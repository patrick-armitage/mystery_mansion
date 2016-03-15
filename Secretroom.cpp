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
    Function Parameters: room's name string
    What the function does: initializes a new instance of the Secretroom subclass,
                            setting room type to SECRET and treasure found to false
*/
Secretroom::Secretroom(string name) : Room(name) {
    setRoomType(SECRET);
    setTreasureFound(false);
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: setTreasureFound, setSecretDescription, setSecretChoice, setTreasure,
                    setTreasureDescription, getTreasureFound, getSecretDescription, getSecretChoice,
                    getTreasure, getTreasureDescription
    Functions' Parameters: setters use corresponding values of data members
    What the functions do: getters and setters which act as public options to
                           read/write the Secretroom class's private attribute methods
*/
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
    What the function does: pure virtual function; prints description and, if treasure
                            found is false, prints green message saying there are
                            interesting things in the room
*/
void Secretroom::describe() {
    string description = getDescription();
    cout << description << endl;

    if (getTreasureFound() == false) {
        printf(GREEN "This room looks like it has a lot of interesting things in it!\n\n" RESET);
    }
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: checkRoom
    Function Parameters: n/a
    What the function does: pure virtual function; if treasure found is false,
                            prints secret description, and prompts user to make
                            secret choice, returning choice, else prints message
                            that there's nothing else here, and returns false
*/
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

/*--------------------------------------------------------------------------------*/
/*
    Function Name: makeInfoChoice
    Function Parameters: n/a
    What the function does: presents user with option to investigate secret or return
                            to main menu.  If they select to investigate, prints
                            secret description and prompts user with secret choice
                            menu, and if they press further, calls discoverSecret
                            and returns true, else returns false
*/
bool Secretroom::makeSecretChoice() {
    int selection;
    char sel;
    cout << "What do you want to do?\n";
    cout << "[1] " << getSecretChoice() << "\n";
    cout << "[2] Go back to menu\n";

    cin >> sel;
    selection = sel - '0';
    while ((selection < 1) || (selection > 2)) {
        cout << "That's not one of the options!!  Try again: ";
        cin >> sel;
        selection = sel - '0';
    }

    if (selection == 1) {
        discoverSecret();
        return true;
    }

    return false;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: discoverSecret
    Function Parameters: n/a
    What the function does: prints treasure description
*/
void Secretroom::discoverSecret() {
    cout << getTreasureDescription();
}
