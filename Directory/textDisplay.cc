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

void TextDisplay::printTitle() {
    // vector<string> s = display_player_card(1, "First Player", 20, 0);
    // for (auto i : s) {
    //     cout << i;
    // }

    vector<string> center = CENTRE_GRAPHIC;
    for (auto i : center) {
        cout << i << endl;
    }
}

void TextDisplay::refresh(unique_ptr<Player>& playerOne, unique_ptr<Player>& playerTwo) {
    printTitle();
}
