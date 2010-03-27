// -*- C++ -*-

/* jump or die: yet another 2d platform game
 * Copyright (C) 2010 - Enrique Barbeito García
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program;  if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave., Cambridge, MA 02139, USA.
 */

#ifndef _TIMER_H
#define	_TIMER_H

#include <Gosu/Timing.hpp>

namespace jod
{

class Timer
{
public:
	/**
	 * Static method that returns the amount of ms. since game started.
	 * @return Total ms. from the beginning.
	 */
	static unsigned milliseconds ();

public:
	/**
	 * Default constructor. You can define your own interval or not.
	 * @param interval Interval value in milliseconds. It's optional.
	 */
	Timer (unsigned interval = 0);

	Timer (const Timer &src);
	
	~Timer (void);

	Timer & operator= (const Timer &src);

	unsigned getInterval (void) const;

	void setInterval (unsigned interval);

	unsigned elapsed (void);

	void pause (void);
	
	void resume (void);

	bool running (void) const;
	
	void start (void);

	bool timeUp (void) const;

	void update (void);

private:
	//! Attribute for managing time intervals
	unsigned m_interval;
	
	//! Timer starts at this initial tick
	unsigned m_startTick;

	//! Last tick saved
	unsigned m_lastTick;

	//! Tick saved when timer got paused
	unsigned m_pauseTick;

	//! Timer could be working or not
	bool m_running;
};

} // namespace jod

#endif	/* _TIMER_H */
