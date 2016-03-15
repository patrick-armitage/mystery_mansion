/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Room methods file which defines the methods of the
** Room class that were prototyped within the Room header file
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
                            setting room name and also setting visited
                            boolean to false and all rooms to NULL
*/
Room::Room(string name) {
    setRoomName(name);
    setVisited(false);
    setAllRooms(NULL, NULL, NULL, NULL);
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: setRoomType, setRoomName, setNorthRoom, setSouthRoom, setEastRoom,
                    setWestRoom, setDescription, setVisited,  getRoomType, getRoomName,
                    getNorthRoom, getSouthRoom, getEastRoom, getWestRoom, getDescription,
                    getVisited
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
