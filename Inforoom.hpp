/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Inforoom header file declaring the methods that will be defined
** within Inforoom.cpp
*******************************************************************************/

#include <string>
#include "Room.hpp"

#ifndef INFOROOM_HPP
#define INFOROOM_HPP

using std::string;

class Inforoom : public Room {
 private:
    string infoDescription;
    string infoChoice;
    string info;
 public:
    Inforoom(string name);
    void setInfoDescription(string description);
    void setInfoChoice(string choice);
    void setInfo(string info);
    string getInfoDescription();
    string getInfoChoice();
    string getInfo();
    void describe();
    bool checkRoom();
    void makeInfoChoice();
};

#endif
