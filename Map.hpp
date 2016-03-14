/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description:
*******************************************************************************/

#include <string>
#include "Room.hpp"
#include "Connectorroom.hpp"
#include "Inforoom.hpp"
#include "Puzzleroom.hpp"
#include "Passagewayroom.hpp"
#include "Hiddenroom.hpp"
#include "Secretroom.hpp"
#include "Outsideroom.hpp"

#ifndef MAP_HPP
#define MAP_HPP

using std::string;

struct Mansion {
    Connectorroom *grandFoyer;
    Inforoom *billiardRoom;
    Connectorroom *greatHall;
    Puzzleroom *courtyard;
    Secretroom *armory;
    Passagewayroom *library;
    Hiddenroom *attic;
    Outsideroom *outside;
};

Mansion *createMansion();
void setMapAssociations(Mansion *mansion);
void setHiddenAssociations(Mansion *mansion);
Connectorroom *createGrandFoyer();
Inforoom *createBilliardRoom();
Connectorroom *createGreatHall();
Puzzleroom *createCourtyard();
Secretroom *createArmory();
Passagewayroom *createLibrary();
Hiddenroom *createAttic();
Outsideroom *createOutside();
Room *getGrandFoyer(Mansion *mansion);
Room *getBilliardRoom(Mansion *mansion);
Room *getGreatHall(Mansion *mansion);
Room *getCourtyard(Mansion *mansion);
Room *getArmory(Mansion *mansion);
Room *getLibrary(Mansion *mansion);
Room *getAttic(Mansion *mansion);
Room *getOutside(Mansion *mansion);
Puzzleroom *getPuzzleRoom(Mansion *mansion, string roomName);
Secretroom *getSecretRoom(Mansion *mansion, string roomName);
Passagewayroom *getPassagewayRoom(Mansion *mansion, string roomName);
Hiddenroom *getHiddenRoom(Mansion *mansion, string roomName);
Outsideroom *getOutsideRoom(Mansion *mansion, string roomName);

#endif
