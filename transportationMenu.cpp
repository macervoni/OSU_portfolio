/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Implementation file for derived class TransportationMenu.
This is the TransportationMenu unique menu for user interaction.

It's constructor accepts pointers to the control flow Spaceship class
and the main Inventory class. These pointers allows the menu to access
the inventory data member (store, remove, check) as well as tell the 
Spaceship class to pass along info, like which room the player would
like to move to next, as well as have access to data member as needed.

The menu displays several choices for the user to pick from. The choices
include opportunities to interact with elements in the room, as well as
taking objects from the room and adding to your inventory.

The menu has base options that are repeated for each room's menu and 
include 
    - Exploring the room
    - Exiting the room
    - Viewing the map of the room (w/ locater) 
    - Displaying current inventory
    - Removing item from inventory

Method calls to the Spaceship and Inventory classes are made as needed
throughout this class. 

*********************************************************************/

#include "transportationMenu.hpp"
#include "spaceship.hpp"
#include "inputValidation.hpp"
#include <iostream>


/*
    Constructor accepts pointers to Spaceship and Inventory classes and 
    sets them to member data pointers for manipulation.
*/

TransportationMenu::TransportationMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory)
{
    mySpaceship = theConnectedSpaceship;
    myInventory = theConnectedInventory;
}

void TransportationMenu::displayChoices()
{
    int choice = 0;
    bool exit = false;
    int isValid = 0;

    std::cout << "\n" << std::endl;

    do
    {

    do
    {
    
    std::cout << "Enter your next move: " 
    << std::endl;

    std::cout 
    << "1. Explore room \n"
    << "2. Exit Room \n"
    << "3. View map \n"  
    << "4. Display inventory \n"
    << "5. Remove item from inventory \n"
    << "6. Enter escape pod \n";

    std::cin >> choice;

    if(inputValidation() == true)
    {
        if(choice < 0 || choice > 6)
        {
            std::cout << "-----------------------------\n"
            << "Please choose between 1 - 6\n"
            << "-----------------------------"
            << std::endl;
        }
        else
        {
            isValid = 1;
        } 

    }

    }
    while(isValid == 0);

    switch(choice)
    {
        case 1:
        {
            this->exploreRoom();
            break;
        }

        case 2:
        {
            this->exitRoom();
            exit = true;
            break;
        }

        case 3:
        {
            this->viewMap();                // base class method
            break;
        }

        case 4:
        {
            std::cout << "checking inventory...\n" 
            << std::endl;

            myInventory->displayInventory();

            break;
        }

        case 5:
        {
            std::cout << "Accessing inventory...\n" 
            << std::endl;

            myInventory->findAndRemoveItem();                   // User can choose which inventory item to remove

            break;
        }

        case 6:
        {
            this->enterEscapePod();
            exit = true;
            break;
        }
    }

    }
    while(exit == false);

}

void TransportationMenu::exploreRoom()
{
   
    std::cout << "\n" << std::endl;
    std::cout 
    << "The transportatoin room contains multiple drones, rovers and \n"
    << "single unit transports. None of which you know how to operate. \n"
    << "In the back of the room you see a glowing sign over a door. It \n"
    << "It reads, **Escape Pod**\n"
    << std::endl;

}



/*  Below methods below are called depending on what room the user
    chooses to enter. Each method executes the following:
        - Moves player (head) to the next node(Space) in the ship
        - Calls the countdown timer to reduce the clock by 5 min
        - Displays the next rooms description
        - Displays the next rooms menu choices
*/

void TransportationMenu::exitRoom()
{
    mySpaceship->player = mySpaceship->player->N;
    mySpaceship->countdownTimer();
    mySpaceship->player->menu->exploreRoom();
    mySpaceship->player->menu->displayChoices();
}

void TransportationMenu::enterEscapePod()
{
    mySpaceship->player = mySpaceship->player->S;
    mySpaceship->countdownTimer();
    mySpaceship->player->menu->exploreRoom();
    mySpaceship->player->menu->displayChoices();
}

void TransportationMenu::viewMap()
{
    std::cout
    << "                  ------------------                   \n"
    << "                 |                  |                  \n"
    << "                 |                  |                  \n"
    << "                 |     Navigation   |                  \n"
    << "                 |                  |                  \n"
    << "                 |                  |                  \n"
    << "                 |------|   |-------|                  \n"
    << "                 |                  |                  \n"
    << "  ---------------|                  |----------------- \n"
    << "  |              |                  |                | \n"
    << "  |              |                  |                | \n"
    << "  |     Crew                              Science    | \n"
    << "  |   Quarters                              Lab      | \n"
    << "  |              |                  |                | \n"
    << "  |              |    Main Cabin    |                | \n"
    << "  ---------------|                  |---------------- \n"
    << "  |              |                  |                | \n"
    << "  |              |                  |                | \n"
    << "  |    Comms                              Galley     | \n"
    << "  |                                                  | \n"
    << "  |              |                  |                | \n"
    << "  |              |                  |                | \n"
    << "  ---------------|                  |---------------- \n"
    << "                 |                                   | \n"
    << "                 |_______    _______                 | \n"
    << "                 |                  |    Equipment   | \n"
    << "                 |  Transportation  |                | \n"
    << "                 |        * *       |                | \n"
    << "                 |________ * _______|________________| \n"
    << "                   |              |                    \n"
    << "                   |  Escape Pod  |                    \n"
    << "                    |            |                    \n"
    << "                     |          |                    \n"
    << "                      |        |                    \n"
    << "                       |______|                    \n"


    << std::endl;
}




