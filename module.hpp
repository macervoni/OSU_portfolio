/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

**********THIS IS THE SPACE CLASS PER REQUIREMENTS*************

Implementation file for the Base class Module. All derived classes
represent rooms in the game and are part of a linked list in the 
Spaceship class object.

*********************************************************************/


#ifndef MODULE_HPP
#define MODULE_HPP

#include <string>
#include <iostream>

// #include "mainCabinMenu.hpp"
#include "menu.hpp"

class Module
{

protected:

bool inEscapePod;

   

public:
   


    RoomMenu * menu;

    Module* N;
    Module* NE;
    Module* E;
    Module* SE;
    Module* S;
    Module* SW;
    Module* W;
    Module* NW;



    virtual ~Module() = default;

    bool getInEscapePod();

    void room_description();

};

#endif
