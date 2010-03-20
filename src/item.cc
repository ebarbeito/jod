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

#include "item.h"

using namespace jod;

Item::Item (GameEngine &game, item_t type)
{
	// sprite class attributes
	m_img.reset (new Image (game.graphics (), game.getPath (IMG_SQRBLOCK)));
	m_posx = 600;
	m_posy = 333;
	m_posz = Z_ITEM;

	// item class attributes
	m_type = type;
}

void
Item::setType (int type)
{
	switch (type)
	{
	case  1 : m_type = FLOOR_1;   break;
	case  2 : m_type = FLOOR_2;   break;
	case  3 : m_type = BLOCK_SQR; break;
	case  4 : m_type = BLOCK_TRI; break;
	case  5 : m_type = BONUS_CIR; break;
	case  6 : m_type = BONUS_SQR; break;
	case  7 : m_type = BONUS_TRI; break;
	default : m_type = NO_ITEM;   break;
	}
}
