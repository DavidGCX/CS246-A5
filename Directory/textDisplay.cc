#include "textDisplay.h"
#include <memory>
#include "player.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Initialize internal data
void TextDisplay::init() {
    cout << "Text Display Initializing" << endl;
}

void TextDisplay::printToScreen() {
    vector<string> s = display_player_card(1, "First Player", 20, 0);
    for (auto i : s) {
        cout << s;
    }
}

void TextDisplay::refresh(unique_ptr<Player>& playerOne, unique_ptr<Player>& playerTwo) {
    printToScreen();
}
