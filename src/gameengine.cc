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

#include "gameengine.h"
#include "gamestate.h"

using namespace jod;

GameEngine::GameEngine (unsigned width, unsigned height,
                        bool fullscreen, double fps, const std::string &title)
	: Window (width, height, fullscreen, 1000./fps)
{
	// how to get std::wstring value from std::string
	std::wstring wtitle (title.length (), L' ');
	std::copy (title.begin (), title.end (), wtitle.begin ());

	Gosu::Window::setCaption (wtitle);
	
	m_fullscreen = false;
	m_running = true;
}

void
GameEngine::cleanup (void)
{
	// cleanup all states
	while (m_states.empty () == false)
	{
		m_states.top ()->cleanup ();
		m_states.pop ();
	}
}

void
GameEngine::quit (void)
{
	m_running = false;
}

void
GameEngine::update (void)
{
	if (m_running == true)
		m_states.top ()->update (*this);
	else
		Gosu::Window::close ();
}

void
GameEngine::buttonDown (Gosu::Button btn)
{
	Key key = getKey (btn);
	m_states.top ()->buttonDown (*this, key);
}

void
GameEngine::draw (void)
{
	m_states.top ()->draw (*this);
}

Key
GameEngine::getKey (Gosu::Button btn)
{
	Key result;

	switch (btn.getId ())
	{
	case Gosu::kbReturn : result = kbReturn; break;
	case Gosu::kbEscape : result = kbEscape; break;
	case Gosu::kbP      : result = kbP;      break;
	default             : result = noButton; break;
	}

	return result;
}

void
GameEngine::changeState (GameState &state)
{
	// cleanup the current state
	if (m_states.empty () == false)
	{
		m_states.top ()->cleanup ();
		m_states.pop ();
	}

	// store and init the new state
	m_states.push (&state);
	m_states.top ()->init (*this);
}

void
GameEngine::pushState (GameState &state)
{
	// store and init the new state
	m_states.push (&state);
	m_states.top ()->init (*this);
}

void
GameEngine::popState (void)
{
	// cleanup the current state
	if (m_states.empty () == false)
	{
		m_states.top ()->cleanup ();
		m_states.pop ();
	}
}

Graphics &
GameEngine::graphics (void)
{
	// get the reference that provides basic drawing functionality
	return Gosu::Window::graphics ();
}