/*********************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Hiddenroom header file declaring the methods that will be defined
** within Hiddenroom.cpp
*********************************************************************************/

#include <string>
#include "Room.hpp"
#include "Utils.hpp"

#ifndef HIDDENROOM_HPP
#define HIDDENROOM_HPP

using std::string;

class Hiddenroom : public Room {
 private:
    bool hiddenRevealed;
    TREASURES treasure;
    bool treasureFound;
    string treasureDescription;
 public:
    Hiddenroom(string name);
    void setHiddenRevealed(bool revealed);
    void setTreasure(TREASURES treasure);
    void setTreasureFound(bool found);
    void setTreasureDescription(string description);
    bool getHiddenRevealed();
    TREASURES getTreasure();
    bool getTreasureFound();
    string getTreasureDescription();
    void describe();
    bool checkRoom();
};

#endif
