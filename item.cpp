
/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for the Base class Item. This is an abstract class and 
allows the derived classes to be polymorphic. 

*********************************************************************/

#include "item.hpp"



int Item::getItemID()
{
    return itemID;
}      

std::string Item::getItemName()
{
    return itemName;
}