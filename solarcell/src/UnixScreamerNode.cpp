/***************************************************************************
                          UnixScreamerNode.cpp  -  description
                             -------------------
    begin                : Sat Jan 4 2003
    copyright            : (C) 2003 by Chris Thomas
    email                : chris_alex_thomas@yahoo.co.uk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "unixscreamernode.h"
#include <sstream>

#include "options.h"

#ifndef _WIN32
	#include <sys/types.h>
	#include <signal.h>
#endif

gboolean	NodeOutput		(GIOChannel *source, GIOCondition condition, gpointer data);
char ** 	BuildArgs			(const char *string,int &numarg);
void			CleanupArgs		(char ***cmd,int &numarg);
char *		WineDirectory	(std::string pathname);

UnixScreamerNode::UnixScreamerNode(int number): ScreamerNode(number)
{

}

UnixScreamerNode::~UnixScreamerNode()
{
	Stop(false);	
}

bool UnixScreamerNode::Init(Scene *scene)
{
	//	Execute the base functionality
	bool ret = ScreamerNode::Init(scene);

	//	Now override the m_scenefile string with a Wine Compatible string
	m_scenefile = WineDirectory(m_scenefile);

	return ret;
}

void UnixScreamerNode::Start(void)
{
	m_jobfile.open(m_job.c_str(),std::ios::out);
	m_jobfile.close();

	m_ackfile.open(m_ack.c_str(),std::ios::out);
	m_ackfile.close();

	char buffer[512];
	sprintf(buffer,"SCREAMERNET %d STARTING\n\n",m_number+1);

  m_outputactive  = false;
  m_output				=	buffer;

	std::stringstream s;

	s << options->WineCmd
		<< " " << WineDirectory(options->ScreamerExecutable)
		<< " -2"
		<< " -c" << WineDirectory(options->ScreamerConfigDir)
		<< " " << WineDirectory(m_job)
		<< " " << WineDirectory(m_ack);

 	int numarg;
  char **cmd;

  cmd = BuildArgs(s.str().c_str(),numarg);

	GError *error = NULL;
	int fd = 0;
	bool ret;


	ret = g_spawn_async_with_pipes(	NULL,
																	cmd,
																	NULL,
																	G_SPAWN_SEARCH_PATH,
																	NULL,
																	NULL,
 																	&m_pid,
																	NULL,
																	&fd,
																	NULL,
																	&error);
	if(ret == true){
		GIOChannel *gio = g_io_channel_unix_new(fd);

		//	For some reason when dealing with stdout, you have to turn the encoding off
		//	and then turn the buffering off, I guess because what comes from stdout is binary
		//	data only and you shouldnt try to interpret it, simply grab it and display
		//	thats if your application is outputing ascii text
    g_io_channel_set_encoding(gio,NULL,&error);
		g_io_channel_set_buffered(gio,false);
				
		g_io_add_watch(gio,G_IO_IN,NodeOutput,this);
	}

  CleanupArgs(&cmd,numarg);
}

void UnixScreamerNode::Stop(bool force)
{
	Quit();

	kill(m_pid,SIGKILL);
}

/**
	The GIOChannel callback on the screamernodes stdout
**/
gboolean NodeOutput(GIOChannel *source, GIOCondition condition, gpointer data)
{
	ScreamerNode *n = (ScreamerNode *)data;

	const int BUFFERLEN = 8192;
	char buffer[BUFFERLEN];
	gsize bytes = 0;
	GIOStatus status = G_IO_STATUS_EOF;

	//	test whether any screamer is selected
 	while(1){
		GError *error = NULL;
  	memset(buffer,0,BUFFERLEN);

		//	read BUFFERLEN number of bytes
		status = g_io_channel_read_chars(source,buffer,BUFFERLEN,&bytes,&error);

		//	the io status was not normal, test if EOF, if anything else, error occured
		if(status == G_IO_STATUS_NORMAL){
			//	pass the data to the screamernode
			n->UpdateOutput(buffer);

      //	You are dealing with stdout here, so there is no EOF, I think this is correct
      //	you read a load of data, if it's more than the amount you can store, you
      //	read again, if you've read less than you can store, then surely you are done
      //	reading the data? that sounds right, whether it **IS** right is another matter
			if(bytes < (signed)BUFFERLEN) return true;
		}else{
			// if you get here, error occured, so return false
			return false;
		}
	}

  return false;
}

