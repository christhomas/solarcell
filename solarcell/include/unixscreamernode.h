/***************************************************************************
                          UnixScreamerNode.h  -  description
                             -------------------
    begin                : Sat Jan 4 2003
    copyright            : (C) 2003 by Chris Thomas
    email                : chris_alex_thomas@yahoo.co.uk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef _UNIXSCREAMERNODE_H_
	#define _UNIXSCREAMERNODE_H_

#include "screamernode.h"

class UnixScreamerNode: public ScreamerNode{
protected:
	int m_pid;
public:
								UnixScreamerNode	(int number);
	virtual 			~UnixScreamerNode	();
	virtual	bool	Init							(Scene *scene);
	virtual void	Start							(void);
	virtual void	Stop							(bool force);
};

#endif // #ifndef _UNIXSCREAMERNODE_H_
