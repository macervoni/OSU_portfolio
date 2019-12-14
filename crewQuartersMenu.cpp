/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Implementation file for derived class CrewQuartersMenu.
This is the CrewQuartersMenu unique menu for user interaction.

This class is unique in that there is no display menu items for the 
user to interact with. The player dies upon entering this room

*********************************************************************/

#include "crewQuartersMenu.hpp"
// #include "spaceship.hpp"
#include <iostream>



/*
    Constructor accepts pointers to Spaceship class and 
    sets it to member data pointer for manipulation.
*/
CrewQuartersMenu::CrewQuartersMenu(Spaceship * theConnectedSpaceship)
{
    mySpaceship = theConnectedSpaceship;
}




void CrewQuartersMenu::displayChoices()
{
    
}

void CrewQuartersMenu::exploreRoom()
{
    
}

void CrewQuartersMenu::exitRoom()
{
    
}

void CrewQuartersMenu::checkInventory()
{
    
}






