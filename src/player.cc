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

#include "player.h"

using namespace jod;

Player::Player (GameEngine &game)
{
	// sprite class attributes
	m_img.reset (new Image (game.graphics (), game.getPath (IMG_PLAYER)));
	m_posx = 180;
	m_posy = 333;
	m_posz = Z_PLAYER;

	// player class attributes
	m_bullets = 0;
	m_lifes = 3;
	m_score = 0;
	m_time = 0;
}
