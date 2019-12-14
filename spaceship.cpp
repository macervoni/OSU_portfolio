/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 


Implementation file for Spaceship class.

This is the main flow control class for the entire game and the linked
list container for all the spaces (modules/rooms) in the game.

The class instantiates the inventory object, all room module objects
and all room menu objects. The class also manages the linked list to 
move the user throughout all the rooms in the game. 

This class also manages the main menu for the game and the deallocation 
of all instantiated objects for rooms, menus and inventory. 

*********************************************************************/

#include "spaceship.hpp"
#include "inputValidation.hpp"


/* menu derived classes */

#include "mainCabinMenu.hpp"
#include "navigationMenu.hpp"
#include "galleyMenu.hpp"
#include "scienceLabMenu.hpp"
#include "equipmentMenu.hpp"
#include "transportationMenu.hpp"
#include "escapePodMenu.hpp"
#include "commsMenu.hpp"
#include "crewQuartersMenu.hpp"


/*
    The constructor instantiates a new inventory object and assigns to the 
    pointer in Spaceship's member data. Sets dead and escaped game status 
    flags to false, sets the ships self-destruction timer to 90 and sets 
    critical game play status flags to false - which all three need to be 
    set to true throughout the game to successfully win.
*/


Spaceship::Spaceship()
{

    inventory1 = new Inventory(this);           // New Inventory object 

    isDead = false;                             // Flag to return to main menu if died
    isEscaped = false;                          // Flag to return to main menu if escaped

    timeLeft = 90;


    flightPlans_inEscapePod = false;            // Flag that user has flightPlans uploaded to escape pod
    spacesuitOn_inEscapePod = false;            // Flag user has their spacesuit on in the escape pod
    alienBactra_inEscapePod = false;            // Flag user has the alien bacteria while in the escape pod




/*  Menu objects. 

    Each object is instantiated and assigned to pointers in Spaceship's member data.
    The new Menu object is passed pointers of this Spaceship object and the inventory
    object that is party of Spaceship's member data. This allows each room's menu object
    to access the necessary methods/data in both the Spaceship and the Inventory by the 
    user while interacting with the menu objects.
*/

    mainCabinMenu       = new MainCabinMenu(this, inventory1);
    nav_menu            = new NavigationMenu(this, inventory1);
    galley_menu         = new GalleyMenu(this, inventory1);
    science_lab_menu    = new ScienceLabMenu(this, inventory1);
    equipment_menu      = new EquipmentMenu(this, inventory1);
    transportation_menu = new TransportationMenu(this, inventory1);
    escape_pod_menu     = new EscapePodMenu(this, inventory1);
    comms_menu          = new CommsMenu(this, inventory1);
    crew_quarters_menu  = new CrewQuartersMenu(this);



/* 
    Module objects.

    Each object is instantiated and assigned to pointers in Spaceship's member data.
    The new Module object (Space) is passed a pointer to the menu objects so that
    each room can point to their own menu object via the lined list header during game
    play. For example, the head node is 'player.' When player->menu->explore() room is 
    called in ANY room, the program automatically calls the menu object of the room the 
    player is in. 
*/

    main_cabin       = new MainCabin(mainCabinMenu);     // pass pointer to menu
    navigation       = new Navigation(nav_menu);
    galley           = new Galley(galley_menu);
    science_lab      = new ScienceLab(science_lab_menu);
    equipment        = new Equipment(equipment_menu);
    transportation   = new Transportation(transportation_menu);
    escape_pod       = new EscapePod(escape_pod_menu);
    comms            = new Comms(comms_menu);
    crew_quarters    = new CrewQuarters(crew_quarters_menu);





/* linking of all modules */

    main_cabin->N = navigation;
    navigation->S = main_cabin;

    main_cabin->NE = science_lab;
    science_lab->W = main_cabin;

    main_cabin->E = galley;
    galley->W = main_cabin;

    galley->S = equipment;
    equipment->N = galley;

    main_cabin->SE = equipment;
    equipment->W = main_cabin;

    main_cabin->S = transportation;
    transportation->N = main_cabin;

    transportation->S = escape_pod;
    escape_pod->N = transportation;

    main_cabin->SW = comms;
    comms->E = main_cabin;

    comms->N = crew_quarters;

    main_cabin->W = crew_quarters;

    player = main_cabin;                // Head pointer = set to main cabin room to start game play

}

/*
    This main menu handles initial game play and repeat game play after the user 
    exits, loses or wins the game. It also handles the 'clean up' of the game in 
    order to reset all memory allocations, flags and the countdown timer for the 
    next game play. 
*/

