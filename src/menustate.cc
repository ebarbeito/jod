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

// TODO: hardcoded value, do it well :P
#define MENUSTATE L"/home/neuronal/workspace/netbeans/jod/data/image/tmp_menustate.png"

using namespace jod;

void
MenuState::init (GameEngine &game)
{
	bg.reset (new Image (game.graphics (), MENUSTATE, false));
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
	bg->draw (0, 0, 0);
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
