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

#ifndef _ITEM_H
#define	_ITEM_H

#include "item_t.h"
#include "sprite.h"

// TODO: hardcoded values, put it config file
#define BLOCK_SQR_IMG "data/image/square.png"
#define BLOCK_TRI_IMG "data/image/triangle.png"

namespace jod
{

class Item : public Sprite
{
public:
	Item (int x, int y, zorder_t z = Z_BASE, item_t type = NO_ITEM);

	item_t getType (void) const;

private:
	//! Item type that identifies this object.
	item_t m_type;

	std::string * imgType (item_t type) const;
};

} // namespace jod

#endif	/* _ITEM_H */
