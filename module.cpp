/*********************************************************************
** Program name: Space Escape
** Author: Michael Cervoni
** Date: 10 December
** Description: 

**********THIS IS THE SPACE CLASS PER REQUIREMENTS*************

Implementation file for the base class Module.

*********************************************************************/

#include "module.hpp"

/*
    This boolean method returns the value of inEscapePod
    for each child class. The value is set within each 
    child's constructor and is only set to true for the
    escapePod. This was put into place to allow the program
    to identify if someone was in the escape pod during 
    gameplay. 
*/

bool Module::getInEscapePod()
{
    return inEscapePod;
}

void Module::room_description()
{

}
