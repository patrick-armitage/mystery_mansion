/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Connectorroom class prototypes, which inherit all data members,
** getters and setters from the Room base class, and implements the virtual
** functions attack, defend, charm and updateStrengthPts, and the constructor
*******************************************************************************/

#include <string>
#include "Room.hpp"

#ifndef CONNECTORROOM_HPP
#define CONNECTORROOM_HPP

using std::string;

class Connectorroom : public Room {
 public:
    Connectorroom(string name);
    void describe();
    bool checkRoom();
};

#endif
