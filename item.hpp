
/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for the base class Item. This is an abstract class and 
allows the derived classes to be polymorphic. Other base classes 
will inherit the virtual functions and manipulate them for their 
specific needs depending on their roll in game-play.

*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
class Item
{

protected:

    std::string itemName;                   // Stores name of the item
    int itemID;                             // Stores ID to be referenced in Menu and 
                                            // Inventory functions

public:


    virtual ~Item() = default;

    virtual void itemDescription() = 0;     // Accessor for item description

    int getItemID();                        // Accessor for item ID

    std::string getItemName();              // Accessor for item Name


};

#endif
