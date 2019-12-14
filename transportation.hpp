/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class Transportation.
This is the Transportation space in the game.
It's constructor accepts a pointer to a unique menu object for the
Transportation room, allowing the user to interact within the room.

*********************************************************************/

#ifndef TRANSPORTATION_HPP
#define TRANSPORTATION_HPP

#include "module.hpp"
#include "menu.hpp"

class Transportation : public Module
{

private:


public:
    Transportation(RoomMenu * m);  
};




#endif
