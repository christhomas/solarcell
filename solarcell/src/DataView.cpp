#include "dataview.h"
#include "support.h"

//  This is here especially cause you need to be able to enable/disable this from here
void HideOutput(int id);

extern GtkWidget *MainWindow;

DataView::DataView()
{
	m_renderer = gtk_cell_renderer_text_new();
}

DataView::~DataView()
{
		
}

void DataView::AddColumn(int number, const char *title)
{
	GtkTreeViewColumn *column;

	column = gtk_tree_view_column_new_with_attributes(title,m_renderer,"text",number,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(m_tree),column);

	gtk_tree_view_column_set_clickable (GTK_TREE_VIEW_COLUMN (column), TRUE);
}


void DataView::Show(void)
{
	//	Acquire a pointer to the data view notebook
	GtkWidget *nb = (GtkWidget *)lookup_widget(MainWindow,"DataView");
	
	//	Tell the notebook to display the correct tab
	gtk_notebook_set_current_page(GTK_NOTEBOOK(nb),m_viewid);
	
  //  Attempt to hide the output page
  HideOutput(m_viewid);
}

void DataView::Hide(void)
{
	//	by default, do nothing
}

void DataView::Remove(bool force)
{
	//	Get a list of selected scenes
	GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(m_tree));
	gtk_tree_selection_selected_foreach(selection,FindSelected,this);

	// go through the Remove list and remove all the rows which were selected for removal
	for(unsigned int a=0;a<SelectedRows.size();a++){
		GtkTreeIter iter;

		gboolean valid = gtk_tree_model_iter_nth_child(m_model,&iter,NULL,SelectedRows[a]);

		if(valid == true)	gtk_list_store_remove(m_store,&iter);

		Remove(a,force);
		AdjustRowIDs(a);
	}

	//	clear the list
	SelectedRows.clear();
}

void DataView::AdjustRowIDs(int start)
{
	//	Now you've removed the scene, you have to adjust the row numbers so there are no gaps
	//	you removed row num or array element [num-1] so now you have to loop through
	//	all the remaining rows, and subtract 1 from their row number
	GtkTreeIter i;
	for(int a=start;a<=Count();a++){
		gtk_tree_model_iter_nth_child(m_model,&i,NULL,a);
		gtk_list_store_set(m_store,&i,COL_NUMBER,a,-1);
	}
}

//	This is so a TreeView object can make a list of all the selected rows
void FindSelected(GtkTreeModel *model, GtkTreePath *path, GtkTreeIter *iter, gpointer data)
{
	DataView *dv = (DataView *)data;
	int num;

	gtk_tree_model_get(model,iter,0,&num,-1);

	dv->SelectedRows.push_back(num);
}
