/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class FullDataTransferUnit.
This is a polymorphic class derived from the base class Item.

This item can be a node in a vector list that lives in the Inventory
object. This item is instantiated within the corresponding room menu
object in which the item is found in the game. 


*********************************************************************/

#ifndef FULL_DTU_HPP
#define FULL_DTU_HPP

#include "item.hpp"

class FullDataTransferUnit : public Item
{

public:

    FullDataTransferUnit * prev;
    FullDataTransferUnit * next;

    FullDataTransferUnit();

    void itemDescription();

};


#endif
