/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for derived class FullSpecimenTransferUnit.
This is a polymorphic class derived from the base class Item.

This item can be a node in a vector list that lives in the Inventory
object. This item is instantiated within the corresponding room menu
object in which the item is found in the game. 


*********************************************************************/

#ifndef SPECIMEN_TRANSFER_UNIT_FULL_HPP
#define SPECIMEN_TRANSFER_UNIT_FULL_HPP

#include "item.hpp"

class FullSpecimenTransferUnit : public Item
{

public:

    FullSpecimenTransferUnit * prev;
    FullSpecimenTransferUnit * next;

    FullSpecimenTransferUnit();

    void itemDescription();

};


#endif
