/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Secretroom methods file which defines the methods of the
** die class that were prototyped within the Secretroom header file
*******************************************************************************/

#include <iostream>
#include <string>
#include "Secretroom.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

/*--------------------------------------------------------------------------------*/
/*
    Function Name: Secretroom
    Function Parameters: creature's name string
    What the function does: initializes a new instance of the Secretroom subclass,
                            setting its type, strengthPts, armorPts, attackDieSides,
                            numAttackDice, and numDefenseDice to Secretroom defaults
*/
Secretroom::Secretroom(string name) : Room(name) {
    setRoomType(SECRET);
    setTreasureFound(false);
}

void Secretroom::setDiscovered(bool disc) {
    discovered = disc;
}

void Secretroom::setTreasureFound(bool found) {
    treasureFound = found;
}

void Secretroom::setSecretDescription(string desc) {
    secretDescription = desc;
}

void Secretroom::setSecretChoice(string choice) {
    secretChoice = choice;
}

void Secretroom::setTreasureDescription(string desc) {
    treasureDescription = desc;
}

void Secretroom::setTreasure(TREASURES t) {
    treasure = t;
}

bool Secretroom::getDiscovered() {
    return discovered;
}

bool Secretroom::getTreasureFound() {
    return treasureFound;
}

TREASURES Secretroom::getTreasure() {
    return treasure;
}

string Secretroom::getSecretDescription() {
    return secretDescription;
}

string Secretroom::getSecretChoice() {
    return secretChoice;
}

string Secretroom::getTreasureDescription() {
    return treasureDescription;
}


/*--------------------------------------------------------------------------------*/
/*
    Function Name: describe
    Function Parameters: n/a
    What the function does:
*/
void Secretroom::describe() {
    if (getDiscovered() == false) {
        string msg = "You've discovered a secret room!!!!  The " + getRoomName() + "!\n";
        cout << YELLOW << msg << RESET;
        setDiscovered(true);
    }

    string description = getDescription();
    cout << description << endl;

    if (getTreasureFound() == false) {
        printf(GREEN "This room looks like it has a lot of interesting things in it!\n\n" RESET);
    }
}

bool Secretroom::checkRoom() {
    if (getTreasureFound() == false) {
        cout << getSecretDescription();
        bool choice = makeSecretChoice();
        return choice;
    } else {
        cout << "\nLooks like there's nothing else in the " << getRoomName();
        cout << " that needs checking out!\n\n";
    }

    return false;
}

bool Secretroom::makeSecretChoice() {
    int selection;
    cout << "What do you want to do?\n";
    cout << "[1] " << getSecretChoice() << "\n";
    cout << "[2] Go back to menu\n";

    cin >> selection;
    while ((selection < 1) || (selection > 2)) {
        cout << "That's not one of the options!!  Try again: ";
        cin >> selection;
    }

    if (selection == 1) {
        discoverSecret();
        return true;
    }

    return false;
}

void Secretroom::discoverSecret() {
    cout << getTreasureDescription();
}
