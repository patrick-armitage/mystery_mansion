/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Display functions file which defines the functions that were
** prototyped within the Display header file
*******************************************************************************/

#include <iostream>
#include <string>
#include "Utils.hpp"
#include "Map.hpp"
#include "Room.hpp"
#include "Connectorroom.hpp"
#include "Inforoom.hpp"
#include "Puzzleroom.hpp"
#include "Passagewayroom.hpp"
#include "Hiddenroom.hpp"
#include "Secretroom.hpp"
#include "Outsideroom.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*----------------------------------------------------------------------------*/
/*
    Function Name: createMansion
    Function Parameters: N/A
    What the function does:
*/
Mansion *createMansion() {
    Mansion *mansion = new Mansion;

    mansion->grandFoyer = createGrandFoyer();
    mansion->billiardRoom = createBilliardRoom();
    mansion->greatHall = createGreatHall();
    mansion->courtyard = createCourtyard();
    mansion->armory = createArmory();
    mansion->library = createLibrary();
    mansion->attic = createAttic();
    mansion->outside = createOutside();

    setMapAssociations(mansion);
    setHiddenAssociations(mansion);
    return mansion;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: createMansion
    Function Parameters: N/A
    What the function does:
*/
void setMapAssociations(Mansion *mansion) {
    Room *grandFoyer = getGrandFoyer(mansion);
    Room *billiardRoom = getBilliardRoom(mansion);
    Room *greatHall = getGreatHall(mansion);
    Room *courtyard = getCourtyard(mansion);
    Room *armory = getArmory(mansion);
    Room *library = getLibrary(mansion);
    Room *attic = getAttic(mansion);
    Room *outside = getOutside(mansion);

    /* Set Grand Foyer associations */
    grandFoyer->setNorthRoom(greatHall);
    grandFoyer->setEastRoom(billiardRoom);
    grandFoyer->setSouthRoom(outside);

    /* Set Billiard Room associations */
    billiardRoom->setWestRoom(grandFoyer);

    /* Set Great Hall associations */
    greatHall->setSouthRoom(grandFoyer);
    greatHall->setWestRoom(courtyard);
    greatHall->setNorthRoom(armory);
    greatHall->setEastRoom(library);

    /* Set Court Yard associations */
    courtyard->setEastRoom(greatHall);

    /* Set Armory associations */
    armory->setSouthRoom(greatHall);

    /* Set Library associations */
    library->setWestRoom(greatHall);
    library->setEastRoom(attic);

    /* Set Attic associations */
    attic->setWestRoom(library);

    /* Set Outside associations */
    outside->setNorthRoom(grandFoyer);
}

void setHiddenAssociations(Mansion *mansion) {
    Passagewayroom *library = getPassagewayRoom(mansion, "Library");
    Room *attic = getAttic(mansion);

    library->setHiddenRoom(attic);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: create functions
    Function Parameters: N/A
    What the function does: creates the room its function name suggestions,
                            populating it with any special functionality
*/
Connectorroom *createGrandFoyer() {
    Connectorroom *grandFoyer = new Connectorroom("Grand Foyer");
    const char *description =
        "You have entered the Grand Foyer!\n"
        "It smells MUSTY in here!  There are marble columns everywhere, and a large OAK DOOR\n"
        "to the north of you.  To the east, there is a smaller door that is GREEN in color.\n";
    grandFoyer->setDescription(string(description, 0, MAX));

    return grandFoyer;
}

Inforoom *createBilliardRoom() {
    Inforoom *billiardRoom = new Inforoom("Billiard Room");
    const char *description =
        "You are now in the Billiard Room!  Care for a game?\n"
        "It's pretty dark...  Lots of hanging lights and pool tables everywhere.\n"
        "The room is filled with faint smoke vapors, and there are glasses clinking somewhere...\n";
    billiardRoom->setDescription(string(description, 0, MAX));
    const char *infoDescription =
        "Nothing to see here except rows of pool tables"
        " covered in dank hanging incandescent lights...\n"
        "Wait...  In the dark corner, there gleam a row of wooden barstools,\n"
        " and a Bartender is mixing drinks...\n\n";
    billiardRoom->setInfoDescription(string(infoDescription, 0, MAX));
    billiardRoom->setInfoChoice("Talk to the Bartender");
    const char *info =
        "\nAs you approach the Bartender, he looks up at you, greasy locks of hair falling over his eyes.\n"
        "He has on a desheveled shirt and slacks with suspenders, he's a little on the big-boned side.\n\n"
        CYAN "\"Hey there laddie, welcome to the Mystery Pub!  Can I fetch you something to drink?  Ey?\"\n\n" RESET
        "He reaches for a glass and starts polishing it, then looks around somewhat furtively.\n\n"
        CYAN "\"You must be mighty wary round this old house, lad.  There be troublers about.\n"
        "Take for instances those gaggling gawkheads in the Courtyard!  The lot o' them!\n"
        "I could swear one of them stole something important from His Lordship...\n\n"
        "Er...  But that's only me drink talking!  GYAHAHAA!!!\"\n\n" RESET;
    billiardRoom->setInfo(string(info, 0, MAX));

    return billiardRoom;
}

Connectorroom *createGreatHall() {
    Connectorroom *greatHall = new Connectorroom("Great Hall");
    const char *description =
        "So this must be the famous Great Hall!\n"
        "There are dazzling crystal chandelliers hanging on the long ceiling down the corridor.\n"
        "The lights are on and burning brightly, but there isn't a single soul in sight!\n"
        "Strangely, there is faint organ music playing in the background.  Weird...\n\n"
        "To the west, there is a large with bright sunlight streaming underneath.\n"
        "At the north end of the hallway, there is a large metal door with rings for handles.\n"
        "To the east, there is an ornate door with a fancy hand-carved handle, very nice!\n";
    greatHall->setDescription(string(description, 0, MAX));

    return greatHall;
}

Puzzleroom *createCourtyard() {
    Puzzleroom *courtyard = new Puzzleroom("Courtyard");
    const char *description =
        RED "Caw!  Caw!  Caw!  Caw!  Caw!  Caw!\n\n" RESET
        "Circling overhead are dozens of Crows!  They fly and perch amidst a great oak tree in \n"
        "the center of the courtyard.  As you look around, the only things in sight are stone \n"
        "benches and walls and windows.  Behind you lies the only door in the yard.  It's very \n"
        "pretty and all, but...  nothing much here except these obnoxious crows!\n\n"
        RED "Caw!  Caw!  Caw!  Caw!  Caw!  Caw!\n" RESET;
    courtyard->setDescription(string(description, 0, MAX));
    const char *puzzleDescription =
        "As you stand there, staring blankly into the sky, you suddenly realize that the crows \n"
        "aren't just making bird calls...  There's a bit of english in there too!!\n\n"
        RED "Caw!  Caw!  Caw!  Caw!  Caw!  Stole it!\n"
        "Caw!  Caw!  From His Lordship!  Caw!  Caw!  Caw!\n"
        "Caw!  His precious treasure!  Caw!  Caw!  Caw!  Caw!\n"
        "Yes!  Caw!  We!  Caw!  Did! Caw! Caw!\n\n" RESET
        MAGENTA "\"I wonder what on earth they're going on about...\"\n" RESET;
    courtyard->setPuzzleDescription(string(puzzleDescription, 0, MAX));
    courtyard->setCorrectItem(BIRDSEED);
    courtyard->setWrongItem(SHOTGUN);
    courtyard->setTreasure(KEY);

    return courtyard;
}

Secretroom *createArmory() {
    Secretroom *armory = new Secretroom("Armory");
    armory->setDiscovered(true);

    const char *description =
        "As you walk into the armory, you are greeted with an array of all things combat and war\n"
        "related of every kind.  Hanging on the wall, there are various forms of taxidermy, including\n"
        "the heads of deceased elk, deer, tigers, panthers and even, strangely, a hippopatomus.\n\n"
        MAGENTA "\"Woah...  Gross!\"\n\n" RESET
        "There are also every kind of weapons and armor from every imaginable era hanging on the wall,\n"
        "Including a large double-headed battleax, and a full plate-mail with a hinged shutting helmet!\n\n"
        MAGENTA "\"That's straight up medieval!...\"\n\n" RESET
        "As you scan the room for anything useful, it appears everything is securely locked in cages\n"
        "or bolted down.  Go figure!\n";
    armory->setDescription(string(description, 0, MAX));
    const char *secretDescription =
        "Strolling around the room, you turn knobs on cabinets and check locks on cages... it appears\n"
        "nothing is accessible.  It makes sense, why would they leave weapons lying around!\n\n"
        "You come up to an old, stained wooden chest.  The latch is locked, no luck here...\n\n"
        "...Wait a second...  Fiddling with the lid, it seems the latch is about to fall apart...\n\n";
    armory->setSecretDescription(string(secretDescription, 0, MAX));
    armory->setSecretChoice("Try to force the lid open");
    const char *treasureDescription =
        "You pull the lid up hard!...\n\n" MAGENTA "\"Urrrrgh!\"\n\n" RESET "No luck!\n"
        "Hmmm...  This thing won't budge.  You're not just going to stand here and keep pulling at it.\n"
        "Fed up, you throw the chest a swift kick before walking away!\n\n"
        MAGENTA "*KICK*\n\n" YELLOW "*POP*\n\n" RESET "Gasp!  The lid has popped open!!\n"
        "Inside lies a large, dark, gleaming " YELLOW "SHOTGUN!!\n\n" RESET
        GREEN "Added Shotgun to Inventory!!\n\n" RESET;
    armory->setTreasureDescription(string(treasureDescription, 0, MAX));
    armory->setTreasure(SHOTGUN);

    return armory;
}

Passagewayroom *createLibrary() {
    Passagewayroom *library = new Passagewayroom("Library");
    library->setCorrectItem(SHOTGUN);
    const char *description =
        "As you enter the attic, you discover the source of that strange organ music!\n"
        "In the center of the room sits a giant brass organ, the keys move by themselves.  Spooky!\n\n"
        RED "It's blaring that awful music so loud it's deafening!!!\n\n" RESET
        "You scan the room for anything interesting...  Looks like just a bunch of walls filled \n"
        "top to bottom with old, dusty books!\n";
    library->setDescription(string(description, 0, MAX));
    const char *passageDescription =
        "You look around the library, trying to avoid that freaky self-playing brass organ...\n\n"
        "Nothing!  Nothing but books!...  And the organ...  Wait...  what's that handle on the ceiling?\n";
    library->setPassageDescription(string(passageDescription, 0, MAX));

    return library;
}

Hiddenroom *createAttic() {
    Hiddenroom *attic = new Hiddenroom("Attic");
    const char *description =
        "You pull your way up the last rung of the ladder to discover a dark, dusty attic!\n\n"
        MAGENTA "*COUGH* *COUGH*\n\n" "\"Ick, asbestos!\"\n\n" RESET
        "It's hard to tell what is in the attic, it's so dark.  You'll have to feel your way \n"
        "around to see if anything else is there!\n";
    attic->setDescription(string(description, 0, MAX));
    const char *treasureDescription =
        "As you feel your way around the dark attic, it doesn't seem like there's much here \n"
        "except for a bunch of dried out rat droppings!\n\n" MAGENTA "\"Ewwww...\"\n\n" RESET
        "Wait...  Looks like we've found something!  A big bag filled with...  Birdseed!\n\n"
        GREEN "Added Birdseed to Inventory!!\n\n" RESET;
    attic->setTreasureDescription(string(treasureDescription, 0, MAX));
    attic->setTreasure(BIRDSEED);

    return attic;
}

Outsideroom *createOutside() {
    Outsideroom *outside = new Outsideroom("Outside");

    return outside;
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: getter functions
    Function Parameters: N/A
    What the function does: creates the room its function name suggestions,
                            populating it with any special functionality
*/
Room *getGrandFoyer(Mansion *mansion) {
    Connectorroom *grandFoyer = mansion->grandFoyer;

    return grandFoyer;
}

Room *getBilliardRoom(Mansion *mansion) {
    Inforoom *billiardRoom = mansion->billiardRoom;

    return billiardRoom;
}

Room *getGreatHall(Mansion *mansion) {
    Connectorroom *greatHall = mansion->greatHall;

    return greatHall;
}

Room *getCourtyard(Mansion *mansion) {
    Puzzleroom *courtyard = mansion->courtyard;

    return courtyard;
}

Room *getArmory(Mansion *mansion) {
    Secretroom *armory = mansion->armory;

    return armory;
}

Room *getLibrary(Mansion *mansion) {
    Passagewayroom *library = mansion->library;

    return library;
}

Room *getAttic(Mansion *mansion) {
    Hiddenroom *attic = mansion->attic;

    return attic;
}

Room *getOutside(Mansion *mansion) {
    Outsideroom *outside = mansion->outside;

    return outside;
}

Puzzleroom *getPuzzleRoom(Mansion *mansion, string roomName) {
    if (roomName == "Courtyard") {
        return mansion->courtyard;
    }

    return NULL;
}

Secretroom *getSecretRoom(Mansion *mansion, string roomName) {
    if (roomName == "Armory") {
        return mansion->armory;
    }

    return NULL;
}

Passagewayroom *getPassagewayRoom(Mansion *mansion, string roomName) {
    if (roomName == "Library") {
        return mansion->library;
    }

    return NULL;
}

Hiddenroom *getHiddenRoom(Mansion *mansion, string roomName) {
    if (roomName == "Attic") {
        return mansion->attic;
    }

    return NULL;
}

Outsideroom *getOutsideRoom(Mansion *mansion, string roomName) {
    if (roomName == "Outside") {
        return mansion->outside;
    }

    return NULL;
}