void Spaceship::mainMenu()
{
    int choice = 0;

    int isValid = 0;        // Input validation flags    
    int isValid2 = 0;       // Input validation flags

    if(isDead || isEscaped)                                 // If the user has died or successfully escaped the ship
    {
        int replay = 0;                                     

        do

        {
                    
        std::cout << "Would you like to play again?\n"
        << "1. Yes\n"
        << "2. No\n";

        std::cin >> replay;

        if(inputValidation() == true)
        {
            if(replay < 0 || replay > 2)
            {
                std::cout << "-----------------------------\n"
                << "Please choose between 1 - 2\n"
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


        if (replay == 2)                                // If user does not want to play again
            {
                std::cout << "Program terminated"
                << std::endl;
                
                cleanUp();
                
                exit(0);

                
            }

        if (replay == 1)
        {
            inventory1->cleanUp();          // Method to delete all memory for all objects in the game

            timeLeft = 90;                  // Resets self-destruction timer

            player = main_cabin;            // Resets players location on the map back to the main cabin
        }

    }

    std::cout << "\n" << std::endl;


    do
    {

    std::cout     
    << "- - - - - - - - - - - - - \n"
    << "Space Escape Main Menu:\n"
    << "- - - - - - - - - - - - - \n"
    << "1. Play\n" 
    << "2. Exit"
    << std::endl;

    std::cin >> choice;

    if(inputValidation() == true)
    {
        if(choice < 0 || choice > 2)
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

    switch (choice)
    {
        case 1:
        {
            storySetup();                           // Displays main game play story to the user
            std::cout << "\n" << std::endl;

            this->player->menu->displayChoices();   // Displays the menu choices of the current room,
                                                    // which is main cabin by default in a new game
            break;
        }

        case 2:
        {
            break;
        }
    }
}


int Spaceship::getTimeLeft()
{
    return timeLeft;                // Returns value in member data
}


/*
    This method is called each time a user exits/enters a new room on the map.
    When called, it always first reduces the clock by 5 minutes. It then checks
    the value of the time. If it's 0, then it displays the self-destruct notification,
    calls the dead() method to let the main menu handler know the player died, and 
    calls the mainMenu() method to see if the user wants to replay the game. 
*/

void Spaceship::countdownTimer()
{
 
    timeLeft -=5;           // Reduces clock by 5 minutes

    if(timeLeft <=0 )
    {
        std::cout 
        << "*********************************************\n"
        << "*                                           *\n"
        << "*      Self Destruct Routine Initiated      *\n"
        << "*                                           *\n"
        << "*********************************************\n\n"

        << "A bright and noiseless flash fills your vision. Your life \n"
        << "flashes before your eyes and then darkness\n\n"

        << "You're dead and all of humanity is close behind - Try Again.\n"
        << std::endl;

        dead();
        mainMenu();
    }


    /*
        If the clock is > 0 after the reduction of 5 minutes, the user
        is displayed the updated countdown time.
    */
    else
    {
        std::cout 
        << "*********************************************\n"
        << "*                                           *\n"
        << "* The ship will self destruct in " << timeLeft << " minutes *\n"
        << "*                                           *\n"
        << "*********************************************\n"
        << std::endl;

    }

}


void Spaceship::dead()
{
    isDead = true;          // Sets flag to let the program/main menu know the  
                            // user has died and the game is over
}



void Spaceship::escaped()
{
    isEscaped = true;       // Sets flag to let the program/main menu know the
                            // user has escaped and the game is over
}

/*  
    This method is called once at the beginning of game play to setup the story
    for the user.
*/

void Spaceship::storySetup()
{
    std::cout << "\n" << std::endl;
    std::cout 
    << "Your an extraterrestrial biological engineer on a top-secret expedition \n"
    << "to Mars to extract recently discovered alien bacteria that will save the \n"
    << "human race from a terrible epidemic back on Earth. The mission is so top \n" 
    << "secret because the bacteria in the wrong hands become one of the most \n"
    << "deadly bio-warfare agent ever in existence.\n\n"

    << "The expedition is on a course back to Earth after a successful extraction \n"
    << "and everyone on the team but you are sleeping it off in the CREW QUARTERS. \n" 
    << "Suddenly you hear a loud explosion and the ships on-board AI computer comes \n" 
    << "over the intercom system...\n\n"

    << "Attention all crew members. A fatal explosion has occurred in the crew quarters. \n"
    << "Protocol 1-2-3A has commenced....\n\n"

    << "*********************************************\n"
    << "*                                           *\n"
    << "*                                           *\n"
    << "* The ship will self destruct in " << timeLeft << " minutes *\n"
    << "*                                           *\n"
    << "*                                           *\n"
    << "*********************************************\n\n"


    << "You've better get the alien bacteria and whatever other gear you need and \n"
    << "get in the ESCAPE POD before the ship explodes.\n\n"

    << "Your inventory can hold up to 6 items at a time.\n"
    << "Each time you enter or leave a room, the countdown time \n"
    << "reduces by 5 minutes. Navigate wisely and use the map often.\n"

    << std::endl;
}

/*
    This method deallocates all the memory for objects instantiated within the Spaceship class.
    It also resets the self-destruction timer to 90, and calls the inventory cleanup() method to
    let the inventory class know the game is over and it needs to deallocate and reset the vector
    inventory container and objects left in the list from the game that just ended.
*/
void Spaceship::cleanUp()
{

/* menu objects */

    delete mainCabinMenu;
    delete nav_menu;
    delete galley_menu; 
    delete science_lab_menu;
    delete equipment_menu;
    delete transportation_menu;
    delete escape_pod_menu;
    delete comms_menu;
    delete crew_quarters_menu;

    /* Module objects */

    delete main_cabin;
    delete navigation;
    delete galley;
    delete science_lab;
    delete equipment;
    delete transportation;
    delete escape_pod;
    delete comms;
    delete crew_quarters;

    /* Inventory Objects */
    delete inventory1;

    /*  Countdown rest */
    timeLeft = 90;

    /* Call inventory to clean up flags and memory allocations */
    inventory1->cleanUp();


}

