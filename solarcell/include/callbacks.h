#include <gtk/gtk.h>



void
on_MainWindow_destroy_event            (GtkObject       *object,
                                        gpointer         user_data);

void
on_options1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_add1_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_remove1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_revert1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_preferences1_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_verify1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_reset_frame_count1_activate         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_open_scene_list1_activate           (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_save_scene_list1_activate           (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_refresh1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_execute1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_stop1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_force_stop1_activate                (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_signal_crashed1_activate            (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_clear1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_help1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_about1_activate											(GtkMenuItem  	*menuitem,
 																				 gpointer				user_data);                                                                   

void
on_Options_OK_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_Options_Cancel_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Options_Help_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_FindCmdDir_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FindExec_clicked       			       (GtkButton       *button,
                                        gpointer         user_data);

void
on_FindConfig_clicked    							 (GtkButton       *button,
                                        gpointer         user_data);

void
on_Scene_OK_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Scene_Cancel_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_Scene_Help_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FindExec_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_FindConfig_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_Scene_OK_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Scene_Cancel_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_Scene_Help_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_Main_SceneButton_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Main_ScreamerButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_Main_OutputButton_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_Main_EventButton_clicked            (GtkButton       *button,
                                        gpointer         user_data);
