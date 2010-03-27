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

#include "gameengine.h"
#include "player.h"

using namespace jod;

Player::Player (void)
{
	GameEngine &engine = GameEngine::instance ();

	// sprite class attributes
	m_img.reset (new Image (engine.graphics (), engine.getPath (PLAYER_IMG)));
	m_posx = PLAYER_POSX;
	m_posy = PLAYER_POSY;
	m_posz = Z_PLAYER;

	// player class attributes
	m_accel = 10.;
	m_bullets = 0;
	m_jumping = false;
	m_lifes = 3;
	m_score = 0;
	m_timer.setInterval (1000/PLAYER_FPS);
	m_vel = 0.;
}

bool
Player::jumping (void) const
{
	return m_jumping;
}

void
Player::moveUp (void)
{
	// start jumping when it's on the floor
	if (m_jumping == false)
	{
		m_vel = PLAYER_VEL;
		m_jumping = true;
	}
}

void
Player::update (void)
{
	// Move up player when it's jumping
	if (m_jumping == true)
	{
		if (m_timer.timeUp () == true)
		{
			m_angle += 38.57;
			m_vel -= m_accel;
			m_posy -= m_vel;
			m_timer.update ();
		}
	}

	// Check to see if Player has hit floor
	if (m_posy >= PLAYER_POSY)
	{
		m_vel = 0.;
		m_jumping = false;
	}
}
