#include "options.h"
#include "support.h"

#include <gtk/gtk.h>
#include <fstream>

extern GtkWidget *MainWindow,*OptionsWindow;

Options *options;

Options::Options()
{
	ScreamerName					=	"";
	ScreamerCPUNumbers		=	0;
	NumberFrames					=	0;
	CommandDirectory			=	"";
	ScreamerExecutable		=	"";
	ScreamerConfigDir			=	"";
	ScreamerPriority			=	0;
	FindScreamerInterval	=	5;
	WineCmd								=	"";
}

Options::~Options()
{

}

void Options::Read(void)
{
	unsigned int a;
	bool	begin = false;
	char	buffer[2048];
	
	//	Open solarcell.ini
	std::ifstream config("solarcell.ini");

	//	if doesnt exist, write a new solarcell.ini file 
	//	(need to create one from defaults, or store a copy of the default config within the exe)
	//	leave this for later, assume for now that it exists

	if(config.is_open() == false) return;

	//	read config data
	while(config.eof() == false){
		memset(buffer,0,2048);

		config.getline(buffer,2048);
		
		if(strncmp(buffer,"[Options]",9) == 0 || strncmp(buffer,"[SceneDefault]",14) == 0){
			begin = true;
			continue;
		}

		if(strcmp(buffer,"\0") == 0) continue;

		if(begin == true){

			char *item = strtok(buffer,"=");
			char *data = strtok(&buffer[strlen(item)+1],"\n\0");
			
			//	if there is no string after the "=" the data variable will be NULL, this will crash GTK+
			//	if you attempt to set a NULL string, rather than catch the error like I would
			if(data==NULL) continue;

			//	populate structures with data
			if(strcmp(item,"ScreamerName")					== 0)	ScreamerName					= data;
			if(strcmp(item,"ScreamerCPUNumbers")		== 0)	ScreamerCPUNumbers		= atoi(data);
			if(strcmp(item,"NumberFrames")					== 0)	NumberFrames					=	atoi(data);
			if(strcmp(item,"CommandDirectory")			== 0)	CommandDirectory			=	data;
			if(strcmp(item,"ScreamerExecutable")		== 0)	ScreamerExecutable		=	data;
			if(strcmp(item,"ScreamerConfigDir")			== 0)	ScreamerConfigDir			=	data;
			if(strcmp(item,"ScreamerPriority")			== 0)	ScreamerPriority			=	atoi(data);
			if(strcmp(item,"FindScreamerInterval")	== 0) FindScreamerInterval	=	atoi(data);
			if(strcmp(item,"WineCmd")								== 0)	WineCmd								=	data;
		}	
	}

	for(a=0;a<ScreamerExecutable.length();a++){
		if(ScreamerExecutable[a]	== '\\') ScreamerExecutable[a]	= '/';
	}
	
	for(a=0;a<CommandDirectory.length();a++){
		if(CommandDirectory[a]	== '\\') CommandDirectory[a]	= '/';
	}
	
	for(a=0;a<ScreamerConfigDir.length();a++){
		if(ScreamerConfigDir[a]	== '\\') ScreamerConfigDir[a]		= '/';
	}

	UpdateInterface();
	
	//	close solarcell.ini
	config.close();
}

void Options::Write(void)
{
	//	open solarcell.ini + truncate to zero
	std::ofstream config("solarcell.ini");

	//	write new data
	config << "[Options]"																				<< std::endl;
	config << "ScreamerName="						<< ScreamerName					<< std::endl;
	config << "ScreamerCPUNumbers="			<< ScreamerCPUNumbers		<< std::endl;
	config << "NumberFrames="						<< NumberFrames					<< std::endl;
	config << "CommandDirectory="				<< CommandDirectory			<< std::endl;
	config << "ScreamerExecutable="			<< ScreamerExecutable		<< std::endl;
	config << "ScreamerConfigDir="			<< ScreamerConfigDir		<< std::endl;
	config << "ScreamerPriority="				<< ScreamerPriority			<< std::endl;
	config << "FindScreamerInterval="		<< FindScreamerInterval	<< std::endl;
	config << "WineCmd="								<< WineCmd							<< std::endl;	

	//	close solarcell.ini
	config.close();
}

/*
	Synchronises the options data with what is held in the gui structures 
	(the gui holds the "latest" data, so this is copied into here)

	This should be used when the application wants to store the settings on disk
	i.e save them in the configuration file

	or when the application wants to use the new settings with the screamer system
	since it will not ask the gui for this information, when the gui structures are updated
	(this is the only way the user can alter the configuration, apart from hand editing the configuration file)
	any attempt to run screamer must be done with the new configuration, so when the options are updated and ok'd
	they need to be synchronised with the backend options structures, so screamer can use those changes in the options
*/
void Options::Update(void)
{
#define GET_TEXT(name)		gtk_entry_get_text(GTK_ENTRY(lookup_widget(OptionsWindow,name)))
#define GET_NUM(name)			atoi(gtk_entry_get_text(GTK_ENTRY(lookup_widget(OptionsWindow,name))))
#define GET_SPIN(name)		gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(OptionsWindow,name)))
#define	GET_TOGGLE(name)	gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(lookup_widget(OptionsWindow,name)))
	
	ScreamerName					=	GET_TEXT("ScreamerName");
	ScreamerCPUNumbers		=	GET_NUM("ScreamerCPUNumbers");
	NumberFrames					=	GET_SPIN("NumberFrames");
	CommandDirectory			=	GET_TEXT("CommandDirectory");
	ScreamerExecutable		=	GET_TEXT("ScreamerExecutable");
	ScreamerConfigDir			=	GET_TEXT("ScreamerConfigDir");
	ScreamerPriority			=	GET_SPIN("ScreamerPriority");
	FindScreamerInterval	=	GET_SPIN("ScreamerInterval");
	WineCmd								=	GET_TEXT("WineCmd");
}

void Options::UpdateInterface(void)
{
	char buffer[2048];
	
#define SET_TEXT(name,data) 	gtk_entry_set_text(GTK_ENTRY(lookup_widget(OptionsWindow,name)),data)
#define SET_SPIN(name,data)		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(OptionsWindow,name)),data)
#define SET_TOGGLE(name,data)	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(lookup_widget(OptionsWindow,name)),data)
#define SET_NUM(name,data)		\
	sprintf(buffer,"%d",data);	\
	gtk_entry_set_text(GTK_ENTRY(lookup_widget(OptionsWindow,name)),buffer);
	
	//	Set all the options window interface	
	SET_TEXT("ScreamerName",ScreamerName.c_str());
	SET_NUM("ScreamerCPUNumbers",ScreamerCPUNumbers);
	SET_SPIN("NumberFrames",NumberFrames);	
	SET_TEXT("CommandDirectory",CommandDirectory.c_str());
	SET_TEXT("ScreamerExecutable",ScreamerExecutable.c_str());
	SET_TEXT("ScreamerConfigDir",ScreamerConfigDir.c_str());
	SET_SPIN("ScreamerPriority",ScreamerPriority);
	SET_SPIN("ScreamerInterval",FindScreamerInterval);
	SET_TEXT("WineCmd",WineCmd.c_str());
	
	//	Set all the main window interface
	gtk_label_set_text(GTK_LABEL(lookup_widget(MainWindow,"ScreamerName")),ScreamerName.c_str());
}
