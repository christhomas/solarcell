#ifndef _SCREAMERVIEW_H_
		#define _SCREAMERVIEW_H_
		
#include "dataview.h"

class ScreamerNode;

class ScreamerView: public DataView{
using DataView::Remove;
protected:
	std::vector<ScreamerNode *>	m_node;
	
	enum{
		COL_AVAILABLE=1,
		COL_CPU,
		COL_MEMORY,
		COL_NAME,
		COL_STATUS,
		COL_SCENE,
		COL_FRAMES
	};
	
	friend gboolean MonitorScreamer(gpointer data);
	
public:
													ScreamerView	();
	virtual 								~ScreamerView	();
	virtual	void						Add						(void);	
	virtual void						Remove				(int id,bool force);
	virtual	void						Find					(void);
	virtual	void						Update				(int id);
	virtual	int							Count					(void);	
  virtual ScreamerNode *  FirstSelected	(void);
};

extern ScreamerView *screamer_view;

gboolean FindScreamer			(gpointer data);
gboolean MonitorScreamer	(gpointer data);

#endif // #ifndef _SCREAMERVIEW_H_
