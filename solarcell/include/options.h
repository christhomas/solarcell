#ifndef _OPTIONS_H_
	#define _OPTIONS_H_
	
#include <string>

class Options{
public:
	std::string ScreamerName;
	int					ScreamerCPUNumbers;
	int					NumberFrames;
	std::string CommandDirectory;
	std::string ScreamerExecutable;
	std::string ScreamerConfigDir;
	int					ScreamerPriority;
	int					FindScreamerInterval;
	std::string	WineCmd;

				Options					();
				~Options				();

	void	Read						(void);
	void	Write						(void);
	void	Update					(void);
	void	UpdateInterface	(void);
};

extern Options *options;

#endif // #ifndef _OPTIONS_H_
