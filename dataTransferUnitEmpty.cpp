/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for derived EmptyDataTransferUnit class. 
This is a polymorphic derived class from the base Item class.

The item includes member data variables of the item's name and ID.
The ID is critical in the functioning of the program. The ID number 
is used to identify which items are being added or removed from the
user's inventory container.

*********************************************************************/

#include "dataTransferUnitEmpty.hpp"
#include <iostream>



EmptyDataTransferUnit::EmptyDataTransferUnit()
{
    prev = nullptr;
    next = nullptr;

    itemName = "Data Transfer Unit (empty)";
    itemID = 2;
}


void EmptyDataTransferUnit::itemDescription()
{

    std::cout 
    << "Small portable device that can hold up to 2.5 ZetaBytes"
    << std::endl;
}