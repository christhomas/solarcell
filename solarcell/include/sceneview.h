#ifndef _SCENEVIEW_H_
		#define _SCENEVIEW_H_
		
#include "dataview.h"

class Scene;
class ScreamerNode;

class SceneView: public DataView{
using DataView::Remove;
protected:
	std::vector<Scene *>	m_scene;
	
	enum{
		COL_PRIORITY=1,
		COL_COPY,
		COL_VERIFY,
		COL_ALLOCATED,
		COL_SCENE,
		COL_DIRECTORY,
		COL_FRAMES,
		COL_LASTFRAME
	};

public:
								SceneView					();
	virtual 			~SceneView				();
	
	virtual void	Add								(char *filename);
	virtual void	Remove						(int id,bool force);		
	virtual	void	Render						(ScreamerNode *node);	
	virtual	void	Update						(int id);
	virtual int		Count							(void);
	
	virtual void	UpdateSceneWindow	(void);
	
	virtual void	OpenList					(char *list);
	virtual void	SaveList					(char *list);
};

extern SceneView *scene_view;

#endif // #ifndef _SCENEVIEW_H_
