#ifndef _DATAVIEW_H_
		#define _DATAVIEW_H_

#include <gtk/gtk.h>
#include <vector>

class DataView{
protected:
	GtkCellRenderer *m_renderer;
	GtkListStore		*m_store;
	GtkTreeModel		*m_model;
	GtkWidget				*m_tree;
	
	int							m_viewid;

	//	This is for the callback when removing scenes to store what scenes were removed
	//	so they can be removed from the list store later
	std::vector<int> SelectedRows;

	friend void FindSelected(GtkTreeModel *model,GtkTreePath *path,GtkTreeIter *iter, gpointer data);
	
	enum{
		SCENES=0,
		SCREAMER,
		OUTPUT,
		EVENTS
	};

	enum{
		COL_NUMBER=0
	};
	
	virtual	void	AddColumn		(int number, const char *title);	
public:
								DataView		();
	virtual 			~DataView		();
	virtual void	Show				(void);
	virtual void	Hide				(void);
	virtual	void	Remove			(bool force);
	virtual void	Remove			(int id, bool force) = 0;
	virtual	int		Count				(void) = 0;
	virtual void	AdjustRowIDs(int start);	
};

//	The callback for removing scenes properly from the list view
void FindSelected(GtkTreeModel *model,GtkTreePath *path,GtkTreeIter *iter, gpointer data);

#endif // #ifndef _DATAVIEW_H_
