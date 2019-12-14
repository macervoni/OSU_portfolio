/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Header file for derived class NavigationMenu.
This is the NavigationMenu unique menu for user interaction.

It's constructor accepts pointers to the control flow Spaceship class
and the main Inventory class. These pointers allows the menu to access
the invetory data member (store, remove, check) as well as tell the 
Spaceship class to pass along info, like which room the player would
like to move to next, as well as have access to data memeber as needed.

*********************************************************************/

#ifndef NAVIGATION_MENU_HPP
#define NAVIGATION_MENU_HPP

#include "menu.hpp"

class Spaceship;

class Inventory;

class NavigationMenu : public RoomMenu
{


public:

    Spaceship * mySpaceship;

    Inventory * myInventory;

    NavigationMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory);

    void displayChoices();

    void exploreRoom();

    void exitRoom();

    void take6DigitCode();

    void takeFullDTU();

    void lookAtTerminal();

    void lookAtChair_withCode();            // Description of chair with code available to take
    void lookAtChair_withOUTCode();         // Description of chair WITHOUT code to take 

    void lookAtMissionCheckList();

    void viewMap();


};

#endif
