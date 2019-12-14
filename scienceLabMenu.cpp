/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Implementation file for derived class ScienceLabMenu.
This is the ScienceLabMenu unique menu for user interaction.

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

#include "scienceLabMenu.hpp"
#include "spaceship.hpp"
#include "inputValidation.hpp"

#include "specimenTransferUnitFull.hpp"

#include "holoRadio.hpp"
#include "labRat.hpp"

#include <iostream>



/*
    Constructor accepts pointers to Spaceship and Inventory classes and 
    sets them to member data pointers for manipulation.
*/

ScienceLabMenu::ScienceLabMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory)
{
    mySpaceship = theConnectedSpaceship;
    myInventory = theConnectedInventory;

}

/*
    Instantiate new LabRat object, set to pointer of Item type (base class).
    Call Inventory class method to add item to vector list in Inventory obj.

*/

void ScienceLabMenu::takeLabRat()
{
    Item * temp = new LabRat;

    myInventory->addItem(temp);
}

/*
    Instantiate new HoloRadio object, set to pointer of Item type (base class).
    Call Inventory class method to add item to vector list in Inventory obj.

*/


void ScienceLabMenu::takeHoloRadio()
{
    Item * temp = new HoloRadio;

    myInventory->addItem(temp);

}

/*
    Instantiate new FullSpecimenTransferUnit object, set to pointer of 
    Item type (base class). Call Inventory class method to add item to
    vector list in Inventory obj.

*/


void ScienceLabMenu::takeFullSTU()
{
    Item * temp = new FullSpecimenTransferUnit;

    myInventory->addItem(temp);
}

void ScienceLabMenu::displayChoices()
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
    << "6. Look at crew lockers \n"
    << "7. Look at bacteria condenser \n"
    << "8. Look at lab rats \n";

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

        case 6: // crew lockers
        {
            int lockerChoice = 1;
            int isValid2 = 0;

            
            std::cout << "\n" << std::endl;
            std::cout 
            << "You see a series of 4 crew lockers.\n" 
            << "One of them is without a lock and it's not yours.\n\n"
            << std::endl;

            do
            {


            std::cout
            << "What do you want to do?:\n"
            << "1. Leave the locker alone - it's not yours\n"
            << "2. Look inside locker\n\n"
            << std::endl;

            std::cin >> lockerChoice;

            if(inputValidation() == true)
            {
                if(lockerChoice < 0 || lockerChoice > 2)
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

            if(lockerChoice == 2)
            {
                
                int radioChoice = 0;

                if(myInventory->hasItem(7))             // If user already has holoradio
                {
                    std::cout << "\n" << std::endl;
                    std::cout 
                    << "You rumamge through the locker again and find nothing \n"
                    << "of value. Now you know.\n"
                    << std::endl;
                }

                else
                {
                    std::cout << "\n" << std::endl;
                    std::cout 
                    << "You riffle through the contents of the locker and to your \n"
                    << "surprise you find a holographic radio - and it still has some \n"
                    << "charge. This doesn't have a long range, but it might come in \n"
                    << "handy.\n\n"
                    << std::endl;

                    std::cout 
                    << "Do you want to take the holographic radio?\n"
                    << "1. Yes\n"
                    << "2. No\n\n" 
                    << std::endl;

                    std::cin >> radioChoice;

                    if(radioChoice == 1)
                    {

                        this->takeHoloRadio();          // Add to inventory 
                    }
                }
                
            }

            break;

        }

        case 7: // bacteria condenser 
        {

            int condenserChoice = 0;
            int isValid3 = 0;

            std::cout 
            << "The bacteria condenser is a large glass tank filled with \n"
            << "alien bacteria from Mars in Petri dishes. They contain the \n"
            << "genetic recipe to wipe out an incurable disease that's inflicted \n"
            << "all of mankind.\n\n"

            << "You flip the switch to the main console and it flickers to life \n\n"
            << std::endl;

            do
            {

            std::cout
            << "**********************************************\n"
            << "*                                            *\n"
            << "*                                            *\n"
            << "*   Initiate bacteria extraction protocol?   *\n"
            << "*   1. Proceed                               *\n"
            << "*   2. Cancel                                *\n"
            << "*                                            *\n"
            << "*                                            *\n"
            << "**********************************************\n\n";

            std::cin >> condenserChoice;

            if(inputValidation() == true)
            {
                if(condenserChoice < 0 || condenserChoice > 2)
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

            switch(condenserChoice)
            {
                case 1:
                {
                    int STUchoice = 0;
                    int isValid4 = 0;

                    do
                    {

                    std::cout
                    << "**********************************************\n"
                    << "*                                            *\n"
                    << "*                                            *\n"
                    << "*   Insert Specimen Transport Unit           *\n"
                    << "*   1. Insert STU and extract                *\n"
                    << "*   2. Cancel                                *\n"
                    << "*                                            *\n"
                    << "*                                            *\n"
                    << "**********************************************\n\n";

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
                            isValid4 = 1;
                        } 
                    }

                    }
                    while(isValid4 == 0);

                    if(STUchoice == 1)
                    {
                        if(myInventory->hasItem(55))            // If user already has FULL specimen transport unit
                        {
                            std::cout 
                            << "You already have an STU with live bacteria\n\n"
                            << std::endl;
                            
                        }
                        else if(myInventory->hasItem(5))        // If user already has EMPTY specimen transport unit
                        {
                            std::cout
                            << "**********************************************\n"
                            << "*                                            *\n"
                            << "*                                            *\n"
                            << "*   Specimen Transfer In Progress...         *\n"
                            << "*                                            *\n"
                            << "*   Transfer Complete.                       *\n"
                            << "*                                            *\n"
                            << "*                                            *\n"
                            << "**********************************************\n\n";

                            takeFullSTU();                  // Add full STU to inventory

                            myInventory->removeItem(5);     // remove the original empty STU unit that's replaced by the Full
                        }
                        else
                        {
                            std::cout 
                            << "You need a Specimen Transfer Unit to \n"
                            << "to extract the bacteria specimen.\n\n" 
                            << "Better go find one. Quick.\n\n"
                            << std::endl;
                        }
                    }   break;
                }

                case 2:
                    break;
            }




            break;
        }

        case 8: // lab rats
        {
            int labChoice = 0;
            int isValid5 = 0;

            std::cout << "\n" << std::endl;
            
            if(myInventory->hasItem(8))                 // Already have a rat in user inventory 
            {
                std::cout 
                << "The rats are still doing what they do best. \n"
                << "You realize one is more than enough, so you let \n"
                << "them be.\n\n"
                << std::endl;
            }

            else
            {
                std::cout
                << "The lab rats look busy and content to have a purpose \n"
                << "in life. You wonder if you might have any use for these \n"
                << "little guys.\n\n"
                << std::endl;

                do
                {

                std::cout
                << "What do you want to do?:\n"
                << "1. Take a lab rat\n"
                << "2. Let them be\n\n"
                << std::endl;

                std::cin >> labChoice;

                if(inputValidation() == true)
                {
                    if(labChoice < 0 || labChoice > 2)
                    {
                        std::cout << "-----------------------------\n"
                        << "Please choose between 1 - 2\n"
                        << "-----------------------------"
                        << std::endl;
                    }
                    else
                    {
                        isValid5 = 1;
                    } 

                }

            }
            while(isValid5 == 0);

                if(labChoice == 1)
                {
                    this->takeLabRat();         // Add lab rat to inventory 
                }

                else
                {
                    std::cout 
                    << "They give you a look as to say, ""Thank you for leaving \n"
                    << "us be."" You leave them some food before turning away\n\n"
                    << std::endl;
                }
            }


            break;
        }
    }

    }
    while(exit == false);

}

