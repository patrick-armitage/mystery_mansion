/*********************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Outsideroom header file declaring the methods that will be defined
** within Outsideroom.cpp
*********************************************************************************/

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
