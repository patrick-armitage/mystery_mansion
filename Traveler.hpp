/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description:
*******************************************************************************/

#include <vector>
#include <string>
#include "Utils.hpp"
#include "Map.hpp"
#include "Room.hpp"

#ifndef TRAVELER_HPP
#define TRAVELER_HPP

using std::string;
using std::vector;

class Traveler {
 protected:
    string travelerName;
    Room *previousRoom;
    Room *currentRoom;
    vector<TREASURES> *inventory;
 public:
    Traveler(string travelerName);
    void setTravelerName(string travelerName);
    void setPreviousRoom(Room *prevRoom);
    void setCurrentRoom(Room *currRoom);
    string getTravelerName();
    Room *getPreviousRoom();
    Room *getCurrentRoom();
    vector<TREASURES> *getInventory();
    void addInventoryItem(TREASURES item);
    void updateInventory(Mansion *mansion, Room *room);
    void useInventoryItem(Mansion *mansion, Room *room);
    TREASURES selectInventoryItem();
    void useItemInRoom(Mansion *mansion, Room *room, TREASURES item);
};

#endif