//	Tokenises a string and builds it into an array of arguments
char ** BuildArgs(const char *string,int &numarg)
{
	std::vector<char *> tokarray;
	char *temp,*token;

	//	first copy the string to a temp string
	temp = new char[strlen(string)+1];
	strcpy(temp,string);

	//	get the first token
	token = strtok(temp," ");

  //	if the first token is null, there is a serious error
	if(token == NULL) return NULL;

	do{
		//	push back the ptr in the string to the token
		tokarray.push_back(token);

    //	get the next token until there are no more
		token = strtok(NULL," ");
	}while(token != NULL);

	//	now to build the final arg array, make an array the same number of
	//	elements as the vector plus one for the extra null required
	char **cmd = new char*[tokarray.size()+1];
	for(unsigned int a=0;a<tokarray.size();a++){
			//	make a new string and copy it to the final cmd array
			cmd[a] = new char[strlen(tokarray[a])+1];
			strcpy(cmd[a],tokarray[a]);
	}

  //	set the last arg to NULL
	cmd[tokarray.size()] = NULL;

  //	set the number of arguments so you can clean up the memory allocated
	numarg = tokarray.size();

	//	delete the temp strings memory and clear the token array vector
	//	(the memory for each char * in the tokarray is pointing at the
	//		temp string, so if you delete the memory for the temp string,
	//		you in fact also delete the memory for the token array too)
	delete[] temp;
	tokarray.clear();

  //	return this array back to the caller, the cmd array is now complete

	return cmd;
}

//	cleans up any memory allocated for the cmd args
//	array that is sent to g_spawn_async_with_pipes()
void CleanupArgs(char ***cmd,int &numarg)
{
	char **temp = *cmd;

	for(int a=0;a<numarg;a++){
		delete[] temp[a];
	}

	delete[] temp;

	cmd = &temp;
}

