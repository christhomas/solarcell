#include "screamerview.h"
#include "sceneview.h"
#include "support.h"
#include "options.h"

#ifdef _WIN32
	#include "win32screamernode.h"
#else
	#include "unixscreamernode.h"
#endif

extern GtkWidget	*MainWindow;

ScreamerView *screamer_view;

const int MONITOR_TIMEOUT	=	1000;

ScreamerView::ScreamerView()
{
	//	Create the list store and make a tree from it
	m_store = gtk_list_store_new(8,	G_TYPE_INT,
																	G_TYPE_BOOLEAN,
																	G_TYPE_STRING,
																	G_TYPE_INT,
																	G_TYPE_STRING,
																	G_TYPE_STRING,
																	G_TYPE_STRING,
																	G_TYPE_STRING);

	m_model	= GTK_TREE_MODEL(m_store);

	m_tree = (GtkWidget *)lookup_widget(MainWindow,"ScreamerTreeView");
	
	gtk_tree_view_set_model(GTK_TREE_VIEW(m_tree),m_model);

	gtk_tree_selection_set_mode (gtk_tree_view_get_selection(GTK_TREE_VIEW(m_tree)),
																GTK_SELECTION_MULTIPLE);

	AddColumn(COL_NUMBER,			"Screamer ID");
	AddColumn(COL_AVAILABLE,	"Available");
	AddColumn(COL_CPU,				"CPU");
	AddColumn(COL_MEMORY,			"Memory");
	AddColumn(COL_NAME,				"Name");
	AddColumn(COL_STATUS,			"Status");
	AddColumn(COL_SCENE,			"Scene");
	AddColumn(COL_FRAMES,			"Frames");

	//	Set the name of this view
	m_viewid = SCREAMER;
	
	//	start the screamer callback
	g_timeout_add(options->FindScreamerInterval*1000,::FindScreamer,NULL);
}

ScreamerView::~ScreamerView()
{
		
}

void ScreamerView::Add(void)
{
	//	if the number of screamer is zero, and your adding one, this is the first
	//	so you need to (re)start the screamer monitor, otherwise you wont render much
	if(Count() == 0)	g_timeout_add(MONITOR_TIMEOUT,MonitorScreamer,this);

#ifdef _WIN32
	ScreamerNode *n = new Win32ScreamerNode(m_node.size());
#else
	ScreamerNode *n = new UnixScreamerNode(m_node.size());
#endif
	
	n->Start();
	n->Update();

	m_node.push_back(n);

	GtkTreeIter iter;

	gtk_list_store_append(m_store,&iter);

	gtk_list_store_set(	m_store,
											&iter,
											COL_NUMBER,			Count()-1,
											COL_AVAILABLE,	n->GetAvailable(),
											COL_CPU,				"x86",
											COL_MEMORY,			-1,
											COL_NAME,				options->ScreamerName.c_str(),
											COL_STATUS,			n->GetStatus(),
											COL_SCENE,			n->GetScene(),
											COL_FRAMES,			n->GetFrames(),
											-1);
}

void ScreamerView::Remove(int id,bool force)
{
	ScreamerNode *n = m_node[id];
			
	m_node.erase(m_node.begin() + id);
			
	delete n;
}

void ScreamerView::Find(void)
{
	//	Scan for a free cpu
	//	if one is found, send this information through to the scene_view, where a scene or frame range can be found to render

	GtkTreeIter		iter;
	int						id					=	0;
	gboolean			valid				=	gtk_tree_model_get_iter_first(m_model,&iter);
	bool					comp_avail	= false;

	while(valid){
		gtk_tree_model_get(m_model,&iter,COL_AVAILABLE,&comp_avail,-1);

		valid = gtk_tree_model_iter_next(m_model,&iter);

		if(comp_avail == true){
			scene_view->Render(m_node[id]);
			return;
		}
		
		id++;
	}
}

void ScreamerView::Update(int id)
{
	GtkTreeIter iter;
	gboolean		valid	=	gtk_tree_model_iter_nth_child(m_model,&iter,NULL,id);

	if(valid == (gboolean)TRUE){
		gtk_list_store_set(	m_store,
												&iter,
												COL_AVAILABLE,	m_node[id]->GetAvailable(),
												COL_CPU,				"x86",
												COL_MEMORY,			-1,
												COL_NAME,				options->ScreamerName.c_str(),
												COL_STATUS,			m_node[id]->GetStatus(),
												COL_SCENE,			m_node[id]->GetScene(),
												COL_FRAMES,			m_node[id]->GetFrames(),
												-1);
	}
}

int ScreamerView::Count(void)
{
	return m_node.size();
}

ScreamerNode * ScreamerView::FirstSelected(void)
{
	//	Get a list of selected scenes
	GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(m_tree));
	gtk_tree_selection_selected_foreach(selection,FindSelected,this);

	ScreamerNode *n = NULL;

	if(SelectedRows.size() > 0)	n = m_node[SelectedRows[0]];

	SelectedRows.clear();	
	
	return n;
}

/*
	Screamer callbacks
*/

/**
 *	Find a screamer, which happens periodically, it'll search for a free cpu
 *	if one is found, that screamer will attempt to find a scene to render
 *	if nothing is available, then it'll simple wait it's turn until next time
 */
gboolean FindScreamer(gpointer data)
{
	screamer_view->Find();

	return true;
}

/**
 *	Monitor the screamers progress, this must happen reasonably quickly and
 *	is not related to finding a screamer, this basically updates the screamer process
 *	and the reflected information held in the interface
 */
gboolean MonitorScreamer(gpointer data)
{
	int numscreamer = screamer_view->Count();

	if(numscreamer > 0){

		for(int a=0;a<numscreamer;a++){
			screamer_view->m_node[a]->Update();
		}

		return true;
	}
	
	return false;
}

