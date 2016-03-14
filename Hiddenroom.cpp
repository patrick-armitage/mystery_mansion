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
    Function Parameters: creature's name string
    What the function does: initializes a new instance of the Hiddenroom subclass,
                            setting its type, strengthPts, armorPts, attackDieSides,
                            numAttackDice, and numDefenseDice to Hiddenroom defaults
*/
Hiddenroom::Hiddenroom(string name) : Room(name) {
    setRoomType(HIDDEN);
    setHiddenRevealed(false);
    setTreasureFound(false);
}

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
    What the function does:
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

bool Hiddenroom::checkRoom() {
    if (getTreasureFound() == false) {
        cout << getTreasureDescription();
        return true;
    } else {
        cout << "Looks like we've already found everything in this hidden room!\n";
    }

    return false;
}
