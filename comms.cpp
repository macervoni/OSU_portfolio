/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for Comms class. This is a polymorphic 
derived class from the base Module class.

*********************************************************************/


#include "comms.hpp"

/*
    Constructor accepts a pointer to a unique menu class (instantiated
    in Spaceship class). During game-play, the Spaceship object controls
    the Head pointer to each of the room modules. At any point, the menu
    item for that current room pointed to by head can be accessed through
    this objects menu pointer.

    The constructor also sets all the pointers for the module for the
    linked list to nullptr. 
*/

Comms::Comms(RoomMenu * m)
{
    N = nullptr;
    NE = nullptr;
    E = nullptr; 
    SE = nullptr;
    S = nullptr;
    SW = nullptr;
    W = nullptr;
    NW = nullptr;   

    menu = m;

    inEscapePod = false;
}






