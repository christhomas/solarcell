/***************************************************************************
                          Win32ScreamerNode.cpp  -  description
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
#include "win32screamernode.h"

#ifdef _WIN32

Win32ScreamerNode::Win32ScreamerNode(int number): ScreamerNode(number)
{

}

Win32ScreamerNode::~Win32ScreamerNode()
{
	Stop(false);		
}

Win32ScreamerNode::Start(void)
{
	STARTUPINFO sinfo;

	memset(&sinfo,0,sizeof(STARTUPINFO));
	sinfo.cb					= sizeof(STARTUPINFO);
	sinfo.lpTitle			= "Lightwave Screamernet";
	sinfo.dwFlags			=	STARTF_USESHOWWINDOW;
	sinfo.wShowWindow	=	!options->ScreamerHide;	//	have to use inverse of what the boolean value is because
																							//	win32 is so fucked up, true means false and false means
																							//	true, you can see the lawyers at microsoft do have a
																							//	profound effect on the way they develop software

	std::string lwsn	= options->ScreamerFilename;
	std::string arg		=	" -2 -c\"" + m_config + "\" \"" + m_job + "\" \"" + m_ack + "\"";

	m_jobfile.open(m_job.c_str(),std::ios::out);

	m_jobfile.close();

	m_ackfile.open(m_ack.c_str(),std::ios::out);
	m_ackfile.close();

	//	Create a win32 process,
	//	link it's stdout to the console
	//	request process information(so you have a handle to the process, so you can kill it at will)
	int flags = CREATE_DEFAULT_ERROR_MODE | IDLE_PRIORITY_CLASS;

	CreateProcess((char *)lwsn.c_str(),(char *)arg.c_str(),NULL,NULL,FALSE,flags,NULL,NULL,&sinfo,&pinfo);
}


Win32ScreamerNode::Stop(bool force)
{
	if(force == true){
		TerminateProcess(pinfo.hProcess,0);
	}else{
		Quit();
	}
}

#endif // #ifdef _WIN32
