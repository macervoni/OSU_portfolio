/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class ScienceLab.
This is the Science Lab space in hte game.
It's constructor accepts a pointer to a unique menu object for the
Science Lab room, allowing the user to interact within the room.

*********************************************************************/

#ifndef SCIENCE_LAB_HPP
#define SCIENCE_LAB_HPP

#include "module.hpp"
#include "menu.hpp"

class ScienceLab : public Module
{

private:

public:
    ScienceLab(RoomMenu * m);  
};




#endif
