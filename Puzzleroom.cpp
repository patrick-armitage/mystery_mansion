/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Puzzleroom methods file which defines the methods of the
** die class that were prototyped within the Puzzleroom header file
*******************************************************************************/

#include <iostream>
#include <string>
#include "Puzzleroom.hpp"

using std::cout;
using std::endl;

/*--------------------------------------------------------------------------------*/
/*
    Function Name: Puzzleroom
    Function Parameters: creature's name string
    What the function does: initializes a new instance of the Puzzleroom subclass,
                            setting its type, strengthPts, armorPts, attackDieSides,
                            numAttackDice, and numDefenseDice to Puzzleroom defaults
*/
Puzzleroom::Puzzleroom(string name) : Room(name) {
    setRoomType(PUZZLE);
    setPuzzleSolved(false);
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: setPuzzleSolved, setPuzzleDescription, setWrongItem, setTreasure,
                    setCorrectItem, getPuzzleSolved, getPuzzleDescription, getWrongItem,
                    getTreasure, getCorrectItem
    Functions' Parameters: setters use corresponding values of data members
    What the functions do: getters and setters which act as public options to
                           read/write the Inforoom class's private attribute methods
*/
void Puzzleroom::setPuzzleSolved(bool solved) {
    puzzleSolved = solved;
}

void Puzzleroom::setPuzzleDescription(string desc) {
    puzzleDescription = desc;
}

void Puzzleroom::setCorrectItem(TREASURES item) {
    correctItem = item;
}

void Puzzleroom::setWrongItem(TREASURES item) {
    wrongItem = item;
}

void Puzzleroom::setTreasure(TREASURES t) {
    treasure = t;
}

bool Puzzleroom::getPuzzleSolved() {
    return puzzleSolved;
}

string Puzzleroom::getPuzzleDescription() {
    return puzzleDescription;
}

TREASURES Puzzleroom::getCorrectItem() {
    return correctItem;
}

TREASURES Puzzleroom::getWrongItem() {
    return wrongItem;
}

TREASURES Puzzleroom::getTreasure() {
    return treasure;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: describe
    Function Parameters: n/a
    What the function does: pure virtual function; prints description and, if puzzle
                            solved is false, prints magenta message saying there's
                            somethign going on with the room
*/
void Puzzleroom::describe() {
    string description = getDescription();
    cout << description << endl;

    if (getPuzzleSolved() == false) {
        printf(MAGENTA "\n\"There's something funny about this room, but I'm not quite sure what...\"\n\n" RESET);
    }
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: describeWrongItem
    Function Parameters: n/a
    What the function does: prints humorous message about the crows if wrong item
                            (shotgun) is used in the room
*/
void Puzzleroom::describeWrongItem() {
    cout << "Let's deal with these annoying crows once and for all!\n";
    cout << "Ready...  Aim...  FIRE!\n\n";
    const char *fire = RED "KABLAAAM!!!!!!!\n\n\n" RESET;
    timedMessage(string(fire, 0, 100), 1200000);

    const char *reaction = RED "Caw!  Caw!  Caw!  Caw!  Caw!  Caw!  Caw!  Caw!\n" RESET;
    for (int i = 0; i < 100; i++) {
        timedMessage(string(reaction, 0, 100), 30000);
    }

    const char *notAgain =
        MAGENTA "\n\n\nSheesh!!  Those blighters nearly pecked my head off!  \n"
        "Best not try that again...\n" RESET;
    timedMessage(string(notAgain, 0, 100), 700000);
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: checkRoom
    Function Parameters: n/a
    What the function does: pure virtual function; if puzzle solved is false,
                            prints puzzle description, else prints message that
                            there's nothing unusual, and returns false
*/
bool Puzzleroom::checkRoom() {
    if (getPuzzleSolved() == false) {
        cout << getPuzzleDescription();
    } else {
        cout << "Doesn't look like there's anything else here that's out of the ordinary!\n";
    }

    return false;
}
