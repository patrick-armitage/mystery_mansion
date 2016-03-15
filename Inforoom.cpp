/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Inforoom methods file which defines the methods of the
** die class that were prototyped within the Inforoom header file
*******************************************************************************/

#include <iostream>
#include <string>
#include "Inforoom.hpp"

using std::cout;
using std::cin;
using std::endl;

/*--------------------------------------------------------------------------------*/
/*
    Function Name: Inforoom
    Function Parameters: creature's name string
    What the function does: initializes a new instance of the Inforoom subclass,
                            setting its type, strengthPts, armorPts, attackDieSides,
                            numAttackDice, and numDefenseDice to Inforoom defaults
*/
Inforoom::Inforoom(string name) : Room(name) {
    setRoomType(INFO);
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: setInfoDescription, setInfoChoice, setInfo, getInfoDescription,
                    getInfochoice, getInfo
    Functions' Parameters: setters use corresponding values of data members
    What the functions do: getters and setters which act as public options to
                           read/write the Inforoom class's private attribute methods
*/
void Inforoom::setInfoDescription(string description) {
    infoDescription = description;
}

void Inforoom::setInfoChoice(string choice) {
    infoChoice = choice;
}

void Inforoom::setInfo(string i) {
    info = i;
}

string Inforoom::getInfoDescription() {
    return infoDescription;
}

string Inforoom::getInfoChoice() {
    return infoChoice;
}

string Inforoom::getInfo() {
    return info;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: describe
    Function Parameters: n/a
    What the function does: prints generic message that player can learn info,
                            then prints description and returns
*/
void Inforoom::describe() {
    cout << "This room is a dead end, you can go back if you like, ";
    cout << "but perhaps you may just learn some new info." << endl << endl;

    string description = getDescription();
    cout << description << endl;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: checkRoom
    Function Parameters: n/a
    What the function does: pure virtual function that prints description and
                            presents user the choice to investigate information,
                            then returns false
*/
bool Inforoom::checkRoom() {
    cout << getInfoDescription();

    makeInfoChoice();

    return false;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: makeInfoChoice
    Function Parameters: n/a
    What the function does: presents user with option to investigate info or return
                            to main menu.  If they select to investigate, prints
                            info description, else does nothing
*/
void Inforoom::makeInfoChoice() {
    int selection;
    char sel;
    cout << "What do you want to do?\n";
    cout << "[1] " << getInfoChoice() << "\n";
    cout << "[2] Go back to menu\n";

    cin >> sel;
    selection = sel - '0';
    while ((selection < 1) || (selection > 2)) {
        cout << "That's not one of the options!!  Try again: ";
        cin >> sel;
        selection = sel - '0';
    }

    if (selection == 1) {
        cout << getInfo() << endl;
    }
}
