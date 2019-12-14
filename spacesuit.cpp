/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for derived Spacesuit class. 
This is a polymorphic derived class from the base Item class.

The item includes member data variables of the item's name and ID.
The ID is critical in the functioning of the program. The ID number 
is used to identify which items are being added or removed from the
user's inventory container.

*********************************************************************/

#include "spacesuit.hpp"
#include <iostream>



Spacesuit::Spacesuit()
{
    prev = nullptr;
    next = nullptr;

    itemName = "Spacesuit";
    itemID = 1;
}


void Spacesuit::itemDescription()
{

    std::cout 
    << "This is the description of the Spacesuit"
    << std::endl;
}