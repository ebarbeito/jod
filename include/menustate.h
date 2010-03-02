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

#ifndef _MENUSTATE_H
#define	_MENUSTATE_H

#include <boost/scoped_ptr.hpp>
#include "gamestate.h"

namespace jod
{

class MenuState : public GameState, public Singleton< MenuState >
{
public:
	void init (GameEngine &game);
	void cleanup (void);

	void update (GameEngine &game);
	void draw (GameEngine &game);

	void buttonDown (GameEngine &game, Key key);

private:
	//! Background image
	boost::scoped_ptr< Image > bg;
};

} // namespace jod

#endif	/* _MENUSTATE_H */
