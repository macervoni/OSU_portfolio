/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Header file for Base class Menu.
This an abstract class and all derived classes are unique menu objects
used within corresponding spaces for user interaction. 

*********************************************************************/


#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>


class RoomMenu

{

protected:

    

public:

    virtual void displayChoices() = 0;  // Displays menu options for user interaction 

    virtual void exploreRoom() = 0;     // Provides description of the room

    virtual void exitRoom() = 0;        // Exits the room, changing the linked list values

    virtual ~RoomMenu() = default;
    
    void checkInventory();              // This can eventually be removed as inventory 
                                        // object will handle inside room menus

   
    void findAndRemoveItem();           // User removes items from inventor 
    void viewMap();                     // Display map with wayfinder symbol  

};

#endif
