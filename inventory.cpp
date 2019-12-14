/************************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

Implementation file for the Inventory class. This class. 

This class is responsible for holding list of items the user adds to
their inventory during gameplay. It uses a vector container to hold 
pointers of the item objects instantiated within the menu objects.

The Inventory class also includes several methods that help manage the
list throughout gameplay, such as adding/removing items, resetting bool
flags so that Spaceship class knows which items the user has when inter-
acting with other elements in the game and memory deallocation of the 
objects instantiated on the heap (by menu functions) via pointers. The class
also handles the deallocation of all remaining item objects in the inventory
by accessing the objects through the pointers in the vector container when
the destructor is called.

*****************************************************************************/

#include "inventory.hpp"
#include "spaceship.hpp"

#include <vector>



/*
    ***** Item Key *****

    1.  Spacesuit
    2.  Empty DTU
    22. Full DTU
    3.  Six digit code
    4.  Alien bacteria
    5.  Empty STU
    55. Full STU
    6.  Take off sequence
    7.  Holo Radio
    8.  Lab rat
*/

Inventory::Inventory(Spaceship * theConnectedSpaceship)
{
    count = 0;                      // Holds the number of items in inventory at any given time
    inventorySize = 6;              // Maximum number of items that can be carried
    listCount = 1;                  // counter of current number of items. Set 1 to account for first item add


    mySpaceship = theConnectedSpaceship;

/* Sets all item flags to false at beginning of the game */

    hasDTUempty = false;
    hasDTUfull = false;
    hasSpacesuit = false;
    hasCode = false;
    hasAlienBacteria = false;
    hasSTUempty = false;
    hasSTUfull = false;
    hasTakeOffSequence = false;
    hasHoloRadio = false;
    hasLabRat = false;
}


/*
    This method checks to see if the user has a specific item in their inventory.
    It accepts the Item ID passed from the menu object of the room the user 
    is in, and then runs a loop on the vector to check each element's ID number
    for a matching number. If the item is found, the bool 'hasItem' is set to 
    true, otherwise the method returns false.
*/

bool Inventory::hasItem(int id)                                             // Argument is of item ID to check for
{   
    bool hasItem = false;                                                   // Set to false by default 

    /* Code source: http://www.cplusplus.com
    /reference/vector/vector/cbegin/ */

    for (auto iter = inventory.cbegin(); iter != inventory.cend(); ++iter)  // Loop w/ iter through vector array
    {
        if ((*iter)->getItemID() == id)                                     // If element in vector has a matching item ID
        {
            hasItem = true;                                                 // Set bool to true
        }                                        
    }

    return hasItem;                                                         // Return bool value

}


/*
    This method displays all the current items in the users inventory when called.
    It also checks if there are no items and displays an appropriate message.
*/

void Inventory::displayInventory()
{
     if(inventory.empty())                      // Check if list has any items to display
     {
        std::cout << "You have no items.\n"
        << std::endl;
     }
     else
     {
        for (auto iter = inventory.cbegin(); iter != inventory.cend(); ++iter)      // Loop w/ iter through vector array
        {
            std::cout << listCount <<". "       // Display each item in inventory
            << (*iter)->getItemName()           // Dereference and call method for name of item in element
            << std::endl;   
            
            listCount++;                        // Accumulator to display num next to each item for menu selection                                        

        }
        std::cout << '\n';
        listCount = 1;                          // Reset the list count 
     }
}

/*
    This method checks if hte current inventory list is full by checking
    the count against the inventorySize value. It returns a bool value.
*/

bool Inventory::isFull()
{
    if (count >= inventorySize)
        return true;
    else
        return false;
}



/*
    This method is called to add an item to the inventory vector list. It accepts
    as an argument a pointer to an Item type, so it can accept any derived item 
    class of Item. It checks to make sure there is room in the vector, and adds 
    the item to the back of the list if it's not full.

    The method also calls the addItemFlag() method and passes the current item's
    ID number to set the bool flag that lets the rest of the program know the 
    user has this item in their inventory (vs. running a full loop check each time)
*/

