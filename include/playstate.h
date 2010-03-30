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

#ifndef _PLAYSTATE_H
#define	_PLAYSTATE_H

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "gamestate.h"
#include "item.h"
#include "level.h"
#include "playstate_t.h"
#include "player.h"

//! x-position limit where items can reach before they are deleted
#define PLAY_LIMIT 52

// TODO: hardcoded value, put it config file
#define PLAYSTATE "data/image/playstate.png"

namespace jod
{

class PlayState : public GameState, public Singleton< PlayState >
{
public:
	PlayState (void);
	
	void init (GameEngine &game);

	void cleanup (void);

	void update (GameEngine &game);

	void draw (GameEngine &game);

	void buttonDown (GameEngine &game, Key key);

private:
	//! Background image.
	boost::scoped_ptr< Image > m_bg;

	//! Dimensional vector for active items.
	std::vector< boost::shared_ptr< Item > > m_items;

	//! Level information currently playing.
	boost::scoped_ptr< Level > m_level;

	//! A single player.
	boost::scoped_ptr< Player > m_player;

	//! Gameplay modality.
	playstate_t m_type;
};

} // namespace jod

#endif	/* _PLAYSTATE_H */
