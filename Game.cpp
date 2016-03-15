/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Game functions file which defines the functions that were
** prototyped within the Game header file
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
    Function Name: displayRoomOptions
    Function Parameters: mansion struct, traveler instance
    What the function does: gets current room and room type from traveler, then
                            iterates over all the menu options, prompting user
                            to select between checking current room, using
                            an inventory item, changing rooms and getting a clue.
                            Validates user input, forcing a selection between
                            1-4, then executes selection.  calls checkRoom on
                            room if user checks room, updating inventory if
                            user found an item.  Calls useInventoryItem when
                            user uses an item and giveClue when user asks for a clue
                            breaks selection loop when user opts to change room
                            and calls makeMove
*/
void displayRoomOptions(Mansion *mansion, Traveler *trav) {
    Room *room = trav->getCurrentRoom();
    ROOM_TYPE type = room->getRoomType();

    char sel;
    int selection;
    do {
        cout << "\nWhat do you want to do?\n";
        cout << "[1] Check out the " << room->getRoomName() << "\n";
        cout << "[2] Use an inventory item\n";
        cout << "[3] Move to another room\n";
        cout << "[4] Need a clue!\n";
        cin >> sel;
        selection = sel - '0';
        while ((selection < 1) || (selection > 4)) {
            cout << "Yo!  That isn't one of the options here!!  Let's try that again: ";
            cin >> sel;
            selection = sel - '0';
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
    Function Name: makeMove
    Function Parameters: mansion struct, traveler instance
    What the function does: calls getTravelChoice to get next room choice,
                            then checks to see if room is outside room, which
                            conditionally may be locked and the user may not
                            be able to change rooms.  Otherwise calls change room
                            with the next room selection
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
    Function Parameters: Traveler instance, next room pointer
    What the function does: gets the traveler and room name, and chckes to see
                            that the current room is not NULL, printing an
                            exit message if it isn't.  Then sets previousRoom
                            to current room and currentRoom to next room,
                            checking to see if next room has been visited.  If
                            not, prints a message saying traveler is entering
                            for the first time, else prints a message saying
                            traveler has returned to the room
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
    Function Name: getTravelChoice
    Function Parameters: mansion struct, traveler instance
    What the function does: gets the current room then checks each of its room
                            pointers, printing out options to move to each if
                            checkRoomRevealed returns true for each option,
                            then prompts user to make a selection, validating
                            selection lies within the bounds of available
                            choices, and returns the room pointer of the user's
                            selected choice
*/
Room *getTravelChoice(Mansion *mansion, Traveler *trav) {
    int selection, rmCount = 0;
    char sel;
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

    cin >> sel;
    selection = sel - '0';
    while ((selection < 1) || (selection > rmCount)) {
        cout << "Not a valid choice!  Please select one of the " << rmCount << " listed rooms: ";
        cin >> sel;
        selection = sel - '0';
    }

    return *(rooms + (selection-1));
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: checkRoomRevealed
    Function Parameters: mansion struct, current room pointer, check room pointer
    What the function does: checks to see if current room is passageway, then
                            checks to see if passageRevealed is false and whether
                            passageway's hidden room equals the check room,
                            returning false if it does, else returns true
*/
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

/*----------------------------------------------------------------------------*/
/*
    Function Name: giveClue
    Function Parameters: mansion struct, traveler instance
    What the function does: gets the traveler's inventory, then does a number
                            of checks to see "where they are at" in the course
                            of the game.  If outside is unlocked, message is
                            printed saying no clue necessary!  If user possesses
                            Key, clue is given asking them to use the key.
                            If user possess Birdseed, clue is given suggesting
                            someone may want the birdseed.  If user possesses
                            shotgun, clue is given urging them to use shotgun.
                            Otherwise, if inventory is empty, user is encouraged
                            to explore all the rooms.
*/
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

/*----------------------------------------------------------------------------*/
/*
    Function Name: printGameIntro
    Function Parameters: N/A
    What the function does: prints a cool ASCII art intro of the game for a
                            little eye candy before gameplay starts ;)
*/
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
