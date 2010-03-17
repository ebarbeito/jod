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
#include "playstate.h"
#include "menustate.h"
#include "pausestate.h"

using namespace jod;

PlayState::PlayState (void)
{
	// set background up for the play state
	GameEngine &game = GameEngine::instance ();
	m_bg.reset (new Image (game.graphics (), game.getPath (PLAYSTATE), false));

	std::cout << "Created singleton instance for PlayState.\n";
}

void
PlayState::init (GameEngine &game)
{
	m_player.reset (new Player (game));
	m_type = CLASSIC;

	std::cout << "PlayState::init()\n";
}

void
PlayState::cleanup (void)
{
	std::cout << "PlayState::cleanup()\n";
}

void
PlayState::update (GameEngine &game)
{
}

void
PlayState::draw (GameEngine &game)
{
	m_player->getImg ()->draw (0, 0, 1);
	m_bg->draw (0, 0, 0);
}

void
PlayState::buttonDown (GameEngine &game, Key key)
{
	switch (key)
	{
	case kbP:
		game.pushState (Singleton< PauseState >::instance ());
		break;

	case kbEscape:
		game.changeState (Singleton< MenuState >::instance ());
		break;

	default:
		break;
	}
}
