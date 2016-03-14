/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Display functions file which defines the functions that were
** prototyped within the Display header file
*******************************************************************************/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include "Utils.hpp"
#include "Game.hpp"
#include "Room.hpp"
#include "Map.hpp"
#include "Traveler.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::find;
using std::vector;

/*----------------------------------------------------------------------------*/
/*
    Function Name: changeRoom
    Function Parameters:
    What the function does:
*/
void displayRoomOptions(Mansion *mansion, Traveler *trav) {
    Room *room = trav->getCurrentRoom();
    ROOM_TYPE type = room->getRoomType();

    if (type == OUTSIDE) {
        room->describe();
        return;
    }

    int selection;
    do {
        cout << "\nWhat do you want to do?\n";
        cout << "[1] Check out the " << room->getRoomName() << "\n";
        cout << "[2] Use an inventory item\n";
        cout << "[3] Move to another room\n";
        cout << "[4] Need a clue!\n";
        cin >> selection;
        while ((selection < 1) || (selection > 4)) {
            cout << "Yo!  That isn't one of the options here!!  Let's try that again: ";
            cin >> selection;
        }

        if (selection == 1) {
            bool newItem = room->checkRoom();

            if ((newItem == true) && (type == SECRET || type == HIDDEN)) {
                trav->updateInventory(mansion, room);
            }
        } else if (selection == 2) {
            trav->useInventoryItem(mansion, room);
        } else if (selection == 4) {
            giveClue(mansion, trav);
        }
    } while (selection != 3);

    makeMove(mansion, trav);
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: changeRoom
    Function Parameters:
    What the function does:
*/
void makeMove(Mansion *mansion, Traveler *trav) {
    Room *nextRm = getTravelChoice(mansion, trav);

    if (nextRm->getRoomType() == OUTSIDE) {
        Outsideroom *oRoom = getOutsideRoom(mansion, "Outside");

        if (oRoom->getIsLocked() == true) {
            cout << "\nYou try the door again...  Still locked!\n";
            trav->setPreviousRoom(trav->getCurrentRoom());
            return;
        }
    }
    changeRoom(trav, nextRm);
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: changeRoom
    Function Parameters:
    What the function does:
*/
void changeRoom(Traveler *trav, Room *nextRm) {
    string travName = trav->getTravelerName();
    string nextRmName = nextRm->getRoomName();
    if (trav->getCurrentRoom() != NULL) {
        cout << travName << " is now exiting ";
        cout << trav->getCurrentRoom()->getRoomName() << "..." << endl;
    }

    trav->setPreviousRoom(trav->getCurrentRoom());
    trav->setCurrentRoom(nextRm);

    if (nextRm->getVisited() == false) {
        nextRm->setVisited(true);
        cout << travName << " is entering the " << nextRmName;
        cout << " for the first time.  The door creaks as it swings open...\n\n";
    } else {
        cout << travName << " reenters the " << nextRmName;
        cout << "...  Looks like not much has changed.\n\n";
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: changeRoom
    Function Parameters:
    What the function does:
*/
Room *getTravelChoice(Mansion *mansion, Traveler *trav) {
    int selection, rmCount = 0;
    Room *currRm = trav->getCurrentRoom();
    Room *rooms[4];
    Room *temp;

    cout << "\nOkay " << trav->getTravelerName() << ", where do you want to go?" << endl;
    if (currRm->getNorthRoom() != NULL) {
        temp = currRm->getNorthRoom();

        if (checkRoomRevealed(mansion, currRm, temp) == true) {
            *(rooms + rmCount) = temp;
            rmCount++;
            cout << "[" << rmCount << "] NORTH - The " << temp->getRoomName() << endl;
        }
    }
    if (currRm->getWestRoom() != NULL) {
        temp = currRm->getWestRoom();

        if (checkRoomRevealed(mansion, currRm, temp) == true) {
            *(rooms + rmCount) = temp;
            rmCount++;
            cout << "[" << rmCount << "] WEST - The " << temp->getRoomName() << endl;
        }
    }
    if (currRm->getEastRoom() != NULL) {
        temp = currRm->getEastRoom();

        if (checkRoomRevealed(mansion, currRm, temp) == true) {
            *(rooms + rmCount) = temp;
            rmCount++;
            cout << "[" << rmCount << "] EAST - The " << temp->getRoomName() << endl;
        }
    }
    if (currRm->getSouthRoom() != NULL) {
        temp = currRm->getSouthRoom();

        if (checkRoomRevealed(mansion, currRm, temp) == true) {
            *(rooms + rmCount) = temp;
            rmCount++;
            cout << "[" << rmCount << "] SOUTH - The " << temp->getRoomName() << endl;
        }
    }

    cin >> selection;
    while ((selection < 1) || (selection > rmCount)) {
        cout << "Not a valid choice!  Please select one of the " << rmCount << " listed rooms: ";
        cin >> selection;
    }

    return *(rooms + (selection-1));
}

bool checkRoomRevealed(Mansion *mansion, Room *currRm, Room *checkRm) {
    bool revealed = true;

    if (currRm->getRoomType() == PASSAGEWAY) {
        Passagewayroom *wRoom = getPassagewayRoom(mansion, currRm->getRoomName());

        if ((wRoom->getPassageRevealed() == false) && (wRoom->getHiddenRoom() == checkRm)) {
            revealed = false;
        }
    }

    return revealed;
}

void giveClue(Mansion *mansion, Traveler *trav) {
    vector<TREASURES> *inv = trav->getInventory();
    const char *msg;

    Outsideroom *oRoom = getOutsideRoom(mansion, "Outside");
    if (oRoom->getIsLocked() == false) {
        cout << "What do you need a clue for?  You're home free, buster!  \n";
        cout << "You can finally escape this miserable madhouse!!!\n";
        return;
    }

    if (!inv->empty()) {
        if (find(inv->begin(), inv->end(), KEY) != inv->end()) {
            msg =
                "Now you've got this golden Key!  There must be a locked door around here \n"
                "you can " YELLOW "use it in!\n" RESET;
            cout << msg;
        } else if (find(inv->begin(), inv->end(), BIRDSEED) != inv->end()) {
            msg =
                "Well, there's this bag of Birdseed you've been holding onto...\n"
                "Doesn't anybody " YELLOW "want this stuff?\n" RESET;
            cout << msg;
        } else if (find(inv->begin(), inv->end(), SHOTGUN) != inv->end()) {
            msg =
                "We found this awesome Shotgun!  Don't you think that "
                YELLOW "shooting it at something \n" RESET
                "could possibly lead us to the next clue?\n";
            cout << msg;
        }
    } else {
        msg =
            "You haven't looked around here much, maybe you could start by "
            YELLOW "checking all the rooms.\n\n"
            MAGENTA "\"I gotta get outta here somehow!...\"\n" RESET;
        cout << msg;
    }
}

void printGameIntro() {
    // ASCII art borrowed gratefully from http://ascii.co.uk/art/mansion
    const char *intro =
        BLUE "               *         .              *            _.---._\n"
        "                             ___   .            ___.'       '.   *\n"
        "        .              _____[LLL]______________[LLL]_____     \\\n"
        "                      /     [LLL]              [LLL]     \\     |\n"
        "                     /____________________________________\\    |    .\n"
        "                      )==================================(    /\n"
        "     .      *         '|I .-. I .-. I .--. I .-. I .-. I|'  .'\n"
        "                  *    |I |+| I |+| I |. | I |+| I |+| I|-'`       *\n"
        "                       |I_|+|_I_|+|_I_|__|_I_|+|_I_|+|_I|      .\n"
        "              .       /_I_____I_____I______I_____I_____I_\\\n"
        "                       )================================(   *\n"
        "       *         _     |I .-. I .-. I .--. I .-. I .-. I|          *\n"
        "                |u|  __|I |+| I |+| I |<>| I |+| I |+| I|    _         .\n"
        "           __   |u|_|uu|I |+| I |+| I |~ | I |+| I |+| I| _ |U|     _\n"
        "       .  |uu|__|u|u|u,|I_|+|_I_|+|_I_|__|_I_|+|_I_|+|_I||n|| |____|u|\n"
        "          |uu|uu|_,.-' /I_____I_____I______I_____I_____I\\`'-. |uu u|u|__\n"
        "          |uu.-'`      #############(______)#############    `'-. u|u|uu|\n"
        "         _.'`              ~\"^\"~   (________)   ~\"^\"^~           `'-.|uu|\n"
        "      ,''          .'    _                             _ `'-.        `'-.\n"
        "  ~\"^\"~    _,'~\"^\"~    _( )_                         _( )_   `'-.        ~\"^\"~\n"
        "      _  .'            |___|                         |___|      ~\"^\"~     _\n"
        "    _( )_              |_|_|          () ()          |_|_|              _( )_\n"
        "    |___|/\\/\\/\\/\\/\\/\\/\\|___|/\\/\\/\\/\\/\\|| ||/\\/\\/\\/\\/\\|___|/\\/\\/\\/\\/\\/\\/\\|___|\n"
        "    |_|_|\\/\\/\\/\\/\\/\\/\\/|_|_|\\/\\/\\/\\/\\/|| ||\\/\\/\\/\\/\\/|_|_|\\/\\/\\/\\/\\/\\/\\/|_|_|\n"
        "    |___|/\\/\\/\\/\\/\\/\\/\\|___|/\\/\\/\\/\\/\\|| ||/\\/\\/\\/\\/\\|___|/\\/\\/\\/\\/\\/\\/\\|___|\n"
        "    |_|_|\\/\\/\\/\\/\\/\\/\\/|_|_|\\/\\/\\/\\/\\/[===]\\/\\/\\/\\/\\/|_|_|\\/\\/\\/\\/\\/\\/\\/|_|_|\n"
        "    |___|/\\/\\/\\/\\/\\/\\/\\|___|/\\/\\/\\/\\/\\|| ||/\\/\\/\\/\\/\\|___|/\\/\\/\\/\\/\\/\\/\\|___|\n"
        "    |_|_|\\/\\/\\/\\/\\/\\/\\/|_|_|\\/\\/\\/\\/\\/|| ||\\/\\/\\/\\/\\/|_|_|\\/\\/\\/\\/\\/\\/\\/|_|_|\n"
        "    |___|/\\/\\/\\/\\/\\/\\/\\|___|/\\/\\/\\/\\/\\|| ||/\\/\\/\\/\\/\\|___|/\\/\\/\\/\\/\\/\\/\\|___|\n"
        "~\"\"~|_|_|\\/\\/\\/\\/\\/\\/\\/|_|_|\\/\\/\\/\\/\\/|| ||\\/\\/\\/\\/\\/|_|_|\\/\\/\\/\\/\\/\\/\\/|_|_|~\"\"~\n"
        "   [_____]            [_____]                       [_____]            [_____]\n" RESET;
    cout << intro;
    cout << endl << endl << endl;
}
