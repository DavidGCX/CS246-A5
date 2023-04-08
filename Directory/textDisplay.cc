#include "textDisplay.h"
#include <memory>
#include "player.h"
#include "minion.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Initialize internal data
void TextDisplay::init() {
    cout << "Text Display Initializing" << endl;
}

void TextDisplay::printRow(const vector<vector<string>>& v) {
    for (int i=0; i<NUM_LINES; i++) {
        cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
        for (auto block : v) {
            cout << block.at(i);
        }
        cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
        cout << endl;
    }
}

void TextDisplay::printTopBorder() {
    cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for (int i=0; i<NUM_CHARS; i++) {
        cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT;
    cout << endl;
}

void TextDisplay::printBottomBorder() {
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for (int i=0; i<NUM_CHARS; i++) {
        cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT;
    cout << endl;
}

void TextDisplay::printBoard(unique_ptr<Player>& playerOne, unique_ptr<Player>& playerTwo) {
    vector<vector<string>> row1;
    vector<vector<string>> row2;
    vector<vector<string>> row3;
    vector<vector<string>> row4;

    row1.push_back(CARD_TEMPLATE_BORDER);
    row1.push_back(CARD_TEMPLATE_EMPTY);
    row1.push_back(display_player_card(1, "First Player", playerOne->getHealth() , 0));
    row1.push_back(CARD_TEMPLATE_EMPTY);
    row1.push_back(display_minion_no_ability("Bone Golem", 2, 2, 1));

    for (auto& minion : playerOne->getBoard()) {
        // if minion has not ability
        row2.push_back(display_minion_no_ability(minion->getName(),minion->getCost(),minion->getAttack(),minion->getDefense()));
        // if minion has activated ability
        //row2.push_back(display_minion_activated_ability(minion->getName(),minion->getCost(),minion->getAttack(),minion->getDefense(),ability cost,ability disc));
        // if minion has triggered ability
    }

    row2.push_back(display_minion_activated_ability("Novice Pyromancer",1,4,8,3,"Deal 1 damage to target minion"));
    row2.push_back(display_minion_triggered_ability("Potion Seller",2,1,4,"At the end of your turn, all your minions gain +0/+1."));
    row2.push_back(display_minion_no_ability("Earth Elemental",3,4,5));
    row2.push_back(CARD_TEMPLATE_BORDER);
    row2.push_back(CARD_TEMPLATE_BORDER);

    row3.push_back(display_minion_no_ability("Air Elemental",0,1,1));
    row3.push_back(display_minion_triggered_ability("Fire Elemental",2,3,2,"Whenever an opponent's minion enters play, deal 1 damage to it."));
    row3.push_back(display_minion_activated_ability("Apprentice Summoner",1,2,2,1,"Summon a 1/1 air elemental"));
    row3.push_back(CARD_TEMPLATE_BORDER);
    row3.push_back(CARD_TEMPLATE_BORDER);

    row4.push_back(display_ritual("Aura of Power",1,1,"Whenever a minion enters play under your control, it gains +1/+1",2));
    row4.push_back(CARD_TEMPLATE_EMPTY);
    row4.push_back(display_player_card(2, "Second Player", playerTwo->getHealth(), 0));
    row4.push_back(CARD_TEMPLATE_EMPTY);
    row4.push_back(CARD_TEMPLATE_BORDER);

    printTopBorder();
    printRow(row1);
    printRow(row2);

    vector<string> center = CENTRE_GRAPHIC;
    for (auto i : center) {
        cout << i << endl;
    }

    printRow(row3);
    printRow(row4);

    printBottomBorder();
}

void TextDisplay::printHand(unique_ptr<Player>& player) {

}

void TextDisplay::printEnchantments(unique_ptr<Minion>& minion) {

}

void TextDisplay::refresh(unique_ptr<Player>& playerOne, unique_ptr<Player>& playerTwo) {
    printBoard(playerOne, playerTwo);
}
