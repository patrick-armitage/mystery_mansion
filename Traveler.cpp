/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Room methods file which defines the methods of the
** Room class that were prototyped within the GameBoard header file
*******************************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include "Traveler.hpp"
#include "Utils.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Room
    Function Parameters: Room's name string
    What the function does: initializes a new instance of the Room class,
                            setting room name and also setting stillAlive
                            boolean to true
*/
Traveler::Traveler(string name) {
    setTravelerName(name);
    setPreviousRoom(NULL);
    setCurrentRoom(NULL);
    inventory = new vector<TREASURES>;
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: setRoomType, setRoomName
                    getRoomType, getRoomName
    Functions' Parameters: setters use corresponding values of data members
    What the functions do: getters and setters which act as public options to
                           read/write the Room class's private attribute methods
*/
void Traveler::setTravelerName(string name) {
    travelerName = name;
}

void Traveler::setPreviousRoom(Room *room) {
    previousRoom = room;
}

void Traveler::setCurrentRoom(Room *room) {
    currentRoom = room;
}

string Traveler::getTravelerName() {
    return travelerName;
}

Room *Traveler::getPreviousRoom() {
    return previousRoom;
}

Room *Traveler::getCurrentRoom() {
    return currentRoom;
}

vector<TREASURES> *Traveler::getInventory() {
    return inventory;
}

void Traveler::addInventoryItem(TREASURES item) {
    vector<TREASURES> *inv = getInventory();
    inv->push_back(item);
}

void Traveler::updateInventory(Mansion *mansion, Room *room) {
    ROOM_TYPE type = room->getRoomType();

    if (type == SECRET) {
        Secretroom *sRoom = getSecretRoom(mansion, room->getRoomName());

        if (sRoom->getTreasureFound() == false) {
            addInventoryItem(sRoom->getTreasure());
            sRoom->setTreasureFound(true);
        }
    } else if (type == PUZZLE) {
        Puzzleroom *pRoom = getPuzzleRoom(mansion, room->getRoomName());

        if (pRoom->getPuzzleSolved() == false) {
            addInventoryItem(pRoom->getTreasure());
            pRoom->setPuzzleSolved(true);
        }
    } else if (type == HIDDEN) {
        Hiddenroom *hRoom = getHiddenRoom(mansion, room->getRoomName());

        if (hRoom->getTreasureFound() == false) {
            addInventoryItem(hRoom->getTreasure());
            hRoom->setTreasureFound(true);
        }
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: tryAttack
    Function Parameters: attacking and defending Rooms' pointers
    What the function does: gets the two rooms' types and name strings, and
                            before executing the attack roll, checks the types
                            to see if there are any special cases occurring.
                            If the type is Medusa, we must check to see if she
                            will glare, and if type is Vampire, the vamp may
                            charm the opponent
*/
void Traveler::useInventoryItem(Mansion *mansion, Room *room) {
    vector<TREASURES> *inv = getInventory();
    if (inv->size() == 0) {
        cout << "\n" << getTravelerName() << " has no items yet in the inventory!\n\n";
        return;
    }

    TREASURES item = selectInventoryItem();
    useItemInRoom(mansion, room, item);
}

TREASURES Traveler::selectInventoryItem() {
    vector<TREASURES> *inv = getInventory();
    int selection;
    char sel;

    cout << endl;
    for (int i = 0; i < inv->size(); i++) {
        cout << "[" << i + 1 << "] " << getTreasureName(inv->at(i)) << "\n";
    }

    cin >> sel;
    selection = sel - '0';
    while ((selection < 1) || (selection > inv->size())) {
        cout << "That's not an item in your inventory, " << getTravelerName() << "!  Try again: ";
        cin >> sel;
        selection = sel - '0';
    }

    return inv->at(selection - 1);
}

void Traveler::useItemInRoom(Mansion *mansion, Room *room, TREASURES item) {
    ROOM_TYPE type = room->getRoomType();
    string name = room->getRoomName();
    bool specialDescription = false;

    if (type == PUZZLE) {
        Puzzleroom *pRoom = getPuzzleRoom(mansion, name);
        bool solved = pRoom->getPuzzleSolved();

        if (solved == false) {
            bool correctItem = (item == pRoom->getCorrectItem());
            bool wrongItem = (item == pRoom->getWrongItem());

            if (correctItem == true) {
                specialDescription = true;
                updateInventory(mansion, room);
            } else if (wrongItem == true) {
                pRoom->describeWrongItem();
                return;
            }
        }
    } else if (type == PASSAGEWAY) {
        Passagewayroom *wRoom = getPassagewayRoom(mansion, name);
        bool revealed = wRoom->getPassageRevealed();

        if (revealed == false) {
            bool correctItem = (item == wRoom->getCorrectItem());

            if (correctItem == true) {
                specialDescription = true;
                wRoom->setPassageRevealed(true);
            }
        }
    } else if ((name == "Grand Foyer") && (item == KEY)) {
        Outsideroom *oRoom = getOutsideRoom(mansion, "Outside");
        cout << getItemSpecialDescription(item);
        oRoom->setIsLocked(false);
        return;
    }

    if (specialDescription == true) {
        cout << getItemSpecialDescription(item);
    } else {
        cout << getItemRegularDescription(item);
    }
}
