/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "include/support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  gtk_object_set_data_full (GTK_OBJECT (component), name, \
    gtk_widget_ref (widget), (GtkDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  gtk_object_set_data (GTK_OBJECT (component), name, widget)

GtkWidget*
create_MainWindow (void)
{
  GtkWidget *MainWindow;
  GtkWidget *vbox1;
  GtkWidget *menubar1;
  GtkWidget *menuitem1;
  GtkWidget *menuitem1_menu;
  GtkWidget *open_scene_list1;
  GtkWidget *image36;
  GtkWidget *save_scene_list1;
  GtkWidget *image37;
  GtkWidget *separatormenuitem1;
  GtkWidget *options1;
  GtkWidget *image38;
  GtkWidget *separator1;
  GtkWidget *quit;
  GtkWidget *menuitem2;
  GtkWidget *menuitem2_menu;
  GtkWidget *add1;
  GtkWidget *remove1;
  GtkWidget *revert1;
  GtkWidget *verify1;
  GtkWidget *reset_frame_count1;
  GtkWidget *preferences1;
  GtkWidget *menuitem3;
  GtkWidget *menuitem3_menu;
  GtkWidget *refresh1;
  GtkWidget *execute1;
  GtkWidget *stop1;
  GtkWidget *separator2;
  GtkWidget *force_stop1;
  GtkWidget *image39;
  GtkWidget *signal_crashed1;
  GtkWidget *image40;
  GtkWidget *events1;
  GtkWidget *events1_menu;
  GtkWidget *clear1;
  GtkWidget *menuitem4;
  GtkWidget *menuitem4_menu;
  GtkWidget *help1;
  GtkWidget *about1;
  GtkWidget *hbox5;
  GtkWidget *hbuttonbox4;
  GtkWidget *Main_SceneButton;
  GtkWidget *Main_ScreamerButton;
  GtkWidget *Main_OutputButton;
  GtkWidget *Main_EventButton;
  GtkWidget *ScreamerName;
  GtkWidget *DataView;
  GtkWidget *scrolledwindow1;
  GtkWidget *SceneTreeView;
  GtkWidget *label1;
  GtkWidget *scrolledwindow2;
  GtkWidget *ScreamerTreeView;
  GtkWidget *label2;
  GtkWidget *scrolledwindow3;
  GtkWidget *OutputTextView;
  GtkWidget *label3;
  GtkWidget *scrolledwindow4;
  GtkWidget *EventTreeView;
  GtkWidget *label4;
  GtkWidget *statusbar1;
  GtkAccelGroup *accel_group;

  accel_group = gtk_accel_group_new ();

  MainWindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (MainWindow), _("SolarCell 0.5"));
  gtk_window_set_default_size (GTK_WINDOW (MainWindow), 800, 400);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (MainWindow), vbox1);

  menubar1 = gtk_menu_bar_new ();
  gtk_widget_show (menubar1);
  gtk_box_pack_start (GTK_BOX (vbox1), menubar1, FALSE, FALSE, 0);

  menuitem1 = gtk_menu_item_new_with_mnemonic (_("Program"));
  gtk_widget_show (menuitem1);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem1);

  menuitem1_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem1), menuitem1_menu);

  open_scene_list1 = gtk_image_menu_item_new_with_mnemonic (_("Open Scene List"));
  gtk_widget_show (open_scene_list1);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), open_scene_list1);

  image36 = gtk_image_new_from_stock ("gtk-open", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image36);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (open_scene_list1), image36);

  save_scene_list1 = gtk_image_menu_item_new_with_mnemonic (_("Save Scene List"));
  gtk_widget_show (save_scene_list1);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), save_scene_list1);

  image37 = gtk_image_new_from_stock ("gtk-save", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image37);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (save_scene_list1), image37);

  separatormenuitem1 = gtk_menu_item_new ();
  gtk_widget_show (separatormenuitem1);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), separatormenuitem1);
  gtk_widget_set_sensitive (separatormenuitem1, FALSE);

  options1 = gtk_image_menu_item_new_with_mnemonic (_("Options"));
  gtk_widget_show (options1);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), options1);

  image38 = gtk_image_new_from_stock ("gtk-preferences", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image38);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (options1), image38);

  separator1 = gtk_menu_item_new ();
  gtk_widget_show (separator1);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), separator1);
  gtk_widget_set_sensitive (separator1, FALSE);

  quit = gtk_image_menu_item_new_from_stock ("gtk-quit", accel_group);
  gtk_widget_show (quit);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), quit);

  menuitem2 = gtk_menu_item_new_with_mnemonic (_("Scenes"));
  gtk_widget_show (menuitem2);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem2);

  menuitem2_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem2), menuitem2_menu);

  add1 = gtk_image_menu_item_new_from_stock ("gtk-add", accel_group);
  gtk_widget_show (add1);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), add1);

  remove1 = gtk_image_menu_item_new_from_stock ("gtk-remove", accel_group);
  gtk_widget_show (remove1);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), remove1);

  revert1 = gtk_image_menu_item_new_from_stock ("gtk-revert-to-saved", accel_group);
  gtk_widget_show (revert1);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), revert1);

  verify1 = gtk_menu_item_new_with_mnemonic (_("Verify"));
  gtk_widget_show (verify1);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), verify1);

  reset_frame_count1 = gtk_menu_item_new_with_mnemonic (_("Reset Frame Count"));
  gtk_widget_show (reset_frame_count1);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), reset_frame_count1);

  preferences1 = gtk_image_menu_item_new_from_stock ("gtk-preferences", accel_group);
  gtk_widget_show (preferences1);
  gtk_container_add (GTK_CONTAINER (menuitem2_menu), preferences1);

  menuitem3 = gtk_menu_item_new_with_mnemonic (_("Screamer"));
  gtk_widget_show (menuitem3);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem3);

  menuitem3_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem3), menuitem3_menu);

  refresh1 = gtk_image_menu_item_new_from_stock ("gtk-refresh", accel_group);
  gtk_widget_show (refresh1);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), refresh1);

  execute1 = gtk_image_menu_item_new_from_stock ("gtk-execute", accel_group);
  gtk_widget_show (execute1);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), execute1);

  stop1 = gtk_image_menu_item_new_from_stock ("gtk-stop", accel_group);
  gtk_widget_show (stop1);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), stop1);

  separator2 = gtk_menu_item_new ();
  gtk_widget_show (separator2);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), separator2);
  gtk_widget_set_sensitive (separator2, FALSE);

  force_stop1 = gtk_image_menu_item_new_with_mnemonic (_("Force Stop"));
  gtk_widget_show (force_stop1);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), force_stop1);

  image39 = gtk_image_new_from_stock ("gtk-stop", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image39);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (force_stop1), image39);

  signal_crashed1 = gtk_image_menu_item_new_with_mnemonic (_("Signal Crashed"));
  gtk_widget_show (signal_crashed1);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), signal_crashed1);

  image40 = gtk_image_new_from_stock ("gtk-dialog-warning", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image40);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (signal_crashed1), image40);

  events1 = gtk_menu_item_new_with_mnemonic (_("Events"));
  gtk_widget_show (events1);
  gtk_container_add (GTK_CONTAINER (menubar1), events1);

  events1_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (events1), events1_menu);

  clear1 = gtk_image_menu_item_new_from_stock ("gtk-clear", accel_group);
  gtk_widget_show (clear1);
  gtk_container_add (GTK_CONTAINER (events1_menu), clear1);

  menuitem4 = gtk_menu_item_new_with_mnemonic (_("_Help"));
  gtk_widget_show (menuitem4);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem4);

  menuitem4_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem4), menuitem4_menu);

  help1 = gtk_image_menu_item_new_from_stock ("gtk-help", accel_group);
  gtk_widget_show (help1);
  gtk_container_add (GTK_CONTAINER (menuitem4_menu), help1);

  about1 = gtk_menu_item_new_with_mnemonic (_("_About"));
  gtk_widget_show (about1);
  gtk_container_add (GTK_CONTAINER (menuitem4_menu), about1);

  hbox5 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox5);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox5, FALSE, FALSE, 0);

  hbuttonbox4 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox4);
  gtk_box_pack_start (GTK_BOX (hbox5), hbuttonbox4, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbuttonbox4), 10);
  gtk_button_box_set_spacing (GTK_BUTTON_BOX (hbuttonbox4), 10);

  Main_SceneButton = gtk_button_new_with_mnemonic (_("Scenes"));
  gtk_widget_show (Main_SceneButton);
  gtk_container_add (GTK_CONTAINER (hbuttonbox4), Main_SceneButton);
  GTK_WIDGET_SET_FLAGS (Main_SceneButton, GTK_CAN_DEFAULT);

  Main_ScreamerButton = gtk_button_new_with_mnemonic (_("Screamers"));
  gtk_widget_show (Main_ScreamerButton);
  gtk_container_add (GTK_CONTAINER (hbuttonbox4), Main_ScreamerButton);
  GTK_WIDGET_SET_FLAGS (Main_ScreamerButton, GTK_CAN_DEFAULT);

  Main_OutputButton = gtk_button_new_with_mnemonic (_("Output"));
  gtk_widget_show (Main_OutputButton);
  gtk_container_add (GTK_CONTAINER (hbuttonbox4), Main_OutputButton);
  GTK_WIDGET_SET_FLAGS (Main_OutputButton, GTK_CAN_DEFAULT);

  Main_EventButton = gtk_button_new_with_mnemonic (_("Events"));
  gtk_widget_show (Main_EventButton);
  gtk_container_add (GTK_CONTAINER (hbuttonbox4), Main_EventButton);
  GTK_WIDGET_SET_FLAGS (Main_EventButton, GTK_CAN_DEFAULT);

  ScreamerName = gtk_label_new (_("ComputerName"));
  gtk_widget_show (ScreamerName);
  gtk_box_pack_end (GTK_BOX (hbox5), ScreamerName, FALSE, FALSE, 10);
  gtk_label_set_justify (GTK_LABEL (ScreamerName), GTK_JUSTIFY_LEFT);

  DataView = gtk_notebook_new ();
  gtk_widget_show (DataView);
  gtk_box_pack_start (GTK_BOX (vbox1), DataView, TRUE, TRUE, 0);
  GTK_WIDGET_UNSET_FLAGS (DataView, GTK_CAN_FOCUS);
  gtk_notebook_set_show_tabs (GTK_NOTEBOOK (DataView), FALSE);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_container_add (GTK_CONTAINER (DataView), scrolledwindow1);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  SceneTreeView = gtk_tree_view_new ();
  gtk_widget_show (SceneTreeView);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), SceneTreeView);

  label1 = gtk_label_new (_("Scenes"));
  gtk_widget_show (label1);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (DataView), gtk_notebook_get_nth_page (GTK_NOTEBOOK (DataView), 0), label1);
  gtk_label_set_justify (GTK_LABEL (label1), GTK_JUSTIFY_LEFT);

  scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow2);
  gtk_container_add (GTK_CONTAINER (DataView), scrolledwindow2);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow2), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  ScreamerTreeView = gtk_tree_view_new ();
  gtk_widget_show (ScreamerTreeView);
  gtk_container_add (GTK_CONTAINER (scrolledwindow2), ScreamerTreeView);

  label2 = gtk_label_new (_("Screamers"));
  gtk_widget_show (label2);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (DataView), gtk_notebook_get_nth_page (GTK_NOTEBOOK (DataView), 1), label2);
  gtk_label_set_justify (GTK_LABEL (label2), GTK_JUSTIFY_LEFT);

  scrolledwindow3 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow3);
  gtk_container_add (GTK_CONTAINER (DataView), scrolledwindow3);
  gtk_notebook_set_tab_label_packing (GTK_NOTEBOOK (DataView), scrolledwindow3,
                                      FALSE, FALSE, GTK_PACK_START);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow3), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  OutputTextView = gtk_text_view_new ();
  gtk_widget_show (OutputTextView);
  gtk_container_add (GTK_CONTAINER (scrolledwindow3), OutputTextView);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (OutputTextView), FALSE);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (OutputTextView), GTK_WRAP_WORD);

  label3 = gtk_label_new (_("Output"));
  gtk_widget_show (label3);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (DataView), gtk_notebook_get_nth_page (GTK_NOTEBOOK (DataView), 2), label3);
  gtk_label_set_justify (GTK_LABEL (label3), GTK_JUSTIFY_LEFT);

  scrolledwindow4 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow4);
  gtk_container_add (GTK_CONTAINER (DataView), scrolledwindow4);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow4), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  EventTreeView = gtk_tree_view_new ();
  gtk_widget_show (EventTreeView);
  gtk_container_add (GTK_CONTAINER (scrolledwindow4), EventTreeView);

  label4 = gtk_label_new (_("Events"));
  gtk_widget_show (label4);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (DataView), gtk_notebook_get_nth_page (GTK_NOTEBOOK (DataView), 3), label4);
  gtk_label_set_justify (GTK_LABEL (label4), GTK_JUSTIFY_LEFT);

  statusbar1 = gtk_statusbar_new ();
  gtk_widget_show (statusbar1);
  gtk_box_pack_end (GTK_BOX (vbox1), statusbar1, FALSE, FALSE, 0);

  gtk_signal_connect (GTK_OBJECT (MainWindow), "destroy",
                      GTK_SIGNAL_FUNC (on_MainWindow_destroy_event),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (open_scene_list1), "activate",
                      GTK_SIGNAL_FUNC (on_open_scene_list1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (save_scene_list1), "activate",
                      GTK_SIGNAL_FUNC (on_save_scene_list1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (options1), "activate",
                      GTK_SIGNAL_FUNC (on_options1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (quit), "activate",
                      GTK_SIGNAL_FUNC (on_quit1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (add1), "activate",
                      GTK_SIGNAL_FUNC (on_add1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (remove1), "activate",
                      GTK_SIGNAL_FUNC (on_remove1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (revert1), "activate",
                      GTK_SIGNAL_FUNC (on_revert1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (verify1), "activate",
                      GTK_SIGNAL_FUNC (on_verify1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (reset_frame_count1), "activate",
                      GTK_SIGNAL_FUNC (on_reset_frame_count1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (preferences1), "activate",
                      GTK_SIGNAL_FUNC (on_preferences1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (refresh1), "activate",
                      GTK_SIGNAL_FUNC (on_refresh1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (execute1), "activate",
                      GTK_SIGNAL_FUNC (on_execute1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (stop1), "activate",
                      GTK_SIGNAL_FUNC (on_stop1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (force_stop1), "activate",
                      GTK_SIGNAL_FUNC (on_force_stop1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (signal_crashed1), "activate",
                      GTK_SIGNAL_FUNC (on_signal_crashed1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (clear1), "activate",
                      GTK_SIGNAL_FUNC (on_clear1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (help1), "activate",
                      GTK_SIGNAL_FUNC (on_help1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (about1), "activate",
                      GTK_SIGNAL_FUNC (on_about1_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (Main_SceneButton), "clicked",
                      GTK_SIGNAL_FUNC (on_Main_SceneButton_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (Main_ScreamerButton), "clicked",
                      GTK_SIGNAL_FUNC (on_Main_ScreamerButton_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (Main_OutputButton), "clicked",
                      GTK_SIGNAL_FUNC (on_Main_OutputButton_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (Main_EventButton), "clicked",
                      GTK_SIGNAL_FUNC (on_Main_EventButton_clicked),
                      NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (MainWindow, MainWindow, "MainWindow");
  GLADE_HOOKUP_OBJECT (MainWindow, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (MainWindow, menubar1, "menubar1");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem1, "menuitem1");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem1_menu, "menuitem1_menu");
  GLADE_HOOKUP_OBJECT (MainWindow, open_scene_list1, "open_scene_list1");
  GLADE_HOOKUP_OBJECT (MainWindow, image36, "image36");
  GLADE_HOOKUP_OBJECT (MainWindow, save_scene_list1, "save_scene_list1");
  GLADE_HOOKUP_OBJECT (MainWindow, image37, "image37");
  GLADE_HOOKUP_OBJECT (MainWindow, separatormenuitem1, "separatormenuitem1");
  GLADE_HOOKUP_OBJECT (MainWindow, options1, "options1");
  GLADE_HOOKUP_OBJECT (MainWindow, image38, "image38");
  GLADE_HOOKUP_OBJECT (MainWindow, separator1, "separator1");
  GLADE_HOOKUP_OBJECT (MainWindow, quit, "quit");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem2, "menuitem2");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem2_menu, "menuitem2_menu");
  GLADE_HOOKUP_OBJECT (MainWindow, add1, "add1");
  GLADE_HOOKUP_OBJECT (MainWindow, remove1, "remove1");
  GLADE_HOOKUP_OBJECT (MainWindow, revert1, "revert1");
  GLADE_HOOKUP_OBJECT (MainWindow, verify1, "verify1");
  GLADE_HOOKUP_OBJECT (MainWindow, reset_frame_count1, "reset_frame_count1");
  GLADE_HOOKUP_OBJECT (MainWindow, preferences1, "preferences1");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem3, "menuitem3");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem3_menu, "menuitem3_menu");
  GLADE_HOOKUP_OBJECT (MainWindow, refresh1, "refresh1");
  GLADE_HOOKUP_OBJECT (MainWindow, execute1, "execute1");
  GLADE_HOOKUP_OBJECT (MainWindow, stop1, "stop1");
  GLADE_HOOKUP_OBJECT (MainWindow, separator2, "separator2");
  GLADE_HOOKUP_OBJECT (MainWindow, force_stop1, "force_stop1");
  GLADE_HOOKUP_OBJECT (MainWindow, image39, "image39");
  GLADE_HOOKUP_OBJECT (MainWindow, signal_crashed1, "signal_crashed1");
  GLADE_HOOKUP_OBJECT (MainWindow, image40, "image40");
  GLADE_HOOKUP_OBJECT (MainWindow, events1, "events1");
  GLADE_HOOKUP_OBJECT (MainWindow, events1_menu, "events1_menu");
  GLADE_HOOKUP_OBJECT (MainWindow, clear1, "clear1");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem4, "menuitem4");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem4_menu, "menuitem4_menu");
  GLADE_HOOKUP_OBJECT (MainWindow, help1, "help1");
  GLADE_HOOKUP_OBJECT (MainWindow, about1, "about1");
  GLADE_HOOKUP_OBJECT (MainWindow, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (MainWindow, hbuttonbox4, "hbuttonbox4");
  GLADE_HOOKUP_OBJECT (MainWindow, Main_SceneButton, "Main_SceneButton");
  GLADE_HOOKUP_OBJECT (MainWindow, Main_ScreamerButton, "Main_ScreamerButton");
  GLADE_HOOKUP_OBJECT (MainWindow, Main_OutputButton, "Main_OutputButton");
  GLADE_HOOKUP_OBJECT (MainWindow, Main_EventButton, "Main_EventButton");
  GLADE_HOOKUP_OBJECT (MainWindow, ScreamerName, "ScreamerName");
  GLADE_HOOKUP_OBJECT (MainWindow, DataView, "DataView");
  GLADE_HOOKUP_OBJECT (MainWindow, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (MainWindow, SceneTreeView, "SceneTreeView");
  GLADE_HOOKUP_OBJECT (MainWindow, label1, "label1");
  GLADE_HOOKUP_OBJECT (MainWindow, scrolledwindow2, "scrolledwindow2");
  GLADE_HOOKUP_OBJECT (MainWindow, ScreamerTreeView, "ScreamerTreeView");
  GLADE_HOOKUP_OBJECT (MainWindow, label2, "label2");
  GLADE_HOOKUP_OBJECT (MainWindow, scrolledwindow3, "scrolledwindow3");
  GLADE_HOOKUP_OBJECT (MainWindow, OutputTextView, "OutputTextView");
  GLADE_HOOKUP_OBJECT (MainWindow, label3, "label3");
  GLADE_HOOKUP_OBJECT (MainWindow, scrolledwindow4, "scrolledwindow4");
  GLADE_HOOKUP_OBJECT (MainWindow, EventTreeView, "EventTreeView");
  GLADE_HOOKUP_OBJECT (MainWindow, label4, "label4");
  GLADE_HOOKUP_OBJECT (MainWindow, statusbar1, "statusbar1");

  gtk_window_add_accel_group (GTK_WINDOW (MainWindow), accel_group);

  return MainWindow;
}

GtkWidget*
create_OptionsWindow (void)
{
  GtkWidget *OptionsWindow;
  GtkWidget *vbox2;
  GtkWidget *notebook2;
  GtkWidget *table1;
  GtkWidget *label8;
  GtkWidget *label9;
  GtkWidget *label10;
  GtkWidget *label11;
  GtkWidget *label12;
  GtkWidget *label13;
  GtkWidget *label14;
  GtkWidget *label15;
  GtkWidget *ScreamerName;
  GtkWidget *ScreamerCPUNumbers;
  GtkObject *NumberFrames_adj;
  GtkWidget *NumberFrames;
  GtkWidget *hbox2;
  GtkWidget *CommandDirectory;
  GtkWidget *FindCmdDir;
  GtkWidget *hbox3;
  GtkWidget *ScreamerExecutable;
  GtkWidget *FindExec;
  GtkWidget *hbox4;
  GtkWidget *ScreamerConfigDir;
  GtkWidget *FindConfig;
  GtkObject *ScreamerPriority_adj;
  GtkWidget *ScreamerPriority;
  GtkObject *ScreamerInterval_adj;
  GtkWidget *ScreamerInterval;
  GtkWidget *label6;
  GtkWidget *table2;
  GtkWidget *WineCmd;
  GtkWidget *label16;
  GtkWidget *label7;
  GtkWidget *hbuttonbox2;
  GtkWidget *Options_OK;
  GtkWidget *Options_Cancel;
  GtkWidget *Options_Help;

  OptionsWindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (OptionsWindow), _("Options"));

  vbox2 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox2);
  gtk_container_add (GTK_CONTAINER (OptionsWindow), vbox2);

  notebook2 = gtk_notebook_new ();
  gtk_widget_show (notebook2);
  gtk_box_pack_start (GTK_BOX (vbox2), notebook2, TRUE, TRUE, 0);

  table1 = gtk_table_new (8, 2, TRUE);
  gtk_widget_show (table1);
  gtk_container_add (GTK_CONTAINER (notebook2), table1);
  gtk_container_set_border_width (GTK_CONTAINER (table1), 10);
  gtk_table_set_row_spacings (GTK_TABLE (table1), 5);
  gtk_table_set_col_spacings (GTK_TABLE (table1), 10);

  label8 = gtk_label_new (_("Screamer Name"));
  gtk_widget_show (label8);
  gtk_table_attach (GTK_TABLE (table1), label8, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_justify (GTK_LABEL (label8), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label8), 0, 0.5);

  label9 = gtk_label_new (_("Screamer Processor Numbers"));
  gtk_widget_show (label9);
  gtk_table_attach (GTK_TABLE (table1), label9, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_justify (GTK_LABEL (label9), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label9), 0, 0.5);

  label10 = gtk_label_new (_("Number of frames sent at a time"));
  gtk_widget_show (label10);
  gtk_table_attach (GTK_TABLE (table1), label10, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_justify (GTK_LABEL (label10), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label10), 0, 0.5);

  label11 = gtk_label_new (_("Commands Directory"));
  gtk_widget_show (label11);
  gtk_table_attach (GTK_TABLE (table1), label11, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_justify (GTK_LABEL (label11), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label11), 0, 0.5);

  label12 = gtk_label_new (_("Screamer Executable"));
  gtk_widget_show (label12);
  gtk_table_attach (GTK_TABLE (table1), label12, 0, 1, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_justify (GTK_LABEL (label12), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label12), 0, 0.5);

  label13 = gtk_label_new (_("Screamer Config Directory"));
  gtk_widget_show (label13);
  gtk_table_attach (GTK_TABLE (table1), label13, 0, 1, 5, 6,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_justify (GTK_LABEL (label13), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label13), 0, 0.5);

  label14 = gtk_label_new (_("Screamer Priority Level"));
  gtk_widget_show (label14);
  gtk_table_attach (GTK_TABLE (table1), label14, 0, 1, 6, 7,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_justify (GTK_LABEL (label14), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label14), 0, 0.5);

  label15 = gtk_label_new (_("Find Screamer Interval"));
  gtk_widget_show (label15);
  gtk_table_attach (GTK_TABLE (table1), label15, 0, 1, 7, 8,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_justify (GTK_LABEL (label15), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label15), 0, 0.5);

  ScreamerName = gtk_entry_new ();
  gtk_widget_show (ScreamerName);
  gtk_table_attach (GTK_TABLE (table1), ScreamerName, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  ScreamerCPUNumbers = gtk_entry_new ();
  gtk_widget_show (ScreamerCPUNumbers);
  gtk_table_attach (GTK_TABLE (table1), ScreamerCPUNumbers, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  NumberFrames_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  NumberFrames = gtk_spin_button_new (GTK_ADJUSTMENT (NumberFrames_adj), 1, 0);
  gtk_widget_show (NumberFrames);
  gtk_table_attach (GTK_TABLE (table1), NumberFrames, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  hbox2 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox2);
  gtk_table_attach (GTK_TABLE (table1), hbox2, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);

  CommandDirectory = gtk_entry_new ();
  gtk_widget_show (CommandDirectory);
  gtk_box_pack_start (GTK_BOX (hbox2), CommandDirectory, TRUE, TRUE, 0);

  FindCmdDir = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_show (FindCmdDir);
  gtk_box_pack_start (GTK_BOX (hbox2), FindCmdDir, FALSE, FALSE, 0);

  hbox3 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox3);
  gtk_table_attach (GTK_TABLE (table1), hbox3, 1, 2, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);

  ScreamerExecutable = gtk_entry_new ();
  gtk_widget_show (ScreamerExecutable);
  gtk_box_pack_start (GTK_BOX (hbox3), ScreamerExecutable, TRUE, TRUE, 0);

  FindExec = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_show (FindExec);
  gtk_box_pack_start (GTK_BOX (hbox3), FindExec, FALSE, FALSE, 0);

  hbox4 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox4);
  gtk_table_attach (GTK_TABLE (table1), hbox4, 1, 2, 5, 6,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);

  ScreamerConfigDir = gtk_entry_new ();
  gtk_widget_show (ScreamerConfigDir);
  gtk_box_pack_start (GTK_BOX (hbox4), ScreamerConfigDir, TRUE, TRUE, 0);

  FindConfig = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_show (FindConfig);
  gtk_box_pack_start (GTK_BOX (hbox4), FindConfig, FALSE, FALSE, 0);

  ScreamerPriority_adj = gtk_adjustment_new (0, -20, 20, 1, 10, 10);
  ScreamerPriority = gtk_spin_button_new (GTK_ADJUSTMENT (ScreamerPriority_adj), 1, 0);
  gtk_widget_show (ScreamerPriority);
  gtk_table_attach (GTK_TABLE (table1), ScreamerPriority, 1, 2, 6, 7,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_spin_button_set_snap_to_ticks (GTK_SPIN_BUTTON (ScreamerPriority), TRUE);

  ScreamerInterval_adj = gtk_adjustment_new (5, 5, 3600, 5, 10, 10);
  ScreamerInterval = gtk_spin_button_new (GTK_ADJUSTMENT (ScreamerInterval_adj), 1, 0);
  gtk_widget_show (ScreamerInterval);
  gtk_table_attach (GTK_TABLE (table1), ScreamerInterval, 1, 2, 7, 8,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_spin_button_set_snap_to_ticks (GTK_SPIN_BUTTON (ScreamerInterval), TRUE);

  label6 = gtk_label_new (_("General"));
  gtk_widget_show (label6);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook2), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook2), 0), label6);
  gtk_label_set_justify (GTK_LABEL (label6), GTK_JUSTIFY_LEFT);

  table2 = gtk_table_new (1, 2, TRUE);
  gtk_widget_show (table2);
  gtk_container_add (GTK_CONTAINER (notebook2), table2);
  gtk_container_set_border_width (GTK_CONTAINER (table2), 10);
  gtk_table_set_row_spacings (GTK_TABLE (table2), 5);
  gtk_table_set_col_spacings (GTK_TABLE (table2), 10);

  WineCmd = gtk_entry_new ();
  gtk_widget_show (WineCmd);
  gtk_table_attach (GTK_TABLE (table2), WineCmd, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  label16 = gtk_label_new (_("Wine Command"));
  gtk_widget_show (label16);
  gtk_table_attach (GTK_TABLE (table2), label16, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_justify (GTK_LABEL (label16), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label16), 0, 0.5);

  label7 = gtk_label_new (_("Unix"));
  gtk_widget_show (label7);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook2), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook2), 1), label7);
  gtk_label_set_justify (GTK_LABEL (label7), GTK_JUSTIFY_LEFT);

  hbuttonbox2 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox2);
  gtk_box_pack_start (GTK_BOX (vbox2), hbuttonbox2, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbuttonbox2), 10);
  gtk_button_box_set_spacing (GTK_BUTTON_BOX (hbuttonbox2), 10);

  Options_OK = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (Options_OK);
  gtk_container_add (GTK_CONTAINER (hbuttonbox2), Options_OK);
  GTK_WIDGET_SET_FLAGS (Options_OK, GTK_CAN_DEFAULT);

  Options_Cancel = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (Options_Cancel);
  gtk_container_add (GTK_CONTAINER (hbuttonbox2), Options_Cancel);
  GTK_WIDGET_SET_FLAGS (Options_Cancel, GTK_CAN_DEFAULT);

  Options_Help = gtk_button_new_from_stock ("gtk-help");
  gtk_widget_show (Options_Help);
  gtk_container_add (GTK_CONTAINER (hbuttonbox2), Options_Help);
  GTK_WIDGET_SET_FLAGS (Options_Help, GTK_CAN_DEFAULT);

  gtk_signal_connect (GTK_OBJECT (FindCmdDir), "clicked",
                      GTK_SIGNAL_FUNC (on_FindCmdDir_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (FindExec), "clicked",
                      GTK_SIGNAL_FUNC (on_FindExec_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (FindConfig), "clicked",
                      GTK_SIGNAL_FUNC (on_FindConfig_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (Options_OK), "clicked",
                      GTK_SIGNAL_FUNC (on_Options_OK_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (Options_Cancel), "clicked",
                      GTK_SIGNAL_FUNC (on_Options_Cancel_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (Options_Help), "clicked",
                      GTK_SIGNAL_FUNC (on_Options_Help_clicked),
                      NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (OptionsWindow, OptionsWindow, "OptionsWindow");
  GLADE_HOOKUP_OBJECT (OptionsWindow, vbox2, "vbox2");
  GLADE_HOOKUP_OBJECT (OptionsWindow, notebook2, "notebook2");
  GLADE_HOOKUP_OBJECT (OptionsWindow, table1, "table1");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label8, "label8");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label9, "label9");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label10, "label10");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label11, "label11");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label12, "label12");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label13, "label13");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label14, "label14");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label15, "label15");
  GLADE_HOOKUP_OBJECT (OptionsWindow, ScreamerName, "ScreamerName");
  GLADE_HOOKUP_OBJECT (OptionsWindow, ScreamerCPUNumbers, "ScreamerCPUNumbers");
  GLADE_HOOKUP_OBJECT (OptionsWindow, NumberFrames, "NumberFrames");
  GLADE_HOOKUP_OBJECT (OptionsWindow, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (OptionsWindow, CommandDirectory, "CommandDirectory");
  GLADE_HOOKUP_OBJECT (OptionsWindow, FindCmdDir, "FindCmdDir");
  GLADE_HOOKUP_OBJECT (OptionsWindow, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (OptionsWindow, ScreamerExecutable, "ScreamerExecutable");
  GLADE_HOOKUP_OBJECT (OptionsWindow, FindExec, "FindExec");
  GLADE_HOOKUP_OBJECT (OptionsWindow, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (OptionsWindow, ScreamerConfigDir, "ScreamerConfigDir");
  GLADE_HOOKUP_OBJECT (OptionsWindow, FindConfig, "FindConfig");
  GLADE_HOOKUP_OBJECT (OptionsWindow, ScreamerPriority, "ScreamerPriority");
  GLADE_HOOKUP_OBJECT (OptionsWindow, ScreamerInterval, "ScreamerInterval");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label6, "label6");
  GLADE_HOOKUP_OBJECT (OptionsWindow, table2, "table2");
  GLADE_HOOKUP_OBJECT (OptionsWindow, WineCmd, "WineCmd");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label16, "label16");
  GLADE_HOOKUP_OBJECT (OptionsWindow, label7, "label7");
  GLADE_HOOKUP_OBJECT (OptionsWindow, hbuttonbox2, "hbuttonbox2");
  GLADE_HOOKUP_OBJECT (OptionsWindow, Options_OK, "Options_OK");
  GLADE_HOOKUP_OBJECT (OptionsWindow, Options_Cancel, "Options_Cancel");
  GLADE_HOOKUP_OBJECT (OptionsWindow, Options_Help, "Options_Help");

  return OptionsWindow;
}

GtkWidget*
create_SceneWindow (void)
{
  GtkWidget *SceneWindow;
  GtkWidget *vbox3;
  GtkWidget *table3;
  GtkWidget *hbuttonbox3;
  GtkWidget *Scene_OK;
  GtkWidget *Scene_Cancel;
  GtkWidget *Scene_Help;

  SceneWindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (SceneWindow), _("Scene Options Window"));

  vbox3 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox3);
  gtk_container_add (GTK_CONTAINER (SceneWindow), vbox3);

  table3 = gtk_table_new (3, 3, FALSE);
  gtk_widget_show (table3);
  gtk_box_pack_start (GTK_BOX (vbox3), table3, FALSE, FALSE, 0);

  hbuttonbox3 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox3);
  gtk_box_pack_start (GTK_BOX (vbox3), hbuttonbox3, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbuttonbox3), 10);
  gtk_button_box_set_spacing (GTK_BUTTON_BOX (hbuttonbox3), 10);

  Scene_OK = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (Scene_OK);
  gtk_container_add (GTK_CONTAINER (hbuttonbox3), Scene_OK);
  GTK_WIDGET_SET_FLAGS (Scene_OK, GTK_CAN_DEFAULT);

  Scene_Cancel = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (Scene_Cancel);
  gtk_container_add (GTK_CONTAINER (hbuttonbox3), Scene_Cancel);
  GTK_WIDGET_SET_FLAGS (Scene_Cancel, GTK_CAN_DEFAULT);

  Scene_Help = gtk_button_new_from_stock ("gtk-help");
  gtk_widget_show (Scene_Help);
  gtk_container_add (GTK_CONTAINER (hbuttonbox3), Scene_Help);
  GTK_WIDGET_SET_FLAGS (Scene_Help, GTK_CAN_DEFAULT);

  gtk_signal_connect (GTK_OBJECT (Scene_OK), "clicked",
                      GTK_SIGNAL_FUNC (on_Scene_OK_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (Scene_Cancel), "clicked",
                      GTK_SIGNAL_FUNC (on_Scene_Cancel_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (Scene_Help), "clicked",
                      GTK_SIGNAL_FUNC (on_Scene_Help_clicked),
                      NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (SceneWindow, SceneWindow, "SceneWindow");
  GLADE_HOOKUP_OBJECT (SceneWindow, vbox3, "vbox3");
  GLADE_HOOKUP_OBJECT (SceneWindow, table3, "table3");
  GLADE_HOOKUP_OBJECT (SceneWindow, hbuttonbox3, "hbuttonbox3");
  GLADE_HOOKUP_OBJECT (SceneWindow, Scene_OK, "Scene_OK");
  GLADE_HOOKUP_OBJECT (SceneWindow, Scene_Cancel, "Scene_Cancel");
  GLADE_HOOKUP_OBJECT (SceneWindow, Scene_Help, "Scene_Help");

  return SceneWindow;
}
