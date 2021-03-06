/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Room header file declaring the methods that will be defined
** within Room.cpp.  Also defines ROOM_TYPE enum used throughout the game.
*******************************************************************************/

#include <stdio.h>
#include <string>
#include "Utils.hpp"

#ifndef ROOM_HPP
#define ROOM_HPP

using std::string;

enum ROOM_TYPE { CONNECTOR, INFO, PUZZLE, SECRET, PASSAGEWAY, HIDDEN, OUTSIDE };

class Room {
 protected:
    ROOM_TYPE roomType;
    string roomName;
    Room *northRoom;
    Room *westRoom;
    Room *southRoom;
    Room *eastRoom;
    string description;
    bool visited;
 public:
    Room(string roomName);
    void setRoomType(ROOM_TYPE);
    void setRoomName(string roomName);
    void setAllRooms(Room *north, Room *west, Room *south, Room *east);
    void setNorthRoom(Room *northRoom);
    void setWestRoom(Room *westRoom);
    void setSouthRoom(Room *southRoom);
    void setEastRoom(Room *eastRoom);
    void setDescription(string description);
    void setVisited(bool visited);
    ROOM_TYPE getRoomType();
    string getRoomName();
    Room *getNorthRoom();
    Room *getWestRoom();
    Room *getSouthRoom();
    Room *getEastRoom();
    string getDescription();
    bool getVisited();
    virtual void describe() = 0;
    virtual bool checkRoom() = 0;
};

#endif
