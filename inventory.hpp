/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for the Inventory class.

This class is responsible for holding list of items the user adds to
their inventory during gameplay. It uses a vector container to hold 
pointers of the item objects instantiated within the menu objects.

*********************************************************************/


#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "item.hpp"

#include <vector>
#include <iostream>

class Spaceship;

class Inventory
{

protected:

    std::vector<Item*> inventory;               // Vector container of pointers to Item type           

    std::vector<Item*>::iterator iter           // Iterator set to the beginning of the list
    = inventory.begin();

    int count;                                  // Keeps track of total items in inventory
    int inventorySize;                          // Sets the limit of items player can carry
    int listCount;                              // Keeps track of current number of items in the list

public:

    Spaceship * mySpaceship;                    // Pointer to main Spaceship object 

/*
    Flags that let other objects in the game know if the user has specific items
    in their inventory that are critical to game interaction in various Spaces 
*/
    bool hasDTUempty;
    bool hasDTUfull;
    bool hasSpacesuit;
    bool hasCode;
    bool hasAlienBacteria;
    bool hasSTUempty;
    bool hasSTUfull;
    bool hasTakeOffSequence;
    bool hasHoloRadio;
    bool hasLabRat;



    Inventory(Spaceship * theConnectedSpaceship);
    ~Inventory();



    void displayInventory();
    bool isFull();

    void addItem(Item * i);
    void addItemFlag(int id);

    void findAndRemoveItem();

    void resetItemFlag(Item * i);

    void removeItem(int id);

    bool hasItem(int id);

    void cleanUp();

};

#endif
