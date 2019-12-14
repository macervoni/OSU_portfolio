/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Header file for derived class MainCabinMenu.
This is the MainCabinMenu unique menu for user interaction.

It's constructor accepts pointers to the control flow Spaceship class
and the main Inventory class. These pointers allows the menu to access
the invetory data member (store, remove, check) as well as tell the 
Spaceship class to pass along info, like which room the player would
like to move to next, as well as have access to data memeber as needed.

*********************************************************************/

#ifndef MAIN_CABIN_MENU_HPP
#define MAIN_CABIN_MENU_HPP

#include "menu.hpp"


class Spaceship;

class Inventory;

class MainCabinMenu : public RoomMenu
{


public:

    Spaceship * mySpaceship;

    Inventory * myInventory;

    MainCabinMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory);

    void displayChoices();

    void exploreRoom();

    void exitRoom();

    void enterNavigation();

    void enterScienceLab();

    void enterGalley();

    void enterEquipment();

    void enterTransportation();

    void enterComms();

    void enterCrewQuarters();

    void terminate();

};

#endif
