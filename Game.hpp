/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Game header file declaring the methods that will be defined
** within Game.cpp
*******************************************************************************/

#include <string>
#include "Room.hpp"
#include "Traveler.hpp"

#ifndef GAME_HPP
#define GAME_HPP

using std::string;

void displayRoomOptions(Mansion *mansion, Traveler *traveler);
void makeMove(Mansion *mansion, Traveler *traveler);
Room *getTravelChoice(Mansion *mansion, Traveler *traveler);
bool checkRoomRevealed(Mansion *mansion, Room *currRoom, Room *checkRoom);
void changeRoom(Traveler *traveler, Room *nextRoom);
void giveClue(Mansion *mansion, Traveler *traveler);
void printGameIntro();

#endif
