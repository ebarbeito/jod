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

#ifndef _ITEM_T_H
#define	_ITEM_T_H

namespace jod
{

/** \enum jod::item_t
 * Kind of items that could appear in both gameplay modalities.
 */
enum item_t
{
	NO_ITEM,   //!< Not specified item. Default value for new undefined items.
//	FLOOR_1,   //!< Default, white and thin floor. You can walk on it.
	FLOOR_2,   //!< Harmful, black and deep floor. You can't walk on it.
	BLOCK_SQR, //!< Square block. You can walk on it.
	BLOCK_TRI, //!< Triangular block. You can't touch it.
	BONUS_CIR, //!< Small circle block. Your score increases if you catch it.
	BONUS_SQR, //!< Small square block. Your bullets increases if you catch it.
	BONUS_TRI  //!< Small triangle block. Gravity decrease for a while.
};

} // namespace jod

#endif	/* _ITEM_T_H */
