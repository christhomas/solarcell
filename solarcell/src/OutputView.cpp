#include "outputview.h"
#include "screamernode.h"
#include "screamerview.h"
#include "support.h"

OutputView *output_view;

extern GtkWidget *MainWindow;

OutputView::OutputView()
{
	m_viewid  = OUTPUT;
  m_node    = NULL;

	GtkTextView *tv = (GtkTextView *)lookup_widget(MainWindow,"OutputTextView");
	m_textbuffer = gtk_text_view_get_buffer(tv);  
}

OutputView::~OutputView()
{
	
}

void OutputView::Show(void)
{
  //  Do the base functionality
  DataView::Show();

  //  Find the first screamer node in the screamer_view display that is selected
  m_node = screamer_view->FirstSelected();
  
  //  tell that node to activate it's update output flag
  if(m_node!=NULL)  m_node->SetOutput(true);
}

void OutputView::Hide(void)
{
  //  Do the base functionality
  DataView::Hide();

  if(m_node!=NULL){
		//  Have to deactivate the nodes update output flags
		m_node->SetOutput(false);

		//  reset this node object so it wont be mistakenly used again
		m_node = NULL;
	}
}

void OutputView::Update(void)
{
  if(m_node!=NULL){
    //	get the entire output buffer for this node
		const char *buffer = m_node->GetOutput();

   	//	clear the textview of current text (it's most likely full of old output from another screamer anyway)
		Update(buffer);
	}
}

/** This will update the textview buffer, but instead of replacing it, will append a buffer to it
 *
 *	@param buffer	The buffer with which to update the textview with
 */
void OutputView::Update(const char *buffer)
{
	//	update the textview with this update
	GtkTextIter		i;
	gtk_text_buffer_get_end_iter(m_textbuffer,&i);
	gtk_text_buffer_insert(m_textbuffer,&i,buffer,strlen(buffer));

	ScrollWindow();
}

void OutputView::ScrollWindow(void)
{
	GtkTextIter i;
	GtkTextView *tv = (GtkTextView *)lookup_widget(MainWindow,"OutputTextView");
	
	gtk_text_buffer_get_end_iter(m_textbuffer,&i);
  gtk_text_view_scroll_to_iter(tv,&i,0,true,1,1);
}

void HideOutput(int id)
{
	//	If you attempt to show another page, you have to notify output_view
	//	that you shouldnt update the textview buffer with any more data
	//	(cause you can't see it anyway)
	if(id!=output_view->m_viewid)	output_view->Hide();
}
