/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Outsideroom methods file which defines the methods of the
** die class that were prototyped within the Outsideroom header file
*******************************************************************************/

#include <iostream>
#include <string>
#include "Outsideroom.hpp"

using std::cout;
using std::endl;

/*--------------------------------------------------------------------------------*/
/*
    Function Name: Outsideroom
    Function Parameters: creature's name string
    What the function does: initializes a new instance of the Outsideroom subclass,
                            setting its type, strengthPts, armorPts, attackDieSides,
                            numAttackDice, and numDefenseDice to Outsideroom defaults
*/
Outsideroom::Outsideroom(string name) : Room(name) {
    setRoomType(OUTSIDE);
    setIsLocked(true);
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: setIsLocked, getIsLocked
    Functions' Parameters: setters use corresponding values of data members
    What the functions do: getters and setters which act as public options to
                           read/write the Inforoom class's private attribute methods
*/
void Outsideroom::setIsLocked(bool locked) {
    isLocked = locked;
}

bool Outsideroom::getIsLocked() {
    return isLocked;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: describe
    Function Parameters: n/a
    What the function does: prints message that user made it outside
*/
void Outsideroom::describe() {
    cout << "Breathe the fresh air!  You've made it outside!!!!" << endl;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: checkRoom
    Function Parameters: n/a
    What the function does: returns false (dummy function)
*/
bool Outsideroom::checkRoom() {
    return false;
}
