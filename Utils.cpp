/*******************************************************************************
** Author: Patrick Armitage
** Date: 03/12/2016
** Description: Display functions file which defines the functions that were
** prototyped within the Display header file
*******************************************************************************/


#include <iostream>
#include <string>
#include "Utils.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*----------------------------------------------------------------------------*/
/*
    Function Name: timedMessage
    Function Parameters: message string, time int
    What the function does: prints supplied message, then calls usleep with
                            supplied wait time integer
*/
void timedMessage(string message, int waitTime) {
    cout << message;
    usleep(waitTime);
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: getTreasureName
    Function Parameters: treasure type enum
    What the function does: checks to see which TREASURES enum type the supplied
                            treasure param, returning its corresponding string
                            name, else returns Unknown Item
*/
string getTreasureName(TREASURES treasure) {
    if (treasure == SHOTGUN) {
        return "Shotgun";
    } else if (treasure == BIRDSEED) {
        return "Birdseed";
    } else if (treasure == KEY) {
        return "Key";
    }

    return "Unknown Item";
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: getItemRegularDescription, getItemSpecialDescription
    Functions' Parameters: treasure item enum
    What the functions do: checks treasure type to return corresponding function calls
                           for either that item's regular or special description
*/
string getItemRegularDescription(TREASURES item) {
    if        (item == KEY)      { return getKeyRegularDescription();
    } else if (item == SHOTGUN)  { return getShotgunRegularDescription();
    } else if (item == BIRDSEED) { return getBirdseedRegularDescription(); }

    return "Unknown regular description";
}

string getItemSpecialDescription(TREASURES item) {
    if        (item == KEY)      { return getKeySpecialDescription();
    } else if (item == SHOTGUN)  { return getShotgunSpecialDescription();
    } else if (item == BIRDSEED) { return getBirdseedSpecialDescription(); }

    return "Unknown special description";
}

/*---------------------------------------------------------------------------------------*/
/*
    Function Names: getKeyRegularDescription, getKeySpecialDescription
                    getShotgunRegularDescription, getShotgunSpecialDescription
                    getBirdseedRegularDescription, getBirdseedSpecialDescription
    Functions' Parameters: N/A
    What the functions do: returns string to corresponding item's regular or special description
*/
string getKeyRegularDescription() {
    const char *desc =
        "\nYou pull out the shiny golden key.  Surveying the room, it doesn't really look like "
        "it will fit into any of these locks.  I mean, this thing is pretty old school...\n";

    return string(desc, 0, MAX);
}

string getKeySpecialDescription() {
    const char *desc =
        "Heart beating fast, you pull out the golden Key and push it slowly into the front door \n"
        "lock.   It fits!!!\n\n" GREEN "Click!\n\n" RESET
        "It's open!  It's really open!  Finally you can get away from this nightmare mansion!!!!\n";

    return string(desc, 0, MAX);
}

string getShotgunRegularDescription() {
    const char *desc =
        "\nYou bust out the shotgun!  Ready...  aim...\n\n" RED "BLAMOOO!!!!!\n\n" RESET
        "You've just blasted both barrels!  Bits of shot go ricocheting around the room!\n\n"
        "As the smoke clears and the blast echoes die down, you gaze around the room.\n\n"
        "Nothing happened!\n";

    return string(desc, 0, MAX);
}

string getShotgunSpecialDescription() {
    const char *desc =
        "\nYou whip out your shotgun.  If nothing else, maybe you can at least silence that awful organ!\n"
        "You take direct aim at the organ...  Steady...  Steady...!\n\n"
        RED "KABLAAAAMO!!!!!\n\n" YELLOW "CLUMP CLUMP BAAANG!!!\n\n" RESET
        "You jump behind a heavy oak desk as pellets bounce everywhere off of the organ.  You \n"
        "heard a loud noise, maybe that silenced that awful instrument for good!\n\n"
        RED "*Organ continues to blare more awful Count Dracula-esque music*\n\n" RESET
        "Wait...  Guess not...  You get up from your crouched position behind the desk as the "
        "smoke clears...  Wait!\n\n"
        "A hatch door from the ceiling has fallen open and a rope ladder fell down!\n\n"
        YELLOW "A hidden room has been revealed!!!  " RESET "Let's go check it out!\n";

    return string(desc, 0, MAX);
}

string getBirdseedRegularDescription() {
    const char *desc =
        "\nYou pull out the sack of Birdseed, grab a handful, and scatter some over the floor.\n\n"
        "...You just made a big mess.  Let's hope 'His Lordship' doesn't find out about this...\n\n"
        "Nothing happened!\n";

    return string(desc, 0, MAX);
}

string getBirdseedSpecialDescription() {
    const char *desc =
        "\nAs you pull out the sack of Birdseed and stick your hand inside for a handful \n"
        "the Crows cease their cawing!  Perching their heads down at you with a greedy glance, \n"
        "they suddenly take flight en-masse and swoop down to the center of the Courtyard!\n\n"
        RED "Chirp, chirp!  Chirp, chirp, chirp!\n\n"
        MAGENTA "\"Boy, they sure sound a lot nicer when you're about to feed them...\"\n\n" RESET
        "As you toss birdseed out into the crowd of crows, they gobble it up as soon as it hits \n"
        "the ground.  While you're distracted by them, suddenly, a group of crows come behind you \n"
        "and stick their beaks into the Birdseed bag!\n\n"
        MAGENTA "\"Get away from there you scoundrels!!!\"\n\n" RESET
        "The crows explode away back into the tree, so forcefully they knock down their own nest!\n\n"
        "You walk over to see if any crow babies need help off the ground, but instead, woven \n"
        "into the sticks and hay of the nest, you see a golden Key sticking out!\n\n"
        GREEN "Added Key to the inventory!\n" RESET;

    return string(desc, 0, MAX);
}
