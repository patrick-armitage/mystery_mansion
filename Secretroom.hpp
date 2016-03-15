/********************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Secretroom header file declaring the methods that will be defined
** within Secretroom.cpp
********************************************************************************/

#include <string>
#include "Utils.hpp"
#include "Room.hpp"

#ifndef SECRETROOM_HPP
#define SECRETROOM_HPP

using std::string;

class Secretroom : public Room {
 private:
    bool treasureFound;
    string secretDescription;
    string secretChoice;
    string treasureDescription;
    TREASURES treasure;
 public:
    Secretroom(string name);
    void setTreasureFound(bool found);
    void setSecretDescription(string description);
    void setSecretChoice(string secretChoice);
    void setTreasureDescription(string description);
    void setTreasure(TREASURES treasure);
    bool getTreasureFound();
    string getSecretDescription();
    string getSecretChoice();
    string getTreasureDescription();
    TREASURES getTreasure();
    void describe();
    bool checkRoom();
    bool makeSecretChoice();
    void discoverSecret();
};

#endif
