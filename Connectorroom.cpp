/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Connectorroom methods file which defines the methods of the
** die class that were prototyped within the Connectorroom header file
*******************************************************************************/

#include <iostream>
#include <string>
#include "Connectorroom.hpp"

using std::cout;
using std::endl;

/*--------------------------------------------------------------------------------*/
/*
    Function Name: Connectorroom
    Function Parameters: creature's name string
    What the function does: initializes a new instance of the Connectorroom subclass,
                            setting its roomType to CONNECTOR
*/
Connectorroom::Connectorroom(string name) : Room(name) {
    setRoomType(CONNECTOR);
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: describe
    Function Parameters: n/a
    What the function does: pure virtual function that prints description
*/
void Connectorroom::describe() {
    string description = getDescription();
    cout << description << endl;
}

/*--------------------------------------------------------------------------------*/
/*
    Function Name: checkRoom
    Function Parameters: n/a
    What the function does: pure virtual function that prints generic message and
                            returns false
*/
bool Connectorroom::checkRoom() {
    cout << "\nJust a big empty room...  Nothing to see here!\n\n";
    return false;
}
