#include "screamernode.h"
#include "options.h"
#include "scene.h"

#include "sceneview.h"
#include "screamerview.h"

#include "support.h"

#include <iostream>

extern	GtkWidget			*MainWindow;
extern	SceneView			*scene_view;
extern	ScreamerView	*screamer_view;

const char *AckMsg[6] = {	"Ready",
    			  							"Initializing x86",
		  		  						  "Setting content directory",
	  				  				  	"Loading",
			  			  		  		"Rendering",
				  			    			"Ready"};

ScreamerNode::ScreamerNode(int number)
{
	m_number			  =	number;

	m_state				  =	WAIT;
	m_renderstate   = REQ_BATCH;
	m_waitreply		  =	false;
	
	char buffer[64];
	sprintf(buffer,"%d",number+1);

	m_config			  =	options->ScreamerConfigDir + "LW3.cfg";
	m_job					  =	(options->CommandDirectory + "job") + buffer;
	m_ack					  =	(options->CommandDirectory + "ack") + buffer;

	m_start				  =	0;
	m_end					  =	0;
	m_step				  =	0;

	ClearFrames();

	SetAvailable(false);
}

ScreamerNode::~ScreamerNode()
{

}

void ScreamerNode::SetOutput(bool active)
{
	m_outputactive = active;
}

bool ScreamerNode::Init(Scene *scene)
{
	if(m_state == WAIT){

		m_scene				= scene;

		m_contentdir	= m_scene->GetContent();
		m_scenefile		=	m_scene->GetFilename();

		m_state				= INIT;
		m_renderstate	=	REQ_BATCH;
		m_waitreply		= false;
		return true;
	}


	return false;
}

void ScreamerNode::Quit(void)
{
	m_jobfile.clear();
	m_jobfile.open(m_job.c_str(),std::ios::out);

	m_jobfile << "quit";


	m_jobfile.close();
}

void ScreamerNode::Update(void)
{
	switch(m_state){
		case WAIT:{
			if(m_waitreply == false){
				m_waitreply = true;

				m_jobfile.clear();
				m_jobfile.open(m_job.c_str(),std::ios::out);

				m_jobfile << "wait";

				m_jobfile.close();

				SetAvailable(true);
			}else{
				if(ReadReply(WAIT) == true){
					m_waitreply = false;
				}
			}
		}break;

		case INIT:{
			if(m_waitreply == false){
				m_waitreply = true;

				m_jobfile.clear();
				m_jobfile.open(m_job.c_str(),std::ios::out);

				m_jobfile << "init";

				m_jobfile.close();

				SetAvailable(false);
			}else{
				if(ReadReply(INIT) == true){
					m_waitreply = false;
					m_state			= CONTENT;
				}
			}
		}break;

		case CONTENT:{
			if(m_waitreply == false){
				m_waitreply = true;

				m_jobfile.clear();
				m_jobfile.open(m_job.c_str(),std::ios::out);


				m_jobfile << "content " << m_contentdir << std::endl;

				m_jobfile.close();
			}else{
				if(ReadReply(CONTENT) == true){
					m_waitreply = false;
					m_state			= LOAD;
				}
			}
		}break;

		case LOAD:{
			if(m_waitreply == false){
				m_waitreply = true;

				m_jobfile.clear();
				m_jobfile.open(m_job.c_str(),std::ios::out);

				m_jobfile << "load" << std::endl << m_scenefile;

				m_jobfile.close();
			}else{
				if(ReadReply(LOAD) == true){
					m_waitreply	=	false;

					m_state			=	RENDERWAIT;
				}
			}
		}break;

		case RENDERWAIT:{
			if(m_waitreply == false){
				m_waitreply = true;

				m_jobfile.clear();
				m_jobfile.open(m_job.c_str(),std::ios::out);

				m_jobfile << "wait";

				m_jobfile.close();
			}else{
				if(ReadReply(WAIT) == true){
					switch(m_renderstate){
						case REQ_BATCH:{
							m_scene->RequestBatch(m_start,m_end,m_step);

							m_state				=	RENDER;
							m_renderstate = RENDERING;
	
							SetFrames();

							m_waitreply = false;

							if(m_start == SCENE_COMPLETE){
								SetAvailable(true);

								ClearScene();
								ClearFrames();

								m_state	= WAIT;
							}
						}break;

						case RENDERING:{
							m_scene->FrameComplete();
							scene_view->Update(m_scene->GetID());

							if(m_start >= m_end){
								m_renderstate = REQ_BATCH;
							}else{
								m_waitreply	= false;

								m_state	=	RENDER;

								m_start++;
							}
						}
					};
				}
			}
		}break;

		case RENDERPAUSE:{
			if(m_waitreply == false){
				m_waitreply = true;
			}else{
				m_waitreply = false;
			}
		}break;

		case RENDER:{
			if(m_waitreply == false){
				m_waitreply = true;

				m_jobfile.clear();
				m_jobfile.open(m_job.c_str(),std::ios::out);

				m_jobfile << "render " << m_start << " " << m_start << " " << m_step;

				m_jobfile.close();
			}else{

				if(ReadReply(RENDER) == true){
					m_waitreply	= false;
					m_state			= RENDERWAIT;
				}
			}
		}break;


	};

	screamer_view->Update(m_number);
}

bool ScreamerNode::ReadReply(int msg)
{
  int rem = 256;
 	char *ptr = m_status;

	memset(m_status,0,rem);

	m_ackfile.clear();
	m_ackfile.open(m_ack.c_str(),std::ios::in);
	
	if(m_ackfile.is_open() == true){
		while(m_ackfile.eof() != true){
			m_ackfile.getline(ptr,rem);
			int len = strlen(ptr);
			ptr += len;
			rem -= len;

			char *tmp = strrchr(m_status,'\r');
			if(tmp!=NULL) tmp[0] = ' ';
		}

		m_ackfile.close();
		
		if(strncmp(m_status,AckMsg[msg],strlen(AckMsg[msg])) == 0)	return true;
	}

	return false;
}


void ScreamerNode::SetAvailable(bool avail)
{
	m_avail = avail;
}

bool ScreamerNode::GetAvailable(void)
{
	return m_avail;
}

char * ScreamerNode::GetStatus(void)
{
	return m_status;
}

void ScreamerNode::ClearScene(void)
{
	m_scenefile = "";
}

char * ScreamerNode::GetScene(void)
{
	return (char *)m_scenefile.c_str();
}

void ScreamerNode::SetFrames(void)
{
	sprintf(m_frames,"%d %d %d",m_start,m_end,m_step);
}

void ScreamerNode::ClearFrames(void)
{
	memset(m_frames,0,64);
}

char * ScreamerNode::GetFrames(void)
{
	return m_frames;
}

void ScreamerNode::UpdateOutput(char *buffer)
{
  //  update the output buffer with the new text data
  m_output += buffer;

	//	send any new output to the output_view window if it's active
	if(m_outputactive == true)	output_view->Update(buffer);
}


const char * ScreamerNode::GetOutput(void)
{
	return m_output.c_str();
}

