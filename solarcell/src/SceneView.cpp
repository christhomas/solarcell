#include "sceneview.h"
#include "screamerview.h"
#include "screamernode.h"
#include "scene.h"
#include "support.h"
#include "options.h"

extern GtkWidget	*MainWindow;

SceneView *scene_view;

SceneView::SceneView()
{
	//	Create the list store and make a tree from it
	m_store = gtk_list_store_new(9,	G_TYPE_INT,
																	G_TYPE_INT,
																	G_TYPE_BOOLEAN,
																	G_TYPE_INT,
																	G_TYPE_INT,
																	G_TYPE_STRING,
																	G_TYPE_STRING,
																	G_TYPE_INT,
																	G_TYPE_INT);
	
	m_model	=	GTK_TREE_MODEL(m_store);

	m_tree = (GtkWidget *)lookup_widget(MainWindow,"SceneTreeView");
	
	gtk_tree_view_set_model(GTK_TREE_VIEW(m_tree),m_model);

	gtk_tree_selection_set_mode (gtk_tree_view_get_selection(GTK_TREE_VIEW(m_tree)),
																GTK_SELECTION_MULTIPLE);

	AddColumn(COL_NUMBER,		"Scene ID");
	AddColumn(COL_PRIORITY,	"Priority");
	AddColumn(COL_COPY,			"Copy");
	AddColumn(COL_VERIFY,		"Verify");
	AddColumn(COL_ALLOCATED,"Allocated");
	AddColumn(COL_SCENE,		"Scene");
	AddColumn(COL_DIRECTORY,"Directory");
	AddColumn(COL_FRAMES,		"Frames");
	AddColumn(COL_LASTFRAME,"Number Rendered");
	
	m_viewid = SCENES;
}

SceneView::~SceneView()
{

}

void SceneView::Add(char *filename)
{
	//	When opening a scene, should I copy it to a 
	Scene *s = new Scene(m_scene.size(),filename);
	m_scene.push_back(s);

	GtkTreeIter iter;

	gtk_list_store_append(m_store,&iter);

	gtk_list_store_set(	m_store,
											&iter,
											COL_NUMBER,			Count()-1,
											COL_PRIORITY,		1,
											COL_COPY,				FALSE,
											COL_VERIFY,			1,

											COL_SCENE,			s->GetFilename().c_str(),
											COL_DIRECTORY,	"Unk",
											COL_FRAMES,			s->EndFrame(),
											COL_LASTFRAME,	s->NumRenderedFrames(),
											-1);
	
	screamer_view->Find();
}

void SceneView::Remove(int id,bool force)
{
	Scene *s = m_scene[id];
			
	m_scene.erase(m_scene.begin() + id);
			
	delete s;
}

void SceneView::Render(ScreamerNode *node)
{
	//	search through the scene list, find a scene, tell that screamer to start rendering all the frames from it
	for(unsigned int a=0;a<m_scene.size();a++){
		if(m_scene[a]->NumFrames() > 0){
			node->Init(m_scene[a]);
			return;
		}
	}
}

void SceneView::Update(int id)
{
	Scene *s = m_scene[id];

	//	Update all the scene rows with new information

	GtkTreeIter iter;
	gboolean		valid	=	gtk_tree_model_iter_nth_child(m_model,&iter,NULL,id);

	if(valid == (gboolean)TRUE){
		gtk_list_store_set(	m_store,
												&iter,
												COL_PRIORITY,		1,
												COL_COPY,				FALSE,
												COL_VERIFY,			1,
												COL_SCENE,			s->GetFilename().c_str(),
												COL_DIRECTORY,	"Unk",
												COL_FRAMES,			s->EndFrame(),
												COL_LASTFRAME,	s->NumRenderedFrames(),
												-1);
	}
}


int SceneView::Count(void)
{
	return m_scene.size();
}

void SceneView::UpdateSceneWindow(void)
{
	//	the scene view window holds two objects
	//	1.	the scene object
	//	2.	the scene options object
	
	//	you need to find the first selected scene and that will tell you the scene options object to use
	
	
	//	then you need to tell the scene options object to update the scene window with it's data
}

void SceneView::OpenList(char *list)
{
	//	you need to add all the scenes in this list to the current list
	//	I think it's better than you simply add them to the current list, rather than replace it
	//	I think that would be more used than clearing the current list
	//	I will add an option to the scene menu that allows a clearing of the list
}

void SceneView::SaveList(char *list)
{
	//	in this file you need to store everything which is not part of the scene file itself
	//	that being, 
	//	1.	the scene filename
	//	2.	the frames outstanding
	//	3.	thats all for now
}