void ScienceLabMenu::exploreRoom()
{
    std::cout << "\n" << std::endl;
    std::cout 
    << "You know the layout of the science lab all too well. This is \n"
    << "where you've spent much of the last several months experimenting \n"
    << "on the Martian bacteria. You know mankind depends on the genetic \n"
    << "makeup of this bacteria and you MUST get this back to Earth!\n\n"

    << "Off to the right you see a series of crew lockers, straight ahead \n"
    << "is the bacteria culture condensers and to your left you see that \n"
    << "several lab rats are still alive in their holding pens.\n\n"
    << std::endl;
}


void ScienceLabMenu::exitRoom()
{
    mySpaceship->player = mySpaceship->player->W;           // Sets pointer in linked list back to main cabin
    mySpaceship->countdownTimer();                          // Runs the counter to reduce time by 5 minutes
    mySpaceship->player->menu->exploreRoom();               // Calls method of new room to display description
    mySpaceship->player->menu->displayChoices();            // Calls method of new room's menu to be displayed
}


void ScienceLabMenu::viewMap()
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
    << "  |              |                  |       * *      | \n"
    << "  |              |    Main Cabin    |        *       | \n"
    << "  ---------------|                  |---------------- \n"
    << "  |              |                  |                | \n"
    << "  |              |                  |                | \n"
    << "  |    Comms                              Galley     | \n"
    << "  |                                                  | \n"
    << "  |              |                  |                | \n"
    << "  |              |                  |                | \n"
    << "  ---------------|                  |---------------- \n"
    << "                 |                                   | \n"
    << "                 |_______     ______                 | \n"
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


