/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for derived SixDigitCode class. 
This is a polymorphic derived class from the base Item class.

The item includes member data variables of the item's name and ID.
The ID is critical in the functioning of the program. The ID number 
is used to identify which items are being added or removed from the
user's inventory container.

*********************************************************************/

#include "sixDigitCode.hpp"
#include <iostream>



SixDigitCode::SixDigitCode()
{
    prev = nullptr;
    next = nullptr;

    itemName = "6 Digit Code";
    itemID = 3;
}


void SixDigitCode::itemDescription()
{

    std::cout 
    << "Crew member ID: 4-6-19-1-30-2"
    << std::endl;
}