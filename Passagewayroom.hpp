/************************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Passagewayroom header file declaring the methods that will be defined
** within Passagewayroom.cpp
************************************************************************************/

#include <string>
#include "Room.hpp"
#include "Hiddenroom.hpp"
#include "Utils.hpp"

#ifndef PASSAGEWAYROOM_HPP
#define PASSAGEWAYROOM_HPP

using std::string;

class Passagewayroom : public Room {
 private:
    bool passageRevealed;
    string passageDescription;
    TREASURES correctItem;
    Room *hidden;
 public:
    Passagewayroom(string name);
    void setPassageRevealed(bool revealed);
    void setPassageDescription(string description);
    void setCorrectItem(TREASURES item);
    void setHiddenRoom(Room *hidden);
    bool getPassageRevealed();
    string getPassageDescription();
    TREASURES getCorrectItem();
    Room *getHiddenRoom();
    void describe();
    bool checkRoom();
};

#endif
