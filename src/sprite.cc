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

#include "sprite.h"

using namespace jod;

Sprite::Sprite (int x, int y, int z)
{
	m_posx = x;
	m_posy = y;
	setZ (z);
}

Image *
Sprite::getImg (void) const
{
	return m_img.get ();
}

int
Sprite::getX (void) const
{
	return m_posx;
}

int
Sprite::getY (void) const
{
	return m_posy;
}

int
Sprite::getZ (void) const
{
	return static_cast< int >(m_posz);
}

void
Sprite::setX (int x)
{
	m_posx = x;
}

void
Sprite::setY (int y)
{
	m_posy = y;
}

void
Sprite::setZ (int z)
{
	switch (z)
	{
	case  1 : m_posz = Z_PLAYER;  break;
	case  2 : m_posz = Z_ITEM;    break;
	case  3 : m_posz = Z_HUD;     break;
	default : m_posz = Z_BASE;    break;
	}
}

bool
Sprite::collide (Sprite &obj)
{
	// check possible intersection between two boxes
	return ( (m_posx < obj.m_posx + obj.m_img->width ()) && (obj.m_posx < m_posx + m_img->width ()) &&
	         (m_posy < obj.m_posy + obj.m_img->height ()) && (m_posy < obj.m_posy + m_img->height ()) );
}
