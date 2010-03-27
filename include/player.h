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

#include "sprite.h"
#include "timer.h"

//! Frames per second for player position update
#define PLAYER_FPS 25

// TODO: hardcoded value, put it config file
#define PLAYER_IMG "data/image/player.png"

//! Initial player x-position
#define PLAYER_POSX 180

//! Initial player y-position
#define PLAYER_POSY 333

//! Constant velocity for move upward or downward
#define PLAYER_VEL 40

namespace jod
{

class Player : public Sprite
{
public:
	Player (void);

	bool jumping (void) const;

	void moveUp (void);

	void update (void);

private:
	//! Player acceleration (may change in arcade mode)
	float m_accel;

	//! Number of avaiable bullets (arcade gameplay)
	unsigned m_bullets;

	//! Player is jumping or walking
	bool m_jumping;

	//! Number of lifes (arcade gameplay)
	unsigned m_lifes;

	//! Current score (arcade gameplay)
	unsigned m_score;

	//! Internal clock for Player
	Timer m_timer;

	//! Player velocity upward or downward
	float m_vel;
};

} // namespace jod

#endif	/* _PLAYER_H */
