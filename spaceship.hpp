/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Header file for the Spaceship class. 

This object is a main flow control function of the game and instantiates
all the game modules (spaces), room menus and inventory container. 

*********************************************************************/

#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP



#include "module.hpp"
#include "main_cabin.hpp"
#include "navigation.hpp"
#include "galley.hpp"
#include "scienceLab.hpp"
#include "equipment.hpp"
#include "transportation.hpp"
#include "escapePod.hpp"
#include "comms.hpp"
#include "crewQuarters.hpp"


#include "menu.hpp"
#include "inventory.hpp"

#include "item.hpp"
#include <iostream>
#include <string>

// class Inventory;

class Spaceship

{
private:

    bool isDead;
    bool isEscaped;

    int timeLeft;                   // Counter of the time remaining

    /*Pointers to all the ship modules */

    Module* main_cabin;             
    Module* navigation;              
    Module* galley;                  
    Module* science_lab;
    Module* equipment;
    Module* transportation;
    Module* escape_pod;
    Module* comms;
    Module* crew_quarters;

    


/* Pointers to all room menus */

    RoomMenu *  mainCabinMenu;
    RoomMenu *  nav_menu;
    RoomMenu *  science_lab_menu;
    RoomMenu *  galley_menu;
    RoomMenu *  equipment_menu;
    RoomMenu *  transportation_menu;
    RoomMenu *  escape_pod_menu;
    RoomMenu *  comms_menu;
    RoomMenu *  crew_quarters_menu;


public:

    bool flightPlans_inEscapePod;

    bool spacesuitOn_inEscapePod;

    bool alienBactra_inEscapePod;


    Inventory * inventory1;

    Module * player;

    Spaceship();

    void cleanUp();             // deallocates all the memory of menu, room and inventory objects

    void storySetup();          // Main game story description

    void dead();                // Tells program player is dead

    void escaped();             // Tells program player have escaped 

    void mainMenu();            

    void countdownTimer();      // Reduces timer by 5 minutes and displays to user

    int getTimeLeft();          // Accessor of member data timeLeft

};


#endif
