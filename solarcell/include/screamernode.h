#ifndef _SCREAMERNODE_H_
	#define _SCREAMERNODE_H_
	
#include <fstream>
#include <string>

#include "outputview.h"

class Scene;

class ScreamerNode{
protected:
  bool					m_outputactive;
	std::string   m_output;  
	
	int						m_number;
	std::string		m_config,m_job,m_ack;
	std::fstream	m_jobfile,m_ackfile;

	int						m_state;

	std::string		m_contentdir,m_scenefile;

	char					m_frames[64];

	char					m_status[256];

	int						m_start, m_end, m_step;

	bool					m_waitreply;

	bool					m_avail;

	Scene					*m_scene;

	int						m_renderstate;

	enum{	WAIT=0,INIT,CONTENT,LOAD,RENDER,RENDERWAIT,RENDERPAUSE,QUIT };
	enum{	SCENE_COMPLETE=-1,REQ_BATCH,RENDERING };

	virtual	void					SetAvailable	(bool avail);
	virtual	void					ClearScene		(void);
	virtual	void					SetFrames			(void);
	virtual	void					ClearFrames		(void);
	virtual	bool					ReadReply			(int msg);
	
	friend class OutputView;
	
	virtual	void					SetOutput			(bool active);
	virtual	const char *	GetOutput			(void);

public:
									ScreamerNode	(int number);
	virtual					~ScreamerNode	();

	virtual void		Start					(void) 				= 0;
	virtual void		Stop					(bool force)	= 0;
	
	virtual	bool		Init					(Scene *scene);
	virtual	void		Quit					(void);
	
	virtual	bool		GetAvailable	(void);
	virtual	char *	GetStatus			(void);
	virtual	char *	GetScene			(void);
	
	virtual	char *	GetFrames			(void);

	virtual	void		Update				(void);

	virtual	void		UpdateOutput	(char *buffer);
};

#endif // #ifndef _SCREAMERNODE_H_
