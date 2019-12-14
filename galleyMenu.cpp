/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Implementation file for derived class GalleyMenu.
This is the GalleyMenu unique menu for user interaction.

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

#include "galleyMenu.hpp"
#include "spaceship.hpp"
#include "dataTransferUnitEmpty.hpp"
#include "inputValidation.hpp"


// #include "alienBacteria.hpp"

#include <iostream>


/*
    Constructor accepts pointers to Spaceship and Inventory classes and 
    sets them to member data pointers for manipulation.
*/

GalleyMenu::GalleyMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory)
{
    mySpaceship = theConnectedSpaceship;
    myInventory = theConnectedInventory;

}

void GalleyMenu::displayChoices()
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
    << "3. View Map \n"
    << "4. Display inventory \n"
    << "5. Remove item from inventory \n"
    << "6. Look at engineer's tablet \n"
    << "7. Look at tech officer's backpack \n";

    std::cin >> choice;

    if(inputValidation() == true)
    {
        if(choice < 0 || choice > 7)
        {
            std::cout << "-----------------------------\n"
            << "Please choose between 1 - 7\n"
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

            myInventory->findAndRemoveItem();           // User can choose item to be removed

            break;
        }

        case 6:
        {
            this->lookAtEngineerTablet();
            break;
        }


        case 7:
        {
            /*  This condition tests if the user has either ran empty or a 
                full DTU in their inventory. In either case, they should 
                not be presented the option to take another empty DTU unit
            */

            if(myInventory->hasItem(2) || myInventory->hasItem(22))
            {
                this->lookAtBag_withOUTDTU();               // Description of bag without the DTU in it
            }
            else
            {
                this->lookAtBag_wihtDTU();                  // Description of bag with DTU in it
            }

            break;
        }



    }

    }
    while(exit == false);           // End of menu do-while-loop

}

void GalleyMenu::exploreRoom()
{
    std::cout << "\n" << std::endl;
   
    std::cout 
    << "The ship's galley is full of all the modern accouterments \n"
    << "of any space kitchen - including a 3D food printer. In the \n"
    << "middle of the room sits a large eating table, which looks as \n"
    << "the rest of the crew had just finished dinner before heading \n"
    << "to the crew quarters.\n\n"

    << "Off in the corner on a bench you see the engineer's tablet \n"
    << "and the ship's chief technology officer's backpack on the \n"
    << "main table.\n\n"
  
    << std::endl;
}

void GalleyMenu::lookAtBag_wihtDTU()
{
    
    int isValid2 = 0;

    int DTUchoice = 0;

    std::cout << "\n" << std::endl;
    std::cout 
    << "The bag is small and has considerable weight when you \n"
    << "pick it up off the table. You reach inside and grasp a \n"
    << "smooth metallic cylinder.\n\n"

    << "Upon further inspection you realize it's a Data Transfer \n"
    << "Unit - capable of holding well over 2 zetabytes. You seem \n"
    << "to recall from training that you can store an entire star \n"
    << "map of our quadrant of the galaxy on just one unit.\n\n"
    << std::endl;

    do
    {

    std::cout    
    << "Do you want to take the Data Transfer Unit?\n"
    << "1. Yes\n"
    << "2. No\n" 
    << std::endl;

    std::cin >> DTUchoice;

    if(inputValidation() == true)
    {
        if(DTUchoice < 0 || DTUchoice > 2)
        {
            std::cout << "-----------------------------\n"
            << "Please choose between 1 - 2\n"
            << "-----------------------------"
            << std::endl;
        }
        else
        {
            isValid2 = 1;
        } 

    }


    }
    while(isValid2 == 0);

    switch(DTUchoice)
    {
        case 1:
        {
            this->takeEmptyDTU();               // Add Empty DTU to Inventory
            break;
        }

        case 2:
        {
            break;
        }
    }



}

void GalleyMenu::lookAtBag_withOUTDTU()
{
    std::cout << "\n" << std::endl;
    std::cout 
    << "You again rummage through the tech officer's backpack \n"
    << "in the hopes of finding another useful item that will \n"
    << "get you off this about-to-explode spaceship....\n\n"
    << "Nothing\n\n"
    << std::endl;
}

void GalleyMenu::lookAtEngineerTablet()
{
    std::cout << "\n" << std::endl;

    std::cout 
    << "You turn on the tablet and the screen comes to life with \n"
    << "a sub-routine document you've never encountered before.\n\n"

    << "*************** Escape Pod Sub-Routine ***************\n\n"

    << "  1. Upload Flight Plans\n"
    << "  2. Put on Spacesuit\n"
    << "  3. Engage Detachment Thrusters\n\n"

    << "Caution: Ensure your spacesuit is on and all seals \n"
    << "are locked before engaging the detachment thrusters.\n\n"

    << "******************************************************\n\n"

    << "It seems the tablet is jammed an no other documents can \n"
    << "be accessed at this time. You leave the tablet behind. \n\n"
    
    << std::endl;
}


void GalleyMenu::takeEmptyDTU()         

{
    Item * temp = new EmptyDataTransferUnit;               // New empty DTU object set to Item type pointer

    myInventory->addItem(temp);
}

void GalleyMenu::exitRoom()
{
    mySpaceship->player = mySpaceship->player->W;           // Set's pointer in linked list back to main cabin
    mySpaceship->countdownTimer();                          // Runs the counter to reduce time by 5 minutes
    mySpaceship->player->menu->exploreRoom();               // Calls method of new room to display description
    mySpaceship->player->menu->displayChoices();            // Calls method of new room's menu to be displayed
}

void GalleyMenu::viewMap()
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
    << "  |                                        * *       | \n"
    << "  |              |                  |       *        | \n"
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



