/***************************************************************************
                          win32screamernode.h  -  description
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
#ifndef _WIN32SCREAMERNODE_H_
	#define _WIN32SCREAMERNODE_H_

#include "screamernode.h"

#ifdef _WIN32
#include <windows.h>

class Win32ScreamerNode: public ScreamerNode{
protected:
		PROCESS_INFORMATION pinfo;
public:
								Win32ScreamerNode		(int number);
	virtual 			~Win32ScreamerNode	();
	virtual void	Start								(void);
	virtual void	Stop								(bool force);
};

#endif // #ifdef _WIN32

#endif // #ifndef _WIN32SCREAMERNODE_H_
