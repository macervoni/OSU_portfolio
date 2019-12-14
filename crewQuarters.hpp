/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class CrewQuarters.
This is the Crew Quarters space in the game.
It's constructor accepts a pointer to a unique menu object for the
Crew Quarters room, allowing the user to interact within the room.

*********************************************************************/

#ifndef CREW_QUARTERS_HPP
#define CREW_QUARTERS_HPP

#include "module.hpp"
#include "menu.hpp"

class CrewQuarters : public Module
{

private:

public:
    CrewQuarters(RoomMenu * m);  

    void room_description();

};




#endif
