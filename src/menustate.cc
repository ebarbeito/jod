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

#include <iostream>
#include "menustate.h"
#include "playstate.h"

using namespace jod;

MenuState::MenuState (void)
{
	// set background up for the play state
	GameEngine &game = GameEngine::instance ();
	m_bg.reset (new Image (game.graphics (), game.getPath (MENUSTATE), false));

	std::cout << "Created singleton instance for MenuState.\n";
}

void
MenuState::init (GameEngine &game)
{
	std::cout << "MenuState::init()\n";
}

void
MenuState::cleanup (void)
{
	std::cout << "MenuState::cleanup()\n";
}

void
MenuState::update (GameEngine &game)
{
}

void
MenuState::draw (GameEngine &game)
{
	m_bg->draw (0, 0, 0);
}

void
MenuState::buttonDown (GameEngine &game, Key key)
{
	switch (key)
	{
	case kbEscape:
		game.quit ();
		break;

	case kbReturn:
		game.changeState (Singleton< PlayState >::instance ());
		break;

	default:
		break;
	}
}