//	For converting a unix directory path into a windows path (using the wine's config file)
char * WineDirectory(std::string pathname)
{
  enum{
		FINDSEARCHPATH=0,
		FINDFILE,
		FINDDRIVE,
		FINDPATH,
		COMPAREPATHS,
		FOUNDDRIVE,
		PREPENDDIR,
		CLEANUP
	};

	//	This is a temporary buffer where you store each line of the wine config whilst you process it
	char buffer[4096];

  //	This is the start mode
  int mode = FINDSEARCHPATH;

  //	This is a template for any drive section found in the config file
  char drive[4] = { 'c',':','/','\0' };
  //	This is the path you are searching for a match of (or partial match)
	char	*searchpath = NULL,
				*drivepath = NULL,
				*filename = NULL,
				*outputpath=NULL,
				*prepend=NULL;

  //	This is the exit flag, you turn it on to exit, you leave it off to stay here, quite simply really
	bool exitflag = false;

  //	This is the users personal config drive (should be setup for screamernet)
	std::ifstream config("/home/usr/.wine/config");

  //	If you can't find the config file, return with nothing
	if(config.is_open() == false) return NULL;

  //	Process file until eof or a compatible match was found
	while(1){
		switch(mode){
      case FINDSEARCHPATH:{
				const char *t1,*t2;
				//	the start of the unix directory passed
				t1 = pathname.c_str();
				//	the LAST / in the pathname, anything past this, will be a file
				t2 = strrchr(t1,'/');
				//	the length of the string from the start to the last /
				int len = (int)(t2-t1);

        //	Make a new string and copy the directory you are searching for to it
				searchpath = new char[len+1];
				memset(searchpath,0,len+1);
				strncpy(searchpath,t1,len);

				//	set the mode to search the wine config for the next drive letter
				mode = FINDFILE;
			}break;

			case FINDFILE:{
        //	Find the last / in the pathname, anything AFTER this is the file you want to open
        //	but you want to open using windows drive letters and not the unix file heirarchy
				char *tmp = strrchr(pathname.c_str(),'/');
				filename = new char[strlen(tmp)+1];
				//	Copy the filename
				strcpy(filename,&tmp[1]);

				mode = FINDDRIVE;
			}break;

			case FINDDRIVE:{
				//	Clear the buffer and then fill it with a line from the config file
 				memset(buffer,0,4096);
				config.getline(buffer,4096);

				if(strncmp(buffer,"[Drive",6) == 0){
					//	You've found a drive section, get the drive letter
					drive[0] = buffer[7];

					mode = FINDPATH;
				}
			}break;

			case FINDPATH:{
				//	Clear the buffer and then fill it with a line from the config file
 				memset(buffer,0,4096);
				config.getline(buffer,4096);

				if(strncmp(buffer,"\"Path\"",6) == 0){
					//	the start of the path
					char *tmp = strtok(&buffer[10],"\"");
					drivepath = new char[strlen(tmp)+1];
					strcpy(drivepath,tmp);

					mode = COMPAREPATHS;
				}
			}break;

			case COMPAREPATHS:{
				//	this is complicated now, you have to process each part of the search path
				//	and find the *most* part of it that matches up with a drive letter

				//	To do this, you must make multiple passes through the wine config
				//	you compare the search path against each drive path in the wine config
				//	if something matches, you can leave this and carry on with your merry business
				//	if it doesnt match, then you remove one directory from the end, reset to the beginning
				//	of the wine config and then loop through again, with the revised search path

				//	if nothing matches, then the user hasnt setup their wine config properly, since this
				//	should have been done before
				if(strcmp(searchpath,drivepath) == 0){
    			//	yay, you've found a match, this drive is the one you were looking for
       		mode = FOUNDDRIVE;
				}else{
					//	nope, this doesnt match your search path, check next drive if one exists
					mode = FINDDRIVE;
				}
			}break;

			case FOUNDDRIVE:{
				//	now you've found the correct drive you have to output a new filename
				//	this will leak memory at this point, but I Dont care cause all I want
				//	is for this to work, I'll eliminate all the memory leaks and stuff later
				//	the important thing is you know about them
				outputpath = new char[strlen(drive)+strlen(filename)+1];
				strcpy(outputpath,drive);
				strcat(outputpath,filename);

				delete[] searchpath;
				delete[] drivepath;
				delete[] filename;

				mode = CLEANUP;
			}break;

			case PREPENDDIR:{
				//	you have to reallocate the filename string to include prepend directory before it
				char *tmp = new char[strlen(prepend)+strlen(filename)+strlen("/")+1];

				//	Rebuild the filename
				sprintf(tmp,"%s/%s",prepend,filename);

				//	Delete the old filename memory
				delete[] filename;

        //	Update it's pointer to the new string
				filename = tmp;

				mode = FINDDRIVE;
			}break;

			case CLEANUP:{
				//	This is where you delete any temporary memory you allocated previously
				//	have to inform them that something bad has happened if outputpath is null

				return outputpath;
			}break;
		};

		if(config.eof() != 0){
  		//	seek to the beginning of the wine configuration file
      config.clear();    
      config.seekg(0,std::ios::beg);

     	//	You have to recurse through the search string until you find a match
      //	this means you remove a directory from the search path and add it to the filename
      //	file you want to open:
      //	/home/usr/solarcell/src/commands/ack1
      //	in ~/.wine/config you have drive w: = /home/usr/solarcell/src
      //
      //	Compare /home/usr/solarcell/src/command with /home/usr/solarcell/src	**NO MATCH**
      //	Compare /home/usr/solarcell/src         with /home/usr/solarcell/src	**MATCH FOUND**
      //	Replace /home/usr/solarcell/src with w:
			//	  
      //	outputpath will be w:/commands/ack1
      
			//	also set the search path directory back one directory
     	//	find the last / in the search path
     	char *tmp = strrchr(searchpath,'/');
    	//	set it to null (all string functions will think this is NOW the end of the string)
    	if(tmp != NULL) tmp[0] = '\0';

			prepend = &tmp[1];			     

	    if(strlen(searchpath) == 0){
  	   	//	you've just set the searchpath to null, in other words, the last search path was /
    	  //	therefore there is NOTHING left to search
       	mode = CLEANUP;
			}else{
				mode = PREPENDDIR;
			}
		}
	}
}
