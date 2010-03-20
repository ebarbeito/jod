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

#ifndef _SPRITE_H
#define	_SPRITE_H

#include <boost/scoped_ptr.hpp>
#include "gameengine.h"
#include "zorder_t.h"

namespace jod
{

class Sprite
{
public:
	Image * getImg (void) const;
	
	int posX (void) const;
	
	int posY (void) const;

	int posZ (void) const;

	void posX (int x) { m_posx = x; }
	void posY (int y) { m_posy = y; }

protected:
	//! Player image
	boost::scoped_ptr< Image > m_img;
	
	//! Sprite x-position in the screen.
	int m_posx;

	//! Sprite y-position in the screen.
	int m_posy;

	//! Sprite z-position (z-order) in the screen.
	zorder_t m_posz;
};

} // namespace jod

#endif	/* _SPRITE_H */
