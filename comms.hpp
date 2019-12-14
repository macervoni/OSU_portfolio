/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class Comms.
This is the Comms space in hte game.
It's constructor accepts a pointer to a unique menu object for the
Comms room, allowing the user to interact within the room.

*********************************************************************/

#ifndef COMMS_HPP
#define COMMS_HPP

#include "module.hpp"
#include "menu.hpp"


class Comms : public Module
{

private:

public:
    Comms(RoomMenu * m);    
  
};




#endif
