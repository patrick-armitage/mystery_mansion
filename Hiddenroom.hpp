/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Hiddenroom class prototypes, which inherit all data members,
** getters and setters from the Room base class, and implements the virtual
** functions attack, defend, charm and updateStrengthPts, and the constructor
*******************************************************************************/

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
