/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class Escape Pod.
This is the Escape Pod space in hte game.
It's constructor accepts a pointer to a unique menu object for the
Escape Pod room, allowing the user to interact within the room.

*********************************************************************/

#ifndef ESCAPE_POD_HPP
#define ESCAPE_POD_HPP

#include "module.hpp"
#include "menu.hpp"

class EscapePod : public Module
{

private:


public:
    EscapePod(RoomMenu * m);  

};




#endif
