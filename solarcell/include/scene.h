#ifndef _SCENE_H_
	#define _SCENE_H_
	
#include <string>

class Scene{
private:
	int					m_id;
	std::string	m_filename,m_content;

	int					m_start,m_end,m_step;
	int					m_numframes,m_nextframe;
public:	
							Scene							(int id,char *filename);
							~Scene						();
	
	void				Reset							(void);

	void				SetContent				(std::string content);
	std::string	GetContent				(void);

	int					GetID							(void);

	std::string	GetFilename				(void);

	void				RequestBatch			(int &start, int &end, int &step);

	int					StartFrame				(void);
	int					EndFrame					(void);
	int					FrameStep					(void);

	void				FrameComplete			(void);
	int					NumRenderedFrames	(void);
	int					NumFrames					(void);

	void				Read							(void);
};

#endif // #ifndef _SCENE_H_
