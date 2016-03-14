/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Room methods file which defines the methods of the
** Room class that were prototyped within the GameBoard header file
*******************************************************************************/

#include <string>
#include <iostream>
#include "Room.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Room
    Function Parameters: Room's name string
    What the function does: initializes a new instance of the Room class,
                            setting room name and also setting stillAlive
                            boolean to true
*/
Room::Room(string name) {
    setRoomName(name);
    setVisited(false);
    setAllRooms(NULL, NULL, NULL, NULL);
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: setRoomType, setRoomName
                    getRoomType, getRoomName
    Functions' Parameters: setters use corresponding values of data members
    What the functions do: getters and setters which act as public options to
                           read/write the Room class's private attribute methods
*/
void Room::setRoomType(ROOM_TYPE type) {
    roomType = type;
}

void Room::setRoomName(string name) {
    roomName = name;
}

void Room::setAllRooms(Room *north, Room *west, Room *south, Room *east) {
    setNorthRoom(north);
    setWestRoom(west);
    setSouthRoom(south);
    setEastRoom(east);
}

void Room::setNorthRoom(Room *room) {
    northRoom = room;
}

void Room::setWestRoom(Room *room) {
    westRoom = room;
}

void Room::setSouthRoom(Room *room) {
    southRoom = room;
}

void Room::setEastRoom(Room *room) {
    eastRoom = room;
}

void Room::setDescription(string desc) {
    description = desc;
}

void Room::setVisited(bool v) {
    visited = v;
}

ROOM_TYPE Room::getRoomType() {
    return roomType;
}

string Room::getRoomName() {
    return roomName;
}

Room *Room::getNorthRoom() {
    return northRoom;
}

Room *Room::getWestRoom() {
    return westRoom;
}

Room *Room::getSouthRoom() {
    return southRoom;
}

Room *Room::getEastRoom() {
    return eastRoom;
}

string Room::getDescription() {
    return description;
}

bool Room::getVisited() {
    return visited;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: tryAttack
    Function Parameters: attacking and defending Rooms' pointers
    What the function does: gets the two rooms' types and name strings, and
                            before executing the attack roll, checks the types
                            to see if there are any special cases occurring.
                            If the type is Medusa, we must check to see if she
                            will glare, and if type is Vampire, the vamp may
                            charm the opponent
*/
