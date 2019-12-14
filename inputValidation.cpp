/**********************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December 2019
** Description: 

This utility method checks to see if the user input is of 
a valid integer value. If the value in the buffer passes 
the validation, a true value is passed back to the calling
function to allow the main prog continue.

The first condition tests to see if cin has failed due to
the wrong type of data type being extracted. The statements
clear the cin and remove any other characters from the buffer

If the cin has NOT failed, the next statements clear out any
other characters outside of the extracted data type. It then
tests for the only accepted integers from the argument passed
through the function. If not an accepted value, return of 
false. Otherwise a return of true.

***************************************************************/


#include "inputValidation.hpp"
#include<iostream>
#include <string>

bool inputValidation()                        // passes additional value to be tested
{
    int boolValue;

    if(std::cin.fail())                     // Checks cin if failed
    {       
        std::cin.clear();                   // resets cin
        std::cin.ignore(32767, '\n');       // clears buffer
        std::cout << "--------------\n"; 
        std::cout << "Invalid input\n"; 
        std::cout << "--------------\n"; 
        boolValue = 0;   
    }  

    else 
    {
        std::cin.ignore(32767, '\n');       // clears buffer
        boolValue = 1;  
    }
    return boolValue;
}

