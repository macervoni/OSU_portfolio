/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Implementation file for derived class EscapePodMenu.
This is the EscapePodMenu unique menu for user interaction.

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

#include "escapePodMenu.hpp"
#include "spaceship.hpp"
#include "inputValidation.hpp"
#include <iostream>


/*
    Constructor accepts pointers to Spaceship and Inventory classes and 
    sets them to member data pointers for manipulation.
*/

EscapePodMenu::EscapePodMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory)
{
    mySpaceship = theConnectedSpaceship;
    myInventory = theConnectedInventory;

}

/*
    Main menu interaction for this room (Space).
*/

void EscapePodMenu::displayChoices()
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
    << "1. Explore escape pod \n"
    << "2. Exit escape pod \n"
    << "3. View map \n"  
    << "4. Display inventory \n"
    << "5. Remove item from inventory \n"
    << "6. Upload flight plans from DTU \n"
    << "7. Put on spacesuit \n"
    << "8. Engage detachment thrusters \n";

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

            myInventory->findAndRemoveItem();           // User can choose item to be removed

            break;
        }

        case 6:
        {
            std::cout << "\n" << std::endl;

            if(myInventory->hasItem(22))                            // User has DTU with flight plans uploaded
            {
                std::cout 
                << "You gently insert your DTU and the on-board " 
                << "NavMap lights up.\n"
                << "It's got you on a direct course for Earth.\n"
                << std::endl;

                mySpaceship->flightPlans_inEscapePod = true;        // Sets flag that Escape tests later in game

            }

            else
            {
                std::cout
                << "You don't have any flight plans to upload\n"
                << std::endl;
            }

            break;
        }

        case 7:
        {
            std::cout << "\n" << std::endl;

            if(myInventory->hasItem(22))                            // User has DTU with flight plans uploaded
            {
                std::cout 
                << "Your quickly put on your spacesuit and make sure everything is \n"
                << "completely sealed. Ahhh, the comfort of your spacesuit.\n"
                << std::endl;

                mySpaceship->spacesuitOn_inEscapePod = true;         // Sets flag that Escape tests later in game
            }

            else
            {
                std::cout
                << "You don't have a spacesuit to put on\n"
                << std::endl;
            }

            break;
        }

        case 8:
        {
            std::cout << "\n" << std::endl;

         
            /* Conditional statements to check for all flags needed to win the game */

            if(mySpaceship->spacesuitOn_inEscapePod && mySpaceship->flightPlans_inEscapePod && mySpaceship->alienBactra_inEscapePod)
            {
                std::cout
                << "With a whizz and a buzz you begin your voyage back to earth. Upon re-entry into \n" 
                << "the Earth's atmosphere you're elated to know that humanity is saved and you've \n" 
                << "managed to keep yourself alive in the processes. You'll be a global hero for the \n"
                << "rest of your life and finally have the confidence to ask for that raise you never \n"
                << "had the guts to ask for before.\n\n"

                << "Game Over - You Win!\n\n" << std::endl;

                mySpaceship->escaped();     // Sets flag in Spaceship class that user has escaped 
                mySpaceship->mainMenu();    // Calls main menu for user to choose to play or exit

            }

            /* Conditional statements to check for all flags needed to win the game */
            else if(!mySpaceship->alienBactra_inEscapePod)
            {
                std::cout 
                << "As you kick your feet up on the console, the escape pod cruises forward in  \n"
                << "autopilot. You begin to drift off to sleep when you suddenly realize you never \n" 
                << "took the Martian bacteria with you and all of humanity is doomed. Good news is \n"
                << "you have plenty of time to think of a good excuse.\n\n"

                << "You're alive, but all of humanity will die - Try Again.\n"
                << "Hint: Get the STU from the equipment room and the bacteria from the science lab\n\n"
        
                << std::endl;

                mySpaceship->dead();    // Sets flag in Spaceship class that user has died 
                mySpaceship->mainMenu();
            }

            /* Conditional statements to check for all flags needed to win the game */

            else if(mySpaceship->alienBactra_inEscapePod && !mySpaceship->flightPlans_inEscapePod)
            {
                std::cout 
                << "You decided that you can navigate the escape pad without a flight plan. You \n"
                << "As you fly right by Earth toward an inevitable path into the Sun, you realize \n"
                << "what a bad idea that was.\n\n"

                << "You've melted in the sun and all of humanity will die - Try Again.\n"
                << "Hint: Get the DTU in the Galley and download the plans in the navigation room\n\n"

                << std::endl;


                mySpaceship->dead();
                mySpaceship->mainMenu();
            }

            /* Conditional statements to check for all flags needed to win the game */

            else if(mySpaceship->alienBactra_inEscapePod && mySpaceship->flightPlans_inEscapePod && !mySpaceship->spacesuitOn_inEscapePod)
            {
                std::cout << "\n" << std::endl;

                std::cout 
                << "As the Earth begins to fill up your single portal window, the \n"
                << "emergency alarm comes on. You check the dashboard - air leak. In the \n"
                << "few seconds you have before your brain is deprived of oxygen you have \n"
                << "two thoughts. One is that you should have put on your spacesuit and two, \n"
                << "you find solace knowing that at least the bacteria will find it's way \n"
                << "to Earth and humanity will be saved. You'll be a hero...\n\n"

                << "You're Dead, but humanity is saved - Try Again.\n"
                << "Hint: Get the spacesuit in the equipment room, with the code in the \n"
                << "navigation room.\n\n"

                << std::endl;


                mySpaceship->dead();
                mySpaceship->mainMenu();

            }

            else
            {

                std::cout  
                << "Within seconds of engaging the thrusters a ball of fire engulfs \n"
                << "the escape pod. You are burnt to a crisp.\n\n"

                << "You're Dead - Try Again.\n"
                << "Hint: Follow the instructions on the engineers tablet in the Galley\n\n"

                << std::endl;
            }
            









        }
    }

    }
    while(exit == false);

}


void EscapePodMenu::exploreRoom()
{
    std::cout << "\n" << std::endl;
    std::cout 
    << "The escape pod is small, but fully funcitonal. You boot up the system \n"
    << "and the console display lights up.\n"
    << std::endl;
}




void EscapePodMenu::exitRoom()
{
    mySpaceship->player = mySpaceship->player->N;   // Set's pointer in linked list back to main cabin
    mySpaceship->countdownTimer();                  // Runs the counter to reduce time by 5 minutes
    mySpaceship->player->menu->exploreRoom();       // Calls method of new room to display description
    mySpaceship->player->menu->displayChoices();    // Calls method of new room's menu to be displayed
}



void EscapePodMenu::viewMap()
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
    << "                 |                  |                | \n"
    << "                 |________   _______|________________| \n"
    << "                   |              |                    \n"
    << "                   |  Escape Pod  |                    \n"
    << "                    |            |                    \n"
    << "                     |    * *   |                    \n"
    << "                      |    *   |                    \n"
    << "                       |______|                    \n"


    << std::endl;
}



