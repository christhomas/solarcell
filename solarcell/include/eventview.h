#ifndef _EVENTVIEW_H_
		#define _EVENTVIEW_H_
		
#include "dataview.h"

class EventView: public DataView{
using DataView::Remove;
protected:
	enum{
		COL_TIME=0,
		COL_ORIGIN,
		COL_TYPE,
		COL_COMMENT
	};
	
public:
								EventView		();
	virtual				~EventView	();

	virtual void	Remove(int,bool){};
	virtual int		Count(void){return 0;};		
};

extern EventView *event_view;

#endif // #ifndef _EVENTVIEW_H_
