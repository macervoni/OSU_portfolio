/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Implementation file for derived class EquipmentMenu.
This is the EquipmentMenu unique menu for user interaction.

It's constructor accepts pointers to the control flow Spaceship class
and the main Inventory class. These pointers allows the menu to access
the inventory data member (store, remove, check) as well as tell the 
Spaceship class to pass along info, like which room the player would
like to move to next, as well as have access to data member as needed.

The menu displays several choices for the user to pick from. The choices
include opportunities to interact with elements in the room, as well as
taking objects from the room and adding to your inventory. This derived
class also includes sub-menus for deeper user engagement in the room

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

#include "equipmentMenu.hpp"
#include "spaceship.hpp"
#include "inputValidation.hpp"

#include "spacesuit.hpp"
#include "specimenTransferUnitEmpty.hpp"
#include <iostream>


/*
    Constructor accepts pointers to Spaceship and Inventory classes and 
    sets them to member data pointers for manipulation.
*/


EquipmentMenu::EquipmentMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory)
{
    mySpaceship = theConnectedSpaceship;
    myInventory = theConnectedInventory;
}

/*
    Main menu interaction for this room (Space).
*/

void EquipmentMenu::displayChoices()
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
    << "6. Look at Spacesuit Pods\n"
    << "7. Look in open drawer\n";

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
    while (isValid == 0);


    switch(choice)
    {
        case 1:
        {
            this->exploreRoom();            // Room description
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
            if(myInventory->hasSpacesuit)               // If user has spacesuit in inventory alread
            {
                this->lookAtSpacesuitPod_withOUTSuit();  // Display desription without suit
            }
            else
            {
                this->lookAtSpacesuitPod_withSuit();    // Else display with the suit
            }

            break;
        }

        case 7:
        {
            int STUchoice = 0;

            if(myInventory->hasItem(5) || myInventory->hasItem(55)) // has either a full or empty STU unit already
            {
                std::cout 
                << "You open the drawer and all it contains is a plasma \n"
                << "charger fit for a Specimen Transfer Unit.\n\n"
                << std::endl;
            }

            else
            {
                int isValid2 = 0;

                std::cout 
                << "You open the draw to see a single Specimen Transfer Unit \n"
                << "It's hooked up to a plasma charger.\n"
                << "These things can safety hold live bacteria for months!\n\n"
                << std::endl;

                do
                {

                std::cout 
                << "Do you want to take the Specimen Transfer Unit?\n"
                << "1. Yes\n"
                << "2. No\n\n" 
                << std::endl;

                std::cin >> STUchoice;

                if(inputValidation() == true)
                {
                    if(STUchoice < 0 || STUchoice > 2)
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

                if(STUchoice == 1)
                {
                    this->takeEmptySTU();   // Add to inventory
                }
            }

        break;
        }
    }

    }
    while(exit == false);                  // Ends menu loop

}



/*
    Unique description if user already has spacesuit
*/

void EquipmentMenu::lookAtSpacesuitPod_withOUTSuit()
{
    std::cout
    << "All the spacesuit pods are full, except for yours, \n"
    << "which is in your inventory.\n\n"

    << "For a minute you wonder how much one of these might go \n"
    << "for back home - then you remember you're in plastic box \n"
    << "in space that's about to explode.\n\n" << std::endl;
}

/*
    Unique description if user DOES NOT have spacesuit
*/

void EquipmentMenu::lookAtSpacesuitPod_withSuit()

{
    int isValid3 = 0;       // Input validation flag
    int suitChoice = 0;     // User input variable

    std::cout << "\n"; 
    std::cout 
    << "You approach the spacesuit pods and see your suit sealed\n"
    << "and secured with a blinking keypad to unlock it.\n\n" 
    << std::endl;

    do
    {
        
    std::cout     
    << "Do you want to unlock your spacesuit?\n"
    << "1. Yes\n"
    << "2. No\n" 
    << std::endl;

    std::cin >> suitChoice; 


    if(inputValidation() == true)
    {
        if(suitChoice < 0 || suitChoice > 2)
        {
            std::cout << "-----------------------------\n"
            << "Please choose between 1 - 2\n"
            << "-----------------------------"
            << std::endl;
        }
        else
        {
            isValid3 = 1;
        } 
    }
    }
    while(isValid3 == 0);

    switch (suitChoice)
    {
        case 1:
        {
            if(myInventory->isFull())                   // If your inventory is full
            {
                std::cout << "\n"; 
                std::cout 
                << "Just before you enter the code, you realize you \n"
                << "you have no more room left to hold items. \n"
                << "Consider dropping an item from inventory."
                << std::endl;
            }


            else if (myInventory->hasItem(3))           // inventory open and you don't already
                                                        // have the suit       
            {
                std::cout << "\n"; 
                std::cout 
                << "You enter the code into the keypad with trembling fingers.\n"
                << "You hear a hiss and a pop as the pod opens.\n\n" << std::endl;

                this->takeSpacesuit();                  // Add the suit to your inventory
            }

            else
            {
                std::cout << "\n"; 
                std::cout 
                << "You don't have the code to unlock your spacesuit\n"
                << std::endl;
            }
            break;
        }

        case 2:
            break;
    }

}

void EquipmentMenu::exploreRoom()
{
    std::cout << "\n" << std::endl;
    std::cout 
    << "There are two sides to the equipment room, both leading to \n"
    << "a large portal window at the end of the room. To your left \n"
    << "is a row of spacesuit pods and an access panel. Your right \n"
    << "is a tower of cabinets and drawers full of various type of \n"
    << "equipment needed for this expedition. They're all locked and \n"
    << "only two of the crew members can open via biometrics. You \n"
    << "notice one of the draws is slightly open...\n"
    << std::endl;
}

EquipmentMenu::~EquipmentMenu()
{
    
    
}

/*
    This method instantiates the new object inside the menu class
    and then passes to the Inventory method to store the item in 
    the users inventory. 
*/

void EquipmentMenu::takeSpacesuit()
{
    Item * spacesuitPtr = new Spacesuit;       // New object created now that needed in game

    mySpaceship->inventory1->addItem(spacesuitPtr); // Add to user's inventory
}

/*
    This method instantiates the new object inside the menu class
    and then passes to the Inventory method to store the item in 
    the users inventory. 
*/

void EquipmentMenu::takeEmptySTU()
{
    Item * STUptr
    = new EmptySpecimenTransferUnit;                // New object created now that needed in game

    myInventory->addItem(STUptr);                   // Add to user's inventory
}


void EquipmentMenu::exitRoom()
{
    mySpaceship->player = mySpaceship->player->W;   // Set's pointer in linked list back to main cabin
    mySpaceship->countdownTimer();                  // Runs the counter to reduce time by 5 minutes
    mySpaceship->player->menu->exploreRoom();       // Calls method of new room to display description
    mySpaceship->player->menu->displayChoices();    // Calls method of new room's menu to be displayed
}

void EquipmentMenu::viewMap()
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
    << "                 |__________________                 | \n"
    << "                 |                  |    Equipment   | \n"
    << "                 |  Transportation  |       * *      | \n"
    << "                 |                  |        *       | \n"
    << "                 |________   _______|________________| \n"
    << "                   |              |                    \n"
    << "                   |  Escape Pod  |                    \n"
    << "                    |            |                    \n"
    << "                     |          |                    \n"
    << "                      |        |                    \n"
    << "                       |______|                    \n"


    << std::endl;


}



