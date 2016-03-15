/********************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Puzzleroom header file declaring the methods that will be defined
** within Puzzleroom.cpp
********************************************************************************/

#include <string>
#include "Room.hpp"
#include "Utils.hpp"

#ifndef PUZZLEROOM_HPP
#define PUZZLEROOM_HPP

using std::string;

class Puzzleroom : public Room {
 private:
    bool puzzleSolved;
    string puzzleDescription;
    TREASURES correctItem;
    TREASURES wrongItem;
    TREASURES treasure;
 public:
    Puzzleroom(string name);
    void setPuzzleSolved(bool solved);
    void setPuzzleDescription(string description);
    void setCorrectItem(TREASURES item);
    void setWrongItem(TREASURES item);
    void setTreasure(TREASURES treasure);
    bool getPuzzleSolved();
    string getPuzzleDescription();
    TREASURES getCorrectItem();
    TREASURES getWrongItem();
    TREASURES getTreasure();
    void describe();
    void describeWrongItem();
    bool checkRoom();
};

#endif