void Inventory::addItem(Item * i)
{
    if (count >= inventorySize)                         // Flag to keep user from adding more that alloted size of inventory
    {
        std::cout 
        << "You have no more room to hold items. \n"
        << "Consider dropping an item from inventory."
        << std::endl;
    }
    else
    {

        std::cout << "Added " << i->getItemName() 
        << " to inventory." "\n\n";
        this->inventory.push_back(i);           // Add an item to the vector

        addItemFlag(i->getItemID());

        count++;                                // Keeps track of how many elements are allowed to be added
    }

    
}

/*
    This method removes a specific type of item from the inventory list. This method
    is used in other menu objects to replace upgraded versions of the same item.

    The method accepts the items ID number, iterates through the loop to find the 
    item, sets a temp pointer to the item object, removes that item from the vector
    deallocate that item object from memory via the temporary pointer and then calls
    the resetItemFlag() method that updates the bool flag so the program knows the user
    no longer has that item in their inventory. 
*/

void Inventory::removeItem(int id)                      // Used behind the scenes - not user initiated
{
    int indexCounter = 0;                               // Used for index reference later in function 

    for (auto iter = inventory.begin(); iter != inventory.end(); ++iter)      // Loop w/ iter through vector array
    {
        if ((*iter)->getItemID() == id)                 // If element has item ID passed through argument 
        {
            
            Item *temp = inventory.at(indexCounter);    // Pointer to object to be removed from vector list

            inventory.erase (iter);                     // Remove item at iter

            resetItemFlag(temp);                        // Reset items bool

            delete temp;                                // deallocate memory of object that was just removed from the vector list

            count--;                                    // Adjusts counter

            
        }                                        
        indexCounter++;                                 // Add to counter for each iteration to track index
    };
}

/* 
    This method sets item flags to TRUE for the item ID number that is passed as an argument. 
*/

void Inventory::addItemFlag(int id)
{
    switch(id)
    {
        case 1:
            hasSpacesuit = true;
            break;

        case 2: 
            hasDTUempty = true;
            break;

        case 22:
            hasDTUfull = true;
            break;

        case 3:
            hasCode = true;
            break;

        case 4:
            hasAlienBacteria = true;
            break;

        case 5:
            hasSTUempty = true;
            break;

        case 55:
            hasSTUfull = true;
            mySpaceship->alienBactra_inEscapePod = true;        // Sets special flag that program checks at end of 
                                                                // gameplay to confirm a full win 
            break;

        case 6:
            hasTakeOffSequence = true;
            break;

        case 7:
            hasHoloRadio = true;
            break;

        case 8:
            hasLabRat = true;
            break;

    }

}

/*
    This method is called to reset the bool flag when an item is removed from inventory. 
    It also handles user messages to help the user understand that an item was removed
    from their inventor and where they can find it again in the game. 
*/

