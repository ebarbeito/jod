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

#ifndef _GAMEENGINE_H
#define	_GAMEENGINE_H

#include <Gosu/Gosu.hpp>
#include <stack>
#include <string>
#include "singleton.h"

//! Game name
#define NAME "jump or die"

//! Window widht
#define WIDTH 640

//! Window height
#define HEIGHT 480

//! Fullscreen mode
#define FULLSCREEN false

//! Frames per second
#define FPS 60


typedef Gosu::Image Image;
typedef Gosu::Input Input;
typedef Gosu::Graphics Graphics;

namespace jod
{

enum Key
{
	kbEscape = Gosu::kbEscape,
	kbReturn = Gosu::kbReturn,
	kbP      = Gosu::kbP,
	noButton = Gosu::noButton
};

//! Forward declaration for the abstract State class
class GameState;

/** \brief GameEngine class.
 *
 * Game manager and abstraction layer between libgosu and this game. This class
 * behave as a facade pattern.
 */
class GameEngine : public Gosu::Window, public Singleton< GameEngine >
{
public:
	GameEngine (unsigned width = WIDTH, unsigned height = HEIGHT,
	            bool fullscreen = FULLSCREEN, double fps = FPS,
	            const std::string &title = NAME);

	void cleanup (void);

	void quit (void);

	void update (void);

	void draw (void);

	Key getKey (Gosu::Button btn);

	void buttonDown (Gosu::Button btn);

	void changeState (GameState &state);

	void pushState (GameState &state);

	void popState (void);

	Graphics & graphics (void);
	
	std::wstring getPath (const char *path) const;

private:
	//! Engine status (off|on)
	bool m_running;

	//! Fullscreen mode
	bool m_fullscreen;

	//! Stack of current states
	std::stack< GameState* > m_states;
};

} // namespace jod

#endif	/* _GAMEENGINE_H */
