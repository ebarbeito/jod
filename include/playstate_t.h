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

#ifndef _PLAYSTATE_T_H
#define	_PLAYSTATE_T_H

namespace jod
{

/** \enum jod::playstate_t
 * Users can play two different playstate modalities.
 */
enum playstate_t
{
	CLASSIC, //!< classic mode. Near to The Impossible Game gameplay.
	ARCADE   //!< arcade mode. Richer gameplay elements.
};

} // namespace jod

#endif	/* _PLAYSTATE_T_H */
