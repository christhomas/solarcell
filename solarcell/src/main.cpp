/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : Mon Dec 30 21:03:21 GMT 2002
    copyright            : (C) 2002 by Chris Thomas
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

#include "sceneview.h"
#include "eventview.h"
#include "screamerview.h"
#include "outputview.h"
#include "options.h"

GtkWidget	*MainWindow;
GtkWidget	*OptionsWindow;
GtkWidget	*SceneWindow;

int main(int argc, char *argv[])
{
	gtk_init (&argc, &argv);

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  MainWindow = create_MainWindow();
  gtk_widget_show (MainWindow);
  OptionsWindow = create_OptionsWindow();
	SceneWindow = create_SceneWindow();

	//	Read the options from solarcell.ini
	options = new Options();
	options->Read();

	//	Build the three data view objects
	scene_view 		= new SceneView();
	screamer_view = new ScreamerView();
	output_view		=	new OutputView();
	event_view		= new EventView();

	scene_view->Show();

  gtk_main();

  return EXIT_SUCCESS;
}
