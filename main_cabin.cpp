/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for MainCabin class. 
This is a polymorphic derived class from the base Module class.

*********************************************************************/

#include "main_cabin.hpp"

/*
    Constructor accepts a pointer to a unique menu class (instantiated
    in Spaceship class). During game-play, the Spaceship object controls
    the Head pointer to each of the room modules. At any point, the menu
    item for that current room pointed to by head can be accessed through
    this objects menu pointer.

    The constructor also sets all the pointers for the module for the
    linked list to nullptr. 
*/

MainCabin::MainCabin(RoomMenu * m)
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

    
/*
    This child class has a unique room-description() method that 
    is called upon the player moving into this space in the linked
    list. Because the flow of the game calls for a room description 
    to be displayed to the user without any prompts or interaction, 
    this method is called automatically upon entering this room. 
*/

void MainCabin::room_description()
{
    std::cout 
    << "Amidst a silent flashing red-light alarm and \n"
    << "thick grey smoke hanging low to the ground, \n"
    << "you're able to make out the luminescent signs \n"
    << "above the seven module doors on the ship: \n"
    << "Navigation\n"
    << "Science Lab\n"
    << "Galley\n"
    << "Equipment\n"
    << "Transportation\n"
    << "Comms\n"
    << "Crew Quarters\n\n"
    << "You notice the sign above the crew quarters is \n"
    << "flickering off and on.\n"
    << std::endl;
}




