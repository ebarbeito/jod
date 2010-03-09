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
#include "pausestate.h"

using namespace jod;

void
PauseState::init (GameEngine &game)
{
	bg.reset (new Image (game.graphics (), game.getPath (PAUSESTATE), false));
	std::cout << "PauseState::init()\n";
}

void
PauseState::cleanup (void)
{
	std::cout << "PauseState::cleanup()\n";
}

void
PauseState::update (GameEngine &game)
{
}

void
PauseState::draw (GameEngine &game)
{
	bg->draw (0, 0, 0);
}

void
PauseState::buttonDown (GameEngine &game, Key key)
{
	switch (key)
	{
	case kbP:
		game.popState ();
		break;

	default:
		break;
	}
}
