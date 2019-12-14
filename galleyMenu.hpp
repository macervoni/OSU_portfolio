/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Header file for derived class GalleyMenu.
This is the GalleyMenu unique menu for user interaction.

It's constructor accepts pointers to the control flow Spaceship class
and the main Inventory class. These pointers allows the menu to access
the invetory data member (store, remove, check) as well as tell the 
Spaceship class to pass along info, like which room the player would
like to move to next, as well as have access to data memeber as needed.

*********************************************************************/

#ifndef GALLEY_MENU_HPP
#define GALLEY_MENU_HPP

#include "menu.hpp"


/* Forward declaration */

class Spaceship;

class Inventory;

class GalleyMenu : public RoomMenu
{


public:

    Spaceship * mySpaceship;

    Inventory * myInventory;

    GalleyMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory);

    void displayChoices();

    void exploreRoom();

    void exitRoom();

    void lookAtBag_wihtDTU();

    void lookAtBag_withOUTDTU();

    void lookAtEngineerTablet();

    void takeEmptyDTU();   

    void viewMap();      
};

#endif
