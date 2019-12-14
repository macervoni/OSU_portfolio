/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for CrewQuarters class. 
This is a polymorphic derived class from the base Module class.

*********************************************************************/

#include "crewQuarters.hpp"

/*
    Constructor accepts a pointer to a unique menu class (instantiated
    in Spaceship class). During game-play, the Spaceship object controls
    the Head pointer to each of the room modules. At any point, the menu
    item for that current room pointed to by head can be accessed through
    this objects menu pointer.

    The constructor also sets all the pointers for the module for the
    linked list to nullptr. 
*/

CrewQuarters::CrewQuarters(RoomMenu * m)
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
    list. Because the game is automatically over upon entering this 
    room - there is no unique menu to engage with and this description
    is automatically displayed to the user 
*/

void CrewQuarters::room_description()
{
    std::cout << "\n" << std::endl;
    std::cout 
    << "As the sealed door to the crew quarters opens \n"
    << "you instantly remember this was the room that had \n" 
    << "the explosion and thus what a grave mistake you've \n"
    << "just made.\n\n"
    << "As your body is sucked out into the vastness of \n"
    << "space through the large hole made by the explosion \n"
    << "you realize it's definitely too late for a career change\n"
    << std::endl;

    std::cout << "Game Over" << std::endl;

    std::cout << "\n" << std::endl;

}

