#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "sceneview.h"
#include "screamerview.h"
#include "outputview.h"
#include "eventview.h"
#include "options.h"

extern	GtkWidget	*MainWindow;
extern	GtkWidget *OptionsWindow;
extern	GtkWidget	*SceneWindow;

GtkFileSelection *FileSelector;
typedef void (*GetFileCallback)(GtkFileSelection *selector,gpointer user_data);

/*****************************************************
	custom callbacks for file dialogs and other things
*****************************************************/

void OpenFileDialog(const char *question,GetFileCallback callback)
{
	FileSelector = (GtkFileSelection *)gtk_file_selection_new(question);

	g_signal_connect(G_OBJECT(FileSelector->ok_button),"clicked",G_CALLBACK(callback),NULL);

	g_signal_connect_swapped(G_OBJECT(FileSelector->ok_button),		"clicked",G_CALLBACK(gtk_widget_destroy),(gpointer)FileSelector);
	g_signal_connect_swapped(G_OBJECT(FileSelector->cancel_button),	"clicked",G_CALLBACK(gtk_widget_destroy),(gpointer)FileSelector);

	gtk_widget_show(GTK_WIDGET(FileSelector));
}

void OpenScene(GtkFileSelection *selector,gpointer user_data)
{
	char *filename = (char *)gtk_file_selection_get_filename(FileSelector);

	scene_view->Add(filename);	
}

void OpenCmdDir(GtkFileSelection *selector, gpointer user_data)
{
	char *filename = (char *)gtk_file_selection_get_filename(FileSelector);

	options->CommandDirectory = filename;

	options->UpdateInterface();
}

void OpenScreamerExec(GtkFileSelection *selector, gpointer user_data)
{
	char *filename = (char *)gtk_file_selection_get_filename(FileSelector);

	options->ScreamerExecutable = filename;
	options->UpdateInterface();	
}

void OpenScreamerConfigDir(GtkFileSelection *selector, gpointer user_data)
{
	char *filename = (char *)gtk_file_selection_get_filename(FileSelector);

	options->ScreamerConfigDir = filename;
	options->UpdateInterface();
}

void OpenSceneList(GtkFileSelection *selector,gpointer user_data)
{
	char *filename = (char *)gtk_file_selection_get_filename(FileSelector);
	
	scene_view->OpenList(filename);
}

void SaveSceneList(GtkFileSelection *selector, gpointer user_data)
{
	char *filename = (char *)gtk_file_selection_get_filename(FileSelector);
	
	scene_view->SaveList(filename);
}

/*********************************************
	GTK+ Callbacks for buttons and menu options
*********************************************/

void
on_MainWindow_destroy_event            (GtkObject       *object,
                                        gpointer         user_data)
{
	options->Update();
	options->Write();

	gtk_main_quit();
}


void
on_options1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	gtk_widget_show(OptionsWindow);
}


void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	on_MainWindow_destroy_event(NULL,NULL);
}


void
on_add1_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	OpenFileDialog("Select a Scene file",OpenScene);
}


void
on_remove1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	scene_view->Remove(false);
}


void
on_revert1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	//	revert this scene to the defaults
	//	this, effectively, will open the scene file again and
	//	overwrite any custom options you may have requested
}


void
on_preferences1_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	//	Open the custom options for the scene
	//	this would allow me to change the render options of a scene
	//	without having to reopen lightwave and change them, quicker this way
	//	to make small adjustments
	
	//	update the window with the first scene selected, any others are ignored, stupid human
	scene_view->UpdateSceneWindow();
	
	//	show the window	
	gtk_widget_show(SceneWindow);
}


void
on_verify1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	//	count all the rendered frames, find which are not present and
	//	ask user if they would like those frames to be rendered again
}


void
on_reset_frame_count1_activate         (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	//	restart rendering of a scene, basically tells SolarCell to start from the beginning
}


void
on_open_scene_list1_activate           (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	//	Opens a saved list of scenes from a file, to continue the renders
	OpenFileDialog("Select a scene list file",OpenSceneList);
}


void
on_save_scene_list1_activate           (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	//	Saves the current list of scenes to a file, with status information
}


void
on_refresh1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	//	refresh the list of currently available screamers
	//	what should I do here? attempt to ping the ip address of the computer?
	//	send a command and wait for a response?
}


void
on_execute1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	screamer_view->Add();
}



void
on_stop1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	screamer_view->Remove(false);
}


void
on_force_stop1_activate                (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	screamer_view->Remove(true);
}


void
on_signal_crashed1_activate            (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

	//	tell SolarCell to treat the screamer as crashed
}


void
on_clear1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	//	clear all the events which occured (problems loading a scene, content dir, etc, etc)
}


void
on_help1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	//	Activate the online help
}

void
on_about1_activate											(GtkMenuItem  	*menuitem,
 																				 gpointer				user_data)
{

}                      


void
on_Options_OK_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	//	update all structures with the new information
	options->Update();
	options->UpdateInterface();

	//	write all the options to solarcell.ini
	options->Write();

	//	Close the options window (hide it really)
	gtk_widget_hide(OptionsWindow);
}


void
on_Options_Cancel_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_widget_hide(OptionsWindow);
}


void
on_Options_Help_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	//	Some some help associated with the options window (better explain each option?)
}

void
on_FindCmdDir_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	OpenFileDialog("Locate Screamer Command Directory",OpenCmdDir);
}


void
on_FindExec_clicked   			           (GtkButton       *button,
                                        gpointer         user_data)
{
	OpenFileDialog("Find Screamer executable to run",OpenScreamerExec);
}


void
on_FindConfig_clicked       			     (GtkButton       *button,
                                        gpointer         user_data)
{
	OpenFileDialog("Find Screamer Configuration Directory",OpenScreamerConfigDir);
}

void
on_Scene_OK_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	//	apply changes
	
	//	close window
	gtk_widget_hide(SceneWindow);
}


void
on_Scene_Cancel_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_widget_hide(SceneWindow);
}


void
on_Scene_Help_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	//	Show some help with the scene window
}


void
on_Main_SceneButton_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	scene_view->Show();
}


void
on_Main_ScreamerButton_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	screamer_view->Show();
}


void
on_Main_OutputButton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	//	When this button is pressed, activate the output page of the notebook
	output_view->Show();

	//	Update the textview with the output buffer of the first selected screamer in the screamerview
	output_view->Update();
}


void
on_Main_EventButton_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	event_view->Show();
}

