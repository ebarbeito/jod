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

#include "timer.h"

using namespace jod;

unsigned
Timer::milliseconds (void)
{
	return Gosu::milliseconds ();
}

Timer::Timer (unsigned interval)
{
	m_interval = interval;
	start ();
}

Timer::Timer (const Timer &src)
{
	*this = src;
}

Timer::~Timer (void)
{
	// empty
}

Timer &
Timer::operator= (const Timer &src)
{
	if (this != &src)
	{
		m_interval = src.m_interval;
		m_lastTick = src.m_lastTick;
		m_pauseTick = src.m_pauseTick;
		m_running = src.m_running;
		m_startTick = src.m_startTick;
	}
}

unsigned
Timer::getInterval (void) const
{
	return m_interval;
}

void
Timer::setInterval (unsigned interval)
{
	m_interval = interval;
}

unsigned
Timer::elapsed (void)
{
	unsigned tick;

	if (m_running == true)
	{
		m_lastTick = milliseconds ();
		tick = m_lastTick;
	}
	else
		tick = m_pauseTick;

	return (tick - m_startTick);
}

void
Timer::pause (void)
{
	if (m_running == true)
	{
		m_pauseTick = milliseconds ();
		m_running = false;
	}
}

void
Timer::resume (void)
{
	if (m_running == false)
	{
		m_startTick += (milliseconds () - m_pauseTick);
		m_pauseTick = 0;
		m_running = true;
	}
}

bool
Timer::running (void) const
{
	return m_running;
}

void
Timer::start (void)
{
	m_startTick  = m_lastTick = milliseconds ();
	m_pauseTick = 0;
	m_running    = true;
}

bool
Timer::timeUp (void) const
{
	return ((milliseconds () - m_lastTick) >= m_interval);
}

void
Timer::update (void)
{
	if (m_running == true)
		m_lastTick = milliseconds ();
}
