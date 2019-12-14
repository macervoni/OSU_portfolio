/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class Galley.
This is the Galley space in hte game.
It's constructor accepts a pointer to a unique menu object for the
Galley room, allowing the user to interact within the room.

*********************************************************************/

#ifndef GALLEY_HPP
#define GALLEY_HPP

#include "module.hpp"
#include "menu.hpp"

class Galley : public Module
{

private:

public:
    Galley(RoomMenu * m);  

};




#endif
