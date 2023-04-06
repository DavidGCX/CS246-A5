#include <iostream>
#include <sstream>
#include "player.h"
using namespace std;

int main(int argc, const char** argv) {
    bool testmode = false;
    for (int i = 1; i < argc; ++i)
    if (argv[i] == "-deck1") {
        // set player 1 deck to file from deck1
        cout << "-deck1" << endl;
        ++i;
    } else if (argv[i] == "-deck2") {
        // set player 2 deck to file from deck2
        cout << "-deck2" << endl;
        ++i;
    } else if (argv[i] == "-init") {
        // take file, use as input
        fstream f{argv[i+1]};
        istringstream s{f};
        string name;
        s >> name;
        // player 1 init
        s >> name;
        // player 2 init
        // play everything in the file. Don't wait for other args. Not like you'd put testing after init but yeah
        cout << "-init" << endl;
        ++i;
    } else if (argv[i] == "-testing") {
        testmode = true;
        // set a bool for testing before activation
        // useAbility() should always return true
        // maybe grab the magic cost from the item you're using, compare, then manually add enough to do it if too low

        // in controller, use the bool to determine if the switch case / if statements should check for discard and draw commands

        // bool is to determine if shuffling or not
        cout << "-testing" << endl;
    } else if (argv[i] == "-graphics") {
        // enable the graphics display
        cout << "-graphics" << endl;
    }
    return 0;
}
