/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for derived FullSpecimenTransferUnit class. 
This is a polymorphic derived class from the base Item class.

The item includes member data variables of the item's name and ID.
The ID is critical in the functioning of the program. The ID number 
is used to identify which items are being added or removed from the
user's inventory container.

*********************************************************************/


#include "specimenTransferUnitFull.hpp"
#include <iostream>



FullSpecimenTransferUnit::FullSpecimenTransferUnit()
{
    prev = nullptr;
    next = nullptr;

    itemName = "specimen transfer unit (alien bacteria)";
    itemID = 55;
}


void FullSpecimenTransferUnit::itemDescription()
{

    std::cout 
    << "This STU is locked and loaded with human saving Martian bacteria.\n"
    << std::endl;
}