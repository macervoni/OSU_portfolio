/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Implementation file for derived class CommsMenu.
This is the CommsMenu unique menu for user interaction.

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

#include "commsMenu.hpp"
#include "spaceship.hpp"
#include "inputValidation.hpp"
#include <iostream>


/*
    Constructor accepts pointers to Spaceship and Inventory classes and 
    sets them to member data pointers for manipulation.
*/

CommsMenu::CommsMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory)
{
    mySpaceship = theConnectedSpaceship;
    myInventory = theConnectedInventory;
}

/*
    Main menu interaction for this room (Space).
*/

void CommsMenu::displayChoices()
{
    int isValid = 0;
    int choice = 0;
    bool exit = false;

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
    << "6. Look at Comms Terminal \n";

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
    while (isValid == 0);

    switch(choice)
    {
        case 1:
        {
            this->exploreRoom();            // Description of room
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
            this->viewMap();                
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

            myInventory->findAndRemoveItem();       // User can choose item to be removed

            break;
        }

        case 6:
        {
            int commsChoice = 0;

            std::cout << "\n" << std::endl;
            std::cout 
            << "The comms portal is still working, but you can't seem to get \n"
            << "anyone on a hailing frequency. You notice a notification for \n" 
            << "a new message from command.\n\n"
            
            << "What do you want to do?:\n"
            << "1. Play message from command\n"
            << "2. Exit comms portal\n"
            << std::endl;

            std::cin >> commsChoice;

            if (commsChoice == 1)
            {
                std::cout << "\n" << std::endl;
                std::cout 
                << "The screen begins to flicker and only faint audio can be heard \n"
                << "through static hissing...\n"
                << "****Begin transmission****\n"
                << "....commander Briggs here. This urgent message....we must...it's \n"
                << "....life and death....mankind depends....days left...good luck.\n"
                << "****End transmission****\n\n"

                << "If it wasn't clear to you before, human life as we know it on depends \n"
                << "on you getting off this ship with the Martian bacteria\n"
                << std::endl;

            }


            break;
        }

    }

    }
    while(exit == false);

}

void CommsMenu::exploreRoom()
{
    std::cout << "\n" << std::endl;
    std::cout 
    << "The comms room was next to the explosion in the Crew Quarters and \n"
    << "it looks like some damage was taken. Most of the equipment is shut \n"
    << "off excpet for one video comms terminal\n"
    << std::endl;
}

void CommsMenu::exitRoom()
{
    mySpaceship->player = mySpaceship->player->E;       // Set's pointer in linked list back to main cabin
    mySpaceship->countdownTimer();                      // Runs the counter to reduce time by 5 minutes
    mySpaceship->player->menu->exploreRoom();           // Calls method of new room to display description
    mySpaceship->player->menu->displayChoices();        // Calls method of new room's menu to be displayed
}


void CommsMenu::viewMap()
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
    << "  |     * *                                          | \n"
    << "  |      *       |                  |                | \n"
    << "  |              |                  |                | \n"
    << "  ---------------|                  |---------------- \n"
    << "                 |                                   | \n"
    << "                 |_______    _______                 | \n"
    << "                 |                  |    Equipment   | \n"
    << "                 |  Transportation  |                | \n"
    << "                 |                  |                | \n"
    << "                 |________   _______|________________| \n"
    << "                   |              |                    \n"
    << "                   |  Escape Pod  |                    \n"
    << "                    |            |                    \n"
    << "                     |          |                    \n"
    << "                      |        |                    \n"
    << "                       |______|                    \n"


    << std::endl;

}





