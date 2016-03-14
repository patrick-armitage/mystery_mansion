/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Inforoom class prototypes, which inherit all data members,
** getters and setters from the Room base class, and implements the virtual
** functions attack, defend, charm and updateStrengthPts, and the constructor
*******************************************************************************/

#include <string>
#include "Room.hpp"

#ifndef OUTSIDEROOM_HPP
#define OUTSIDEROOM_HPP

using std::string;

class Outsideroom : public Room {
 private:
    bool isLocked;
 public:
    Outsideroom(string name);
    void setIsLocked(bool locked);
    bool getIsLocked();
    void describe();
    bool checkRoom();
};

#endif
