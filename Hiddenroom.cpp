/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Hiddenroom methods file which defines the methods of the
** die class that were prototyped within the Hiddenroom header file
*******************************************************************************/

#include <iostream>
#include <string>
#include "Hiddenroom.hpp"

using std::cout;
using std::endl;

/*--------------------------------------------------------------------------------*/
/*
    Function Name: Hiddenroom
    Function Parameters: room's name string
    What the function does: initializes a new instance of the Hiddenroom subclass,
                            setting its type to HIDDENROOM, revealed to false, and
                            treasure found to false
*/
Hiddenroom::Hiddenroom(string name) : Room(name) {
    setRoomType(HIDDEN);
    setHiddenRevealed(false);
    setTreasureFound(false);
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: setHiddenRevealed, setTreasure, setTreasureFound, setTreasureDescription,
                    getHiddenRevealed, getTreasure, getTreasureFound, getTreasureDescription
    Functions' Parameters: setters use corresponding values of data members
    What the functions do: getters and setters which act as public options to
                           read/write the Hiddenroom class's private attribute methods
*/
void Hiddenroom::setHiddenRevealed(bool revealed) {
    hiddenRevealed = revealed;
}

void Hiddenroom::setTreasure(TREASURES t) {
    treasure = t;
}

void Hiddenroom::setTreasureFound(bool found) {
    treasureFound = found;
}

void Hiddenroom::setTreasureDescription(string description) {
    treasureDescription = description;
}

bool Hiddenroom::getHiddenRevealed() {
    return hiddenRevealed;
}

TREASURES Hiddenroom::getTreasure() {
    return treasure;
}

bool Hiddenroom::getTreasureFound() {
    return treasureFound;
}

string Hiddenroom::getTreasureDescription() {
    return treasureDescription;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: describe
    Function Parameters: n/a
    What the function does: pure virtual function that prints description
*/
void Hiddenroom::describe() {
    if (getHiddenRevealed() == false) {
        printf(GREEN "You've discovered a hidden room, ");
        cout << "the " << getRoomName() << "!!!\n";
        printf("%s\n", RESET);
        setHiddenRevealed(true);
    }

    string description = getDescription();
    cout << description << endl;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: checkRoom
    Function Parameters: n/a
    What the function does: pure virtual function that prints treasure description
                            if treasure found is false and returns true, else prints
                            generic message saying everything is found and returns
                            false
*/
bool Hiddenroom::checkRoom() {
    if (getTreasureFound() == false) {
        cout << getTreasureDescription();
        return true;
    } else {
        cout << "Looks like we've already found everything in this hidden room!\n";
    }

    return false;
}
