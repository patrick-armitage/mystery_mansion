#include <iostream>
#include "Room.hpp"
#include "Traveler.hpp"
#include "Map.hpp"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    Mansion *mansion = createMansion();
    Traveler *trav = new Traveler("Pete");

    cout << "Welcome, " << trav->getTravelerName() << " to MYSTERY MANSION!" << endl << endl;
    printGameIntro();

    changeRoom(trav, getGrandFoyer(mansion));
    timedMessage("You walk through the front door, and...\n\n", 500000);
    timedMessage("BANG!!!!\n\n", 800000);
    timedMessage("The door has slammed shut behind you!\n", 500000);
    timedMessage("You try to open it...locked!\n\n", 700000);

    while (trav->getCurrentRoom()->getRoomType() != OUTSIDE) {
        if (trav->getCurrentRoom() != trav->getPreviousRoom()) {
            trav->getCurrentRoom()->describe();
        }
        displayRoomOptions(mansion, trav);
    }

    return 0;
}
