#include "eventview.h"
#include "support.h"

extern GtkWidget *MainWindow;

EventView *event_view;

EventView::EventView()
{
	//	Create the list store and make a tree from it
	m_store = gtk_list_store_new(4,	G_TYPE_STRING,
																	G_TYPE_STRING,
																	G_TYPE_STRING,
																	G_TYPE_STRING);

	m_model	=	GTK_TREE_MODEL(m_store);
	
	m_tree = (GtkWidget *)lookup_widget(MainWindow,"EventTreeView");
	
	gtk_tree_view_set_model(GTK_TREE_VIEW(m_tree),m_model);

	AddColumn(COL_TIME,			"Time");
	AddColumn(COL_ORIGIN,		"Origin");
	AddColumn(COL_TYPE,			"Type");
	AddColumn(COL_COMMENT,	"Comment");		

	m_viewid = EVENTS;
}

EventView::~EventView()
{
		
}
