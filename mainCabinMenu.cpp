/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Implementation file for derived class MainCabinMenu.
This is the MainCabinMenu unique menu for user interaction.

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

#include "mainCabinMenu.hpp"
#include "spaceship.hpp"
#include "inputValidation.hpp"
#include <iostream>


/*
    Constructor accepts pointers to Spaceship and Inventory classes and 
    sets them to member data pointers for manipulation.
*/

MainCabinMenu::MainCabinMenu(Spaceship * theConnectedSpaceship, Inventory * theConnectedInventory)
{
    mySpaceship = theConnectedSpaceship;
    myInventory = theConnectedInventory;
}

void MainCabinMenu::displayChoices()
{
    int choice = 0;
    bool exit = false;
    int isValid = 0;

    do
    {

    do
    {

    std::cout << "Enter your next move: " 
    << std::endl;

    std::cout 
    << "1.  Explore room \n"
    << "2.  View map \n"
    << "3.  Check inventory \n"
    << "4.  Remove item from inventory \n"
    << "* * * * * * * * * * * * * * * * \n"
    << "5.  Enter Navigation Room \n"
    << "6.  Enter Science Lab \n"
    << "7.  Enter Galley \n"
    << "8.  Enter Equipment Room \n"
    << "9.  Enter Transportation Room \n"
    << "10. Enter Comms Station \n"
    << "11. Enter Crew Quarters \n"
    << "* * * * * * * * * * * * * * * * \n"
    << "12. Quit\n";

    std::cin >> choice;

    if(inputValidation() == true)
    {
        if(choice < 0 || choice > 12)
        {
            std::cout << "-----------------------------\n"
            << "Please choose between 1 - 12\n"
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
            this->viewMap();
            break;
        }
        
        case 3:
        {
            std::cout << "checking inventory...\n" 
            << std::endl;

            myInventory->displayInventory();

            break;
        }

        case 4:
        {
            std::cout << "Accessing inventory...\n" 
            << std::endl;

            myInventory->findAndRemoveItem();                   // User can choose which inventory item to remove

            break;
        }

        case 5:
        {
            this->enterNavigation();
            exit = true;
            break;
        }

        case 6:
        {
            this->enterScienceLab();
            exit = true;
            break;
        }


        case 7:
        {
            this->enterGalley();
            exit = true;
            break;
        }

        case 8:
        {
            this->enterEquipment();
            exit = true;
            break;
        }

        case 9:
        {
            this->enterTransportation();
            exit = true;
            break;
        }

        case 10:
        {
            this->enterComms();
            exit = true;
            break;
        }


        case 11:
        {
            this->enterCrewQuarters();
            exit = true;
            break;
        }

        case 12:
        {

            this->terminate();              //Exit the current game game
            exit = true;
            break;
        }

    }

    }
    while(exit == false);

}

void MainCabinMenu::exploreRoom()
{
    std::cout << "\n" << std::endl;
    std::cout 
    << "Amidst a silent flashing red-light alarm and \n"
    << "thick grey smoke hanging low to the ground, \n"
    << "you're able to make out the luminescent signs \n"
    << "above the seven module doors on the ship: \n\n"
    << "***   Navigation   ***\n"
    << "***   Science Lab  ***\n"
    << "***      Galley    ***\n"
    << "***    Equipment   ***\n"
    << "*** Transportation ***\n"
    << "***      Comms     ***\n"
    << "***  Crew Quarters ***\n\n"
    << "You notice the sign above the crew quarters is \n"
    << "flickering off and on.\n"
    << std::endl;
}


/*  Below methods below are called depending on what room the user
    chooses to enter. Each method executes the following:
        - Moves player (head) to the next node(Space) in the ship
        - Calls the countdown timer to reduce the clock by 5 min
        - Displays the next rooms description
        - Displays the next rooms menu choices
*/

void MainCabinMenu::enterNavigation()
{
    mySpaceship->player = mySpaceship->player->N;
    mySpaceship->countdownTimer();
    mySpaceship->player->menu->exploreRoom();
    mySpaceship->player->menu->displayChoices();
}

void MainCabinMenu::enterScienceLab()
{
    mySpaceship->player = mySpaceship->player->NE;
    mySpaceship->countdownTimer();
    mySpaceship->player->menu->exploreRoom();
    mySpaceship->player->menu->displayChoices();
}

void MainCabinMenu::enterGalley()
{
    mySpaceship->player = mySpaceship->player->E;
    mySpaceship->countdownTimer();
    mySpaceship->player->menu->exploreRoom();
    mySpaceship->player->menu->displayChoices();
}

void MainCabinMenu::enterEquipment()
{
    mySpaceship->player = mySpaceship->player->SE;
    mySpaceship->countdownTimer();
    mySpaceship->player->menu->exploreRoom();
    mySpaceship->player->menu->displayChoices();
}

void MainCabinMenu::enterTransportation()
{
    mySpaceship->player = mySpaceship->player->S;
    mySpaceship->countdownTimer();
    mySpaceship->player->menu->exploreRoom();
    mySpaceship->player->menu->displayChoices();
}

void MainCabinMenu::enterComms()
{
    mySpaceship->player = mySpaceship->player->SW;
    mySpaceship->countdownTimer();
    mySpaceship->player->menu->exploreRoom();
    mySpaceship->player->menu->displayChoices();
}

void MainCabinMenu::enterCrewQuarters()
{
    mySpaceship->player = mySpaceship->player->W;
    mySpaceship->countdownTimer();
    mySpaceship->player->room_description();
    mySpaceship->dead();
    mySpaceship->mainMenu();

}





void MainCabinMenu::exitRoom()
{
    /* Can't exit maincabin - only for other rooms) */
}


void MainCabinMenu::terminate()
{
    std::cout << "Game Over\n\n";
    mySpaceship->dead();
    mySpaceship->mainMenu();
}





