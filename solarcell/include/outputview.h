#ifndef _OUTPUTVIEW_H_
	#define _OUTPUTVIEW_H_
	
#include "dataview.h"

class ScreamerNode;

class OutputView: public DataView{
protected:
  ScreamerNode	*m_node;
  GtkTextBuffer	*m_textbuffer;

  friend	void	HideOutput(int id);
  virtual	void	ScrollWindow(void);
public:
								OutputView	();
	virtual 			~OutputView	();
  virtual void	Show				(void);
  virtual void  Hide        (void);
	virtual void	Update			(void);
	virtual void	Update			(const char *buffer);

	virtual void	Remove(int,bool){};
	virtual int		Count(void){return 0;};
};

extern OutputView *output_view;

#endif // #ifndef _OUTPUTVIEW_H_
