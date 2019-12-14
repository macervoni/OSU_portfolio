/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for derived HoloRadio class. 
This is a polymorphic derived class from the base Item class.

The item includes member data variables of the item's name and ID.
The ID is critical in the functioning of the program. The ID number 
is used to identify which items are being added or removed from the
user's inventory container.

*********************************************************************/


#include "holoRadio.hpp"
#include <iostream>



HoloRadio::HoloRadio()
{
    prev = nullptr;
    next = nullptr;

    itemName = "Holographic Radio";
    itemID = 7;
}


void HoloRadio::itemDescription()
{

    std::cout 
    << "Short range comms device that displays a holographic \n"
    << " display of each user.\n"
    << std::endl;
}