/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Header file for derived class EquipmentMenu.
This is the EquipmentMenu unique menu for user interaction.

It's constructor accepts pointers to the control flow Spaceship class
and the main Inventory class. These pointers allows the menu to access
the invetory data member (store, remove, check) as well as tell the 
Spaceship class to pass along info, like which room the player would
like to move to next, as well as have access to data memeber as needed.

*********************************************************************/

#ifndef EQUIPMENT_MENU_HPP
#define EQUIPMENT_MENU_HPP

#include "menu.hpp"


/* Forward declaration */

class Spaceship;

class Inventory;

class EquipmentMenu : public RoomMenu
{


public:

    Spaceship * mySpaceship;

    Inventory * myInventory;

    EquipmentMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory);

    ~EquipmentMenu();

    void displayChoices();

    void exploreRoom();

    void exitRoom();

    void takeSpacesuit();

    void takeEmptySTU();

    void lookAtSpacesuitPod_withOUTSuit();
    void lookAtSpacesuitPod_withSuit();

    void viewMap();
    
};

#endif
