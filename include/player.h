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

#ifndef _PLAYER_H
#define	_PLAYER_H

#include "gameengine.h"
#include "sprite.h"

// TODO: hardcoded value, put it config file
#define IMG_PLAYER "data/image/player.png"

namespace jod
{

class Player : public Sprite
{
public:
	Player (GameEngine &game);

private:
	//! Number of avaiable bullets (arcade gameplay)
	unsigned m_bullets;

	//! Number of lifes (arcade gameplay)
	unsigned m_lifes;

	//! Current score (arcade gameplay)
	unsigned m_score;

	//! Current playing time (classic gameplay)
	unsigned m_time;
};

} // namespace jod

#endif	/* _PLAYER_H */
