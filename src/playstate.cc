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

//	m_items.push_back (boost::shared_ptr< Item >(new Item (1588, 333, Z_ITEM, BLOCK_TRI)));
//	m_items.push_back (boost::shared_ptr< Item >(new Item (1508, 333, Z_ITEM, BLOCK_TRI)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1428, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1396, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1364, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1332, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1300, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1268, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1236, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1204, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1172, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1140, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1108, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1076, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1044, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item (1012, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item ( 980, 333, Z_ITEM, BLOCK_SQR)));
	m_items.push_back (boost::shared_ptr< Item >(new Item ( 900, 333, Z_ITEM, BLOCK_TRI)));
//	m_items.push_back (boost::shared_ptr< Item >(new Item ( 820, 333, Z_ITEM, BLOCK_TRI)));
//	m_items.push_back (boost::shared_ptr< Item >(new Item ( 740, 333, Z_ITEM, BLOCK_TRI)));
//	m_items.push_back (boost::shared_ptr< Item >(new Item ( 660, 333, Z_ITEM, BLOCK_TRI)));
//	m_items.push_back (boost::shared_ptr< Item >(new Item ( 580, 333, Z_ITEM, BLOCK_TRI)));

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
	bool alive = true;
	
	// player update
	m_player->update ();

	// scene update
	// erase item outside of the active scene area
	if (m_items.size () !=0 && m_items.back ()->getX () <= PLAY_LIMIT)
		m_items.pop_back ();

	// interaction between player and items
	for (std::vector< boost::shared_ptr< Item > >::reverse_iterator it = m_items.rbegin (); alive && it != m_items.rend (); ++it)
	{	
		if ((*it)->collide (*m_player) == true)
		{
			//std::cout << "colliding with item " << i+1 << std::endl;

			switch ((*it)->getType ())
			{
//			case BLOCK_SQR:
//				// check if player is on square block
//				if ((m_player->getY () + m_player->getImg ()->height ()) <= (*it)->getY ())
//					std::cout << "player walking on the block.\n";
//				else
//					alive = false;
//				break;

			case BLOCK_TRI:
			case FLOOR_2:
				alive = false;
				break;

			default:
				break;
			}
		}

		if (alive == true)
			(*it)->setX((*it)->getX () - m_level->getVel ());
	}

	if (alive == false)
	{
		// TODO: temporal
		std::cout << "you loose.\n";
		game.changeState (Singleton< MenuState >::instance ());
	}
}

void
PlayState::draw (GameEngine &game)
{
	// (x,y) rotation center
	double x = m_player->getX () + (m_player->getImg ()->width () / 2);
	double y = m_player->getY () + (m_player->getImg ()->height () / 2);

	m_player->getImg ()->drawRot (x, y, m_player->getZ (), m_player->getAngle ());
	//m_player->getImg ()->draw (m_player->getX (), m_player->getY (), m_player->getZ ());

	for (std::vector< boost::shared_ptr< Item > >::reverse_iterator it = m_items.rbegin (); it != m_items.rend (); ++it)
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
