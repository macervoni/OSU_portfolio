/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for derived LabRat class. 
This is a polymorphic derived class from the base Item class.

The item includes member data variables of the item's name and ID.
The ID is critical in the functioning of the program. The ID number 
is used to identify which items are being added or removed from the
user's inventory container.

*********************************************************************/

#include "labRat.hpp"
#include <iostream>



LabRat::LabRat()
{
    prev = nullptr;
    next = nullptr;

    itemName = "White lab rat";
    itemID = 8;
}


void LabRat::itemDescription()
{

    std::cout 
    << "White lab rat with a pink little nose."
    << std::endl;
}