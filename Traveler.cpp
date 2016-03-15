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
    Function Name: Traveler
    Function Parameters: Traveler's name string
    What the function does: initializes a new instance of the Traveler class,
                            setting traveler name and setting previous and current
                            rooms to NULL, and inventory to an empty TREASURES
                            vector
*/
Traveler::Traveler(string name) {
    setTravelerName(name);
    setPreviousRoom(NULL);
    setCurrentRoom(NULL);
    inventory = new vector<TREASURES>;
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: setTravelerName, setPreviousRoom, setCurrentRoom,
                    getTravelerName, getPreviousRoom, getCurrentRoom, getInventory
    Functions' Parameters: setters use corresponding values of data members
    What the functions do: getters and setters which act as public options to
                           read/write the Traveler class's private attribute methods
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

/*----------------------------------------------------------------------------*/
/*
    Function Name: addInventoryItem
    Function Parameters: treasure item enum
    What the function does: fetches traveler's current inventory, then calls
                            push_back on inventory with supplied item
*/
void Traveler::addInventoryItem(TREASURES item) {
    vector<TREASURES> *inv = getInventory();
    inv->push_back(item);
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: updateInventory
    Function Parameters: mansion struct, room pointer
    What the function does: gets room type, then does a series of checks to see
                            if room is SECRET, PUZZLE or HIDDEN, getting the
                            corresponding raw room object for each room type
                            and checking if treasure has already been found
                            in each room.  If not, adds treasure item to
                            inventory and sets treasure found to true for
                            that room
*/
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
    Function Name: useInventoryItem
    Function Parameters: mansion struct, room pointer
    What the function does: fetches traveler's current inventory, then checks to
                            ensure that inventory is not empty, printing a notice
                            and returning early if it is.  If not, calls
                            selectInventoryItem to get item selection from user,
                            and useItemInRoom with item to use the item
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

/*----------------------------------------------------------------------------*/
/*
    Function Name: selectInventoryItem
    Function Parameters: N/A
    What the function does: fetches traveler's current inventory, then prompts
                            user to select an item from the inventory, iterating
                            over each item and printing it as a menu option.
                            Validates user has made a correct selection, then
                            returns the treasure enum selection
*/
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

/*----------------------------------------------------------------------------*/
/*
    Function Name: useItemInRoom
    Function Parameters: mansion struct, room pointer, treasure enum
    What the function does: gets room type and name, then does a series of checks
                            to see if room is PUZZLE, PASSAGEWAY, or if current
                            room is the Grand Foyer.  If PUZZLE, checks to see
                            if item used is correct item or wrong item.  If correct,
                            returns true and updates inventory with found treasure.
                            If wrong, calls describeWrongItem on Puzzleroom.  If
                            PASSAGEWAY, checks to see if passage not is revealed and
                            correct item has been used, if true, returns true and
                            updates inventory with found treasure.  If Grand Foyer
                            and item is Key, unlocks the door to the outside and returns.
                            If specialDescription bool is true, prints specialDescription,
                            else prints regularDescription for item
*/
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
