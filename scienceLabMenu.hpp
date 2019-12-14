/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Header file for derived class ScienceLabMenu.
This is the ScienceLabMenu unique menu for user interaction.

It's constructor accepts pointers to the control flow Spaceship class
and the main Inventory class. These pointers allows the menu to access
the invetory data member (store, remove, check) as well as tell the 
Spaceship class to pass along info, like which room the player would
like to move to next, as well as have access to data memeber as needed.

*********************************************************************/

#ifndef SCIENCE_LAB_MENU_HPP
#define SCIENCE_LAB_MENU_HPP

#include "menu.hpp"

class Spaceship;

class Inventory;

class ScienceLabMenu : public RoomMenu
{


public:

    Spaceship * mySpaceship;

    Inventory * myInventory;

    ScienceLabMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory);

    void displayChoices();

    void exploreRoom();

    void exitRoom();

    void takeFullSTU();

    void takeHoloRadio();

    void takeLabRat();

    void viewMap();

};

#endif
