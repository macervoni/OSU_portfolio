/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class Main Cabin.
This is the Main Cabin space in hte game.
It's constructor accepts a pointer to a unique menu object for the
Main Cabin, allowing the user to interact within the room.

*********************************************************************/

#ifndef MAIN_CABIN_HPP
#define MAIN_CABIN_HPP

#include "module.hpp"
#include "menu.hpp"

class MainCabin : public Module
{

private:

public:    

    MainCabin(RoomMenu *);  

    void room_description();

};




#endif
