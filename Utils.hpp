/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description:
*******************************************************************************/

#include <string>

#ifndef UTILS_HPP
#define UTILS_HPP

using std::string;

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#define MAX     999

enum TREASURES { KEY, SHOTGUN, BIRDSEED };

void timedMessage(string message, int time);
string getTreasureName(TREASURES treasure);
string getItemRegularDescription(TREASURES treasure);
string getItemSpecialDescription(TREASURES treasure);
string getKeyRegularDescription();
string getKeySpecialDescription();
string getShotgunRegularDescription();
string getShotgunSpecialDescription();
string getBirdseedRegularDescription();
string getBirdseedSpecialDescription();

#endif
