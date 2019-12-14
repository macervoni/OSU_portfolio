
/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class Equipment.
This is the Equipment space in hte game.
It's constructor accepts a pointer to a unique menu object for the 
Equipment room, allowing the user to interact within the room.

*********************************************************************/

#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include "module.hpp"
#include "menu.hpp"

class Equipment : public Module
{

private:


public:
    Equipment(RoomMenu * m);  

};




#endif
