/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Header file for derived class CrewQuartersMenu.
This is the CrewQuartersMenu unique menu for user interaction.

It's constructor accepts a pointers to the control flow Spaceship class. 
This allows the menu to access the Spaceship class to pass along info,
like which room the player would like to move to next, as well as have 
access to data memeber as needed.

*********************************************************************/

#ifndef CREW_QUARTERS_MENU_HPP
#define CREW_QUARTERS_MENU_HPP

#include "menu.hpp"
#include "spaceship.hpp"

class CrewQuartersMenu : public RoomMenu
{


public:

    Spaceship * mySpaceship;

    CrewQuartersMenu(Spaceship * theConnectedSpaceship);

    void displayChoices();

    void exploreRoom();

    void exitRoom();

    void checkInventory();
    
    void findAndRemoveItem();

};

#endif
