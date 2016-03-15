/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Passagewayroom methods file which defines the methods of the
** die class that were prototyped within the Passagewayroom header file
*******************************************************************************/

#include <iostream>
#include <string>
#include "Passagewayroom.hpp"

using std::cout;
using std::endl;

/*--------------------------------------------------------------------------------*/
/*
    Function Name: Passagewayroom
    Function Parameters: creature's name string
    What the function does: initializes a new instance of the Passagewayroom subclass,
                            setting its type, strengthPts, armorPts, attackDieSides,
                            numAttackDice, and numDefenseDice to Passagewayroom defaults
*/
Passagewayroom::Passagewayroom(string name) : Room(name) {
    setRoomType(PASSAGEWAY);
    setPassageRevealed(false);
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: setPassageRevealed, setPassageDescription, setCorrectItem, setHiddenRoom
                    getPassageRevealed, getPassageDescription, getCorrectItem, getHiddenRoom
    Functions' Parameters: setters use corresponding values of data members
    What the functions do: getters and setters which act as public options to
                           read/write the Passagewayroom class's private attribute methods
*/
void Passagewayroom::setPassageRevealed(bool revealed) {
    passageRevealed = revealed;
}

void Passagewayroom::setPassageDescription(string desc) {
    passageDescription = desc;
}

void Passagewayroom::setCorrectItem(TREASURES item) {
    correctItem = item;
}

void Passagewayroom::setHiddenRoom(Room *h) {
    hidden = h;
}

bool Passagewayroom::getPassageRevealed() {
    return passageRevealed;
}

string Passagewayroom::getPassageDescription() {
    return passageDescription;
}

TREASURES Passagewayroom::getCorrectItem() {
    return correctItem;
}

Room *Passagewayroom::getHiddenRoom() {
    return hidden;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: describe
    Function Parameters: n/a
    What the function does: prints description, and if passage revealed is false,
                            prints yellow message suggesting the room is hiding
                            something
*/
void Passagewayroom::describe() {
    string description = getDescription();
    cout << description << endl;

    if (getPassageRevealed() == false) {
        printf(YELLOW "\nThis room seems rather ordinary, except...  maybe it's hiding something...\n" RESET);
    }
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: checkRoom
    Function Parameters: n/a
    What the function does: pure virtual function.  If passage revealed is false,
                            prints passage description, else prints generic message
                            saying the room is no longer hiding anything
*/
bool Passagewayroom::checkRoom() {
    if (getPassageRevealed() == false) {
        cout << getPassageDescription();
    } else {
        cout << "Doesn't seem like there's anything else this room is hiding anymore...\n";
    }

    return false;
}
