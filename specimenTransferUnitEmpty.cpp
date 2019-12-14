/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for derived EmptySpecimenTransferUnit class. 
This is a polymorphic derived class from the base Item class.

The item includes member data variables of the item's name and ID.
The ID is critical in the functioning of the program. The ID number 
is used to identify which items are being added or removed from the
user's inventory container.

*********************************************************************/

#include "specimenTransferUnitEmpty.hpp"
#include <iostream>



EmptySpecimenTransferUnit::EmptySpecimenTransferUnit()
{
    prev = nullptr;
    next = nullptr;

    itemName = "specimen transfer unit (empty)";
    itemID = 5;
}


void EmptySpecimenTransferUnit::itemDescription()
{

    std::cout 
    << "Empty specimen transfer is able to hold live bacteria stable for 6 months.\n"
    << std::endl;
}