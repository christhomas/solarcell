#include "scene.h"
#include "options.h"
#include <fstream>

Scene::Scene(int id, char *filename)
{
	m_id				=	id;
	m_filename	=	filename;

	Reset();

	Read();
}

Scene::~Scene()
{

}

void Scene::Reset(void)
{
	m_content		=	"";
	m_start			=	0;
	m_end				=	0;
	m_step			=	0;
	m_numframes	=	0;
	m_nextframe	=	0;
}

void Scene::SetContent(std::string content)
{
	m_content = content;
}

std::string Scene::GetContent(void)
{
	return m_content;
}

std::string Scene::GetFilename(void)
{
	return m_filename;
}

int Scene::GetID(void)
{
	return m_id;
}

int Scene::StartFrame(void)
{
	return m_start;
}

int Scene::EndFrame(void)
{
	return m_end;
}

int Scene::FrameStep(void)
{
	return m_step;
}

void Scene::FrameComplete(void)
{
	m_numframes++;
}

int Scene::NumRenderedFrames(void)
{
	return m_numframes;
}

int Scene::NumFrames(void)
{
	return EndFrame() - m_nextframe;
}

void Scene::RequestBatch(int &start, int &end, int &step)
{
	start = m_nextframe;
	end		=	m_nextframe+options->NumberFrames;
	step	=	m_step;

	m_nextframe = end+1;

	if(start	>=	m_end)	start	=	-1;
	if(end		>		m_end)	end		=	m_end;
}

void Scene::Read(void)
{
	std::ifstream s(m_filename.c_str());
	char buffer[2048];

	while(s.eof() != true){
		memset(buffer,0,2048);

		s.getline(buffer,2048);

		if(strncmp(buffer,"FirstFrame",strlen("FirstFrame")) == 0){
			char *data = strtok(buffer," ");

			m_start			=	atoi(&buffer[strlen(data)+1]);
			m_nextframe	=	m_start;
		}

		if(strncmp(buffer,"LastFrame",strlen("LastFrame")) == 0){
			char *data = strtok(buffer," ");

			m_end = atoi(&buffer[strlen(data)+1]);
		}

		if(strncmp(buffer,"FrameStep",strlen("FrameStep")) == 0){
			char *data = strtok(buffer," ");

			m_step = atoi(&buffer[strlen(data)+1]);
		}
	}
}
