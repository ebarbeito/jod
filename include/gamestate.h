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

#ifndef _GAMESTATE_H
#define	_GAMESTATE_H

#include "gameengine.h"
#include "singleton.h"

namespace jod
{

class GameState : public Singleton< GameState >
{
public:
	virtual void init (GameEngine &game) = 0;
	virtual void cleanup (void) = 0;

	virtual void update (GameEngine &game) = 0;
	virtual void draw (GameEngine &game) = 0;

	virtual void buttonDown (GameEngine &game, Key key) = 0;
};

} // namespace jod

#endif	/* _GAMESTATE_H */