void Inventory::resetItemFlag(Item * i)
{
    int itemID;

    itemID = i->getItemID();            // Set's variable from dereferenced pointer


    switch(itemID)                  
    {
        case 1:
        {
            hasSpacesuit = false;
            
            std::cout << "\n"; 
            std::cout << "You return your spacesuit to the pods \n"
            << "in the equipment room and lock it up.\n\n"
            << "You take a moment to reflect on the great pride you \n"
            << "you take in following procedure, but your moment is \n"
            << "quickly interrupted by some violent turbulence in the ship.\n\n"
            << "Time to get your head in the game\n"
            << std::endl;

        }
        break;

        case 2:
        {
            if(hasDTUfull == false)
            {
                std::cout
                << "You place the Data Transfer Unit back in the tech officer's \n"
                << "backpack. He'll never know you took it.\n\n"
                << std::endl;
            }


            hasDTUempty = false;
        }
        break;

        case 22:
        {
            hasDTUfull = false;
            
            if(mySpaceship->player->getInEscapePod() == false)          // Checks if the user is in the escape pod room when item removed
            {
                std::cout << "\n";
                std::cout
                << "You place the Data Transfer Unit back in the tech officer's \n" 
                << "backpack. As you slip it inside the backpack, you accidentally \n"
                << "hit the delete button, wiping clean the flight plans you downloaded.\n"
                << "You wonder out loud why you bothered to wake up this morning.\n\n"
                << std::endl;
            }



        }
        break;

        case 3:
        {  
            hasCode = false;
            
            std::cout << "\n"; 
            std::cout 
            << "It just seems to make sense to you to put the code \n"
            << "back on your flight chair in the Navigation room for \n"
            << "safe keeping.\n"
            << std::endl;

        }
        break;

        case 4:
            hasAlienBacteria = false;
            break;

        case 5:
            {
                hasSTUempty = false;

                if(hasSTUfull == false)
                {
                    std::cout << "\n";
                    std::cout 
                    << "You place the Specimen Transfer Unit back in the plasma charger. \n"
                    << "It would be a tragedy if the unit ran out of power.\n\n"
                    << std::endl;
                }

            }
            break;

        case 55:
            hasDTUfull = false;

            std::cout << "\n";
            std::cout 
            << "Even as you expel the bacteria into the trash vacuum and place \n"
            << "the STU back in the plasma charger, you can't help but think \n"
            << "what a bonehead move this is\n"
            << std::endl;

            mySpaceship->alienBactra_inEscapePod = false;
            break;

        case 6:
            hasTakeOffSequence = false;
            break;


        case 7:
           {
            hasHoloRadio = false;

            std::cout << "\n";
            std::cout 
            << "You place the holo radio back in the crew locker \n"
            << "you found it in. Your conscious is now clean.\n"
            << std::endl;
            
            break;
            
            }

        case 8:
        {
            hasLabRat = false;

            std::cout << "\n";
            std::cout 
            << "You release the lab rat and think to yourself, "" \n"
            << "there's plenty more where he came from."" \n"
            << std::endl;

        }


    }
}

/*
    This method displays to the user each item currently in the inventory vector 
    with a numerical menu reference for each. This allows the user to enter a number
    of the item they would like to remove from the inventory container.

    If no items are in the list when the method is called, the method checks and displays
    that message to the user.

    The method also deallocates the memory of the object removed from the vector container.
    If the item is needed again later in the game it is instantiated again. 
*/

void Inventory::findAndRemoveItem()
{
    int removeChoice = 0;
    int isValid = 0;

    if(!inventory.empty())                  // Checks if list is empty
    {
      
        do
        {
            std::cout << "Select which item you would like to remove: \n"
            << "Or enter 0 to cancel\n"
            << std::endl;

             displayInventory();          // Displays the current list of items in inventory 

             
             std::cin >> removeChoice;

             if(removeChoice > count || removeChoice < 0)
             {
              std::cout << "You must enter a number for "
              << " an item in your inventory" << std::endl;
             }
             else
             {
              isValid = 1;
             }
        } 
        while(isValid == 0);

        if(removeChoice != 0)                                           // If the user didn't cancel the routine
        {
            
            Item *temp = inventory.at(removeChoice-1);                  // Pointer to object to be removed from vector list

            inventory.erase (inventory.begin() + removeChoice-1);       // accounts for users choice -1 to get
                                                                        // the right index value
                                                                        
            resetItemFlag(temp);                                        // Resets item bool value

            delete temp;                                                // deleted object that was just removed
                                                                        //from the vector list

            count--;                                                    // Reduces current count of items in the list

            std::cout << '\n';

            std::cout << "Removed item...\n"
            << "Accessing inventory...\n" 
            << std::endl;

            displayInventory();                                         // Re-displays list of items currently in inventory
        }

    }
    else
    {
        std::cout << "No items to remove\n"
        << std::endl;
    }

}

/*
    This method is called after a game is over to reset all the item flags to false
    and deletes all the elements in the inventory container. This allows for a seamless
    transition to a repeat game.
*/

void Inventory::cleanUp()
{
    inventory.clear();

    hasDTUempty = false;
    hasDTUfull = false;
    hasSpacesuit = false;
    hasCode = false;
    hasAlienBacteria = false;
    hasSTUempty = false;
    hasSTUfull = false;
    hasTakeOffSequence = false;
    hasHoloRadio = false;
    hasLabRat = false;
    
}

/*
    This destructor iterates through the vector, deallocates the memory to
    an items in the list, and then destroys the entire list
*/

Inventory::~Inventory()
{

   for (int i = 0; i < inventory.size(); ++i)
   {
    delete inventory[i];
   }
   inventory.clear();
}








