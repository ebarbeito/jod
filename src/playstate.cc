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
#include <vector>
#include "item_t.h"
#include "menustate.h"
#include "pausestate.h"
#include "playstate.h"
#include "level.h"

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
	// reset active items and player state
	m_items.clear ();
	m_player.reset (new Player);

	// TODO: temporal stuff
	m_level.reset (new Level);

	m_items.push_back (boost::shared_ptr< Item >(new Item ( 580, 333, Z_ITEM, BLOCK_TRI)));
	m_items.push_back (boost::shared_ptr< Item >(new Item ( 660, 333, Z_ITEM, BLOCK_TRI)));
	m_items.push_back (boost::shared_ptr< Item >(new Item ( 740, 333, Z_ITEM, BLOCK_TRI)));
	m_items.push_back (boost::shared_ptr< Item >(new Item ( 820, 333, Z_ITEM, BLOCK_TRI)));
	m_items.push_back (boost::shared_ptr< Item >(new Item ( 900, 333, Z_ITEM, BLOCK_TRI)));
	m_items.push_back (boost::shared_ptr< Item >(new Item ( 980, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1012, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1044, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1076, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1108, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1140, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1172, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1204, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1236, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1268, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1300, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1332, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1364, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1396, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1428, 300, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1508, 333, Z_ITEM, BLOCK_TRI)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1588, 333, Z_ITEM, BLOCK_TRI)));
	
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
	// TODO: temporal stuff
	for (int i = 0; i < m_items.size (); ++i)
	{
		m_items.at (i)->setX(m_items.at (i)->getX () - m_level->getVel ());

		if (m_items.at(i)->collide (*m_player) == true)
			std::cout << "colliding with item " << i+1 << std::endl;
	}

	m_player->update ();
}

void
PlayState::draw (GameEngine &game)
{
	// (x,y) rotation center
	double x = m_player->getX () + (m_player->getImg ()->width () / 2);
	double y = m_player->getY () + (m_player->getImg ()->height () / 2);

	m_player->getImg ()->drawRot (x, y, m_player->getZ (), m_player->getAngle ());
	//m_player->getImg ()->draw (m_player->getX (), m_player->getY (), m_player->getZ ());

	for (std::vector< boost::shared_ptr< Item > >::const_iterator it = m_items.begin (); it != m_items.end (); ++it)
		(*it)->getImg ()->draw ((*it)->getX (), (*it)->getY (), (*it)->getZ ());

	m_bg->draw (0, 0, Z_BASE);
}

void
PlayState::buttonDown (GameEngine &game, Key key)
{
	switch (key)
	{
	// when player must jump
	case kbS:
		m_player->moveUp ();
		break;

	// when user wants to pause gameplay
	case kbP:
		game.pushState (Singleton< PauseState >::instance ());
		break;

	// when user wants to exit gameplay / return to menu
	case kbEscape:
		game.changeState (Singleton< MenuState >::instance ());
		break;

	default:
		break;
	}
}
