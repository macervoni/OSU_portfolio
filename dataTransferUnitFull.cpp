/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for derived FullDataTransferUnit class. 
This is a polymorphic derived class from the base Item class.

The item includes member data variables of the item's name and ID.
The ID is critical in the functioning of the program. The ID number 
is used to identify which items are being added or removed from the
user's inventory container.

*********************************************************************/


#include "dataTransferUnitFull.hpp"
#include <iostream>



FullDataTransferUnit::FullDataTransferUnit()
{
    prev = nullptr;
    next = nullptr;

    itemName = "Data Transfer Unit (map data)";
    itemID = 22;
}


void FullDataTransferUnit::itemDescription()
{

    std::cout 
    << "Small portable device that can hold up to 2.5 ZetaBytes.\n"
    << "The map coordinates are set for earth - just need to upload \n"
    << "them to a working escape pod"
    << std::endl;
}