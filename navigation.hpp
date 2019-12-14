/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class Navigation.
This is the Navigation space in hte game.
It's constructor accepts a pointer to a unique menu object for the
Navigation room, allowing the user to interact within the room.

*********************************************************************/

#ifndef NAVIGATION_HPP
#define NAVIGATION_HPP

#include "module.hpp"
#include "menu.hpp"

class Navigation : public Module
{

private:


public:
    Navigation(RoomMenu * m);  
};




#endif
