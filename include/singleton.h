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

#ifndef _SINGLETON_H
#define	_SINGLETON_H

namespace jod
{

/** \brief Singleton template pattern.
 *
 * Allows to turn any new or existing class T into Singleton Pattern. It is
 * accomplished by deriving class T from class Singleton.
 *
 * It is assumed that Singleton objects are long-lived. Often they exist for the
 * life of the program. You delete them not so much to reclaim space but to shut
 * down in the orderly manner (such as return whatever  resources derived class
 * holds in its ownership back to the system). C++ deletes static objects
 * automatically. Although, it doesn't guarantee the calling order. In other
 * words, destructors of Singleton class are not order-dependent.
 *
 * To force destruction order, Singleton class transfers ownership of object T
 * to Destroyer class. When the program exits, the Destroyer will be destroyed,
 * and the object T along with it. Singleton destructor is now implicit.
 */
template <class T>
class Singleton
{
public:
	//! Return an instance of templated class
	static T& instance (void)
	{
		// The only instance
		// Guaranteed to be lazy initialized
		// Guaranteed that it will be destroyed correctly
		static T obj;
		return obj;
	}

protected:
	//! Protected Constructor
	Singleton (void) {}
	Singleton (const Singleton &src) {}
	virtual ~Singleton (void) {}
	Singleton & operator= (const Singleton &src) {}
};

} // namespace jod

#endif	/* _SINGLETON_H */
