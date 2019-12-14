/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Implementation file for derived class NavigationMenu.
This is the NavigationMenu unique menu for user interaction.

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

#include "navigationMenu.hpp"
#include "spaceship.hpp"
#include "inputValidation.hpp"

#include "sixDigitCode.hpp"
#include "dataTransferUnitFull.hpp"
#include <iostream>


/*
    Constructor accepts pointers to Spaceship and Inventory classes and 
    sets them to member data pointers for manipulation.
*/

NavigationMenu::NavigationMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory)
{
    mySpaceship = theConnectedSpaceship;
    myInventory = theConnectedInventory;
}


/*
    Represents taking the flight map, as it will load into an empty
    DTU item and become a fullDTU.
*/
void NavigationMenu::takeFullDTU()              
{
    Item * temp = new FullDataTransferUnit;

    myInventory->addItem(temp);
}


void NavigationMenu::take6DigitCode()
{
    Item * temp = new SixDigitCode;

    myInventory->addItem(temp);
}

void NavigationMenu::displayChoices()
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
    << "6. Look at flight chair \n" 
    << "7. Look at pilot's terminal \n" 
    << "8. Look at mission checklist \n" 

    << std::endl;

    std::cin >> choice;

    if(inputValidation() == true)
    {
        if(choice < 0 || choice > 8)
        {
            std::cout << "-----------------------------\n"
            << "Please choose between 1 - 8\n"
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

            myInventory->findAndRemoveItem();               // User can choose which inventory item to remove

            break;
        }

        case 6:
        {
            

            if(myInventory->hasItem(3))                  // If inventory already has 6 digit code (3 = item ID)
                                             
            {
                this->lookAtChair_withOUTCode();
            }
            else
            {
               this->lookAtChair_withCode(); 
            }
            
            break;
        }

        case 7:
        {
            this->lookAtTerminal();
            break;
        }


        case 8:
        {
            this->lookAtMissionCheckList();
            break;
        }
    }
    }
    while(exit == false);

}

void NavigationMenu::exploreRoom()                 // No need for alternative versions
{
    std::cout << "\n" << std::endl;
    std::cout 
    << "The navigation room is fully transparent and you \n"
    << "can see the celestial bodies of the solar system in \n"
    << "the distance and the blue dot of Earth front and center\n\n"

    << "Straight ahead you see the glowing terminal display \n"
    << "by the pilot's dashboard and off to your right you see \n"
    << "your flight chair. On the top of the star map table you \n"
    << "notice the mission checklist is open on the table display.\n\n"

    << "Flickering on the main display panel is the self destruct \n"
    << "countdown showing " << mySpaceship->getTimeLeft() << " minutes "
    << "remain.\n\n"

    << "You also notice sparks coming out of the main ship control panel.\n"
    << "Looks like this ship is floating space junk at best.\n" << std::endl; 
 
}

void NavigationMenu::lookAtChair_withCode()
{
    int chairChoice = 0;
    int isValid2 = 0;

    std::cout 
    << "In your chair you find a folded up piece of paper \n"
    << "with a 6 digit code - your CREW MEMBER ID. You could \n" 
    << "never remember your ID, so writing it down was a safe \n"
    << "bet. You recall that your ID is also the code to unlock \n"
    << "your spacesuit in the EQUIPMENT ROOM.\n\n"
    << std::endl;

    do
    {

    
    std::cout
    << "Do you want to take the 6 digit code?\n"
    << "1. Yes\n"
    << "2. No\n" 
    << std::endl;

    std::cin >> chairChoice; 

    if(inputValidation() == true)
    {
        if(chairChoice < 0 || chairChoice > 2)
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

    switch (chairChoice)
    {
        case 1:
        {
            this->take6DigitCode();                      // You add the code to your inventory 

            break;
        }

        case 2:
            break;
    }
}

void NavigationMenu::lookAtChair_withOUTCode()
{
    std::cout 
    << "Bleeding edge technology adorns both arm rests, but \n"
    << "you never took the time to read up on the manual.\n\n"
    << "As comfy as this space chair is, you should probably \n"
    << "get moving with the impending self-destruction and all.\n\n"
    << std::endl;

}

void NavigationMenu::lookAtTerminal()
{
    int terminalChoice = 0;
    int isValid3 = 0;


    do
    {


    std::cout 
    << "*****************************************\n"
    << "*                                       *\n"
    << "*                                       *\n"
    << "*   Download flight plans?              *\n"
    << "*   1. Download                         *\n"
    << "*   2. Exit                             *\n"
    << "*                                       *\n"
    << "*                                       *\n"
    << "*                                       *\n"
    << "*****************************************\n";

    std::cin >> terminalChoice; 

    if(inputValidation() == true)
    {
        if(terminalChoice < 0 || terminalChoice > 2)
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

    switch (terminalChoice)
    {
        case 1:
        {
           
            if(myInventory->hasItem(22))                        // If already have full DTU in inventory
                                                                // passing itemID for FULL DTU 
            {
                std::cout << "Plans have already been downloaded "
                << "to Data Transfer Unit" << std::endl;
            }        

            else if (myInventory->hasItem(2))                   // If already has an EMPTY DTU in inventory
                                                                // passing itemID for EMPTY DTU 
            {
                
                std::cout << "DOWNLOADED FLIGHT PLANS!\n";
                

                
                takeFullDTU();                                  //Add a full DTU unit to inventory

                myInventory->removeItem(2);                     // Remove orignal empty DTU unit from inventory
                
            }
            else
            {
                std::cout << "You need a Data Transfer Unit "
                <<" to download the map." << std::endl;
            }

            break;
        }

        case 2:
            std::cout << "\n" << std::endl;
            break;
    }

}

void NavigationMenu::lookAtMissionCheckList()
{
    std::cout 
    << "Luckily the ships executive officer left open the mission \n"
    << "checklist. There's no way to take it with you, but it will \n"
    << "help you reorient yourself with gear you MIGHT need to get \n"
    << "off this ship with the Martian specimens before it's too late.\n\n"

    << "******** MISSION CHECKLIST ********\n"
    << "> Data Transfer Units \n"
    << "> Specimen Transfer Units \n"
    << "> Lab Rats \n"
    << "> Drones \n"
    << "> Field Rovers \n"
    << "> Spacesuits \n"
    << "> Takeoff Sequence \n"
    << "> Flight Plans\n\n"
    << std::endl;
}

void NavigationMenu::exitRoom()
{
    mySpaceship->player = mySpaceship->player->S;       // Sets pointer in linked list back to main cabin
    mySpaceship->countdownTimer();                      // Runs the counter to reduce time by 5 minutes
    mySpaceship->player->menu->exploreRoom();           // Calls method of new room to display description
    mySpaceship->player->menu->displayChoices();        // Calls method of new room's menu to be displayed
}


void NavigationMenu::viewMap()
{
    std::cout
    << "                  ------------------                   \n"
    << "                 |                  |                  \n"
    << "                 |                  |                  \n"
    << "                 |     Navigation   |                  \n"
    << "                 |        * *       |                  \n"
    << "                 |         *        |                  \n"
    << "                 |------|    |------|                  \n"
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



