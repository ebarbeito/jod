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

#include <string>
#include "gameengine.h"
#include "item.h"

using namespace jod;

Item::Item (int x, int y, zorder_t z, item_t type) : Sprite (x, y, z)
{
	GameEngine &engine = GameEngine::instance ();
	std::string *img = imgType (type);
	
	// item class attributes
	m_type = type;

	// sprite class attributes
	m_img.reset (new Image (engine.graphics (), engine.getPath (img->c_str ())));

	// free temp string
	delete img;
}

std::string *
Item::imgType (item_t type) const
{
	std::string *result;

	switch (type)
	{
	case  BLOCK_SQR : result = new std::string (BLOCK_SQR_IMG); break;
	case  BLOCK_TRI : result = new std::string (BLOCK_TRI_IMG); break;
	default         : result = NULL;                            break;
	}

	return result;
}
