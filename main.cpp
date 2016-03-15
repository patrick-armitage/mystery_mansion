#include <string>
#include <iostream>
#include "Room.hpp"
#include "Traveler.hpp"
#include "Map.hpp"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    /* Introduction */
    printGameIntro();
    cout << "Welcome to MYSTERY MANSION!" << endl << endl;

    string name;
    cout << "What is your name, traveler? ";
    cin >> name;

    while (name == "") {
        cout << "That's not your name!  Come on now, tell us your name! ";
        cin >> name;
    }

    /* Game Setup */
    Mansion *mansion = createMansion();
    Traveler *trav = new Traveler(name);

    changeRoom(trav, getGrandFoyer(mansion));
    timedMessage("You walk through the front door, and...\n\n", 500000);
    timedMessage("BANG!!!!\n\n", 800000);
    timedMessage("The door has slammed shut behind you!\n", 700000);
    timedMessage("You try to open it...locked!\n\n", 1000000);

    /* Game Loop */
    while (trav->getCurrentRoom()->getRoomType() != OUTSIDE) {
        if (trav->getCurrentRoom() != trav->getPreviousRoom()) {
            trav->getCurrentRoom()->describe();
        }
        displayRoomOptions(mansion, trav);
    }

    /* Game Ending */
    Room *outside = getOutside(mansion);
    outside->describe();

    return 0;
}
