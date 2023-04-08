#include "textDisplay.h"
#include <memory>
#include "player.h"
#include "minion.h"
#include "hasAbility.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


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

    if (playerOne->getRitualField()) {
        //row1.push_back(display_ritual(playerOne->getRitualField()->name))
        row1.push_back(CARD_TEMPLATE_BORDER); // CHANGE LATER
    }
    else {
        row1.push_back(CARD_TEMPLATE_BORDER);
    }

    row1.push_back(CARD_TEMPLATE_EMPTY); // always empty
    row1.push_back(display_player_card(1, playerOne->getName(), playerOne->getHealth() , playerOne->getMagic()));
    row1.push_back(CARD_TEMPLATE_EMPTY); // always empty

    if (playerOne->getGraveFieldTop()){
        row1.push_back(CARD_TEMPLATE_BORDER); // CHANGE LATER
    }
    else {
        row1.push_back(CARD_TEMPLATE_BORDER);
    }

    // Player 1 minions
    for (auto& minion : playerOne->getBoard()) {
        if (dynamic_cast<CanUseAbility>(minion)) {
            if (dynamic_cast<HasAbilityTriggered>(minion)) {
                row2.push_back(display_minion_triggered_ability(minion->getName(),minion->getCost(),minion->getAttack(),minion->getDefense,dynamic_cast<HasAbilityTriggered>(minion)->getAbilityDescription()));
            }
            else {
                // Activated ability
                row2.push_back(display_minion_activated_ability(minion->getName(),minion->getCost(),minion->getAttack(),minion->getDefense(),dynamic_cast<CanUseAbility>(minion)->getAbilityCost(),dynamic_cast<CanUseAbility>(minion)->getAbilityDescription()));
            }
        }
        else{
            // if minion has no ability
            row2.push_back(display_minion_no_ability(minion->getName(),minion->getCost(),minion->getAttack(),minion->getDefense()));
        }
    }
    for (int i=0; i<5-playerOne->getBoardMinionCount(); i++) {
        // fill the rest with
        row2.push_back(CARD_TEMPLATE_BORDER);
    }

    // Player 2 minions
    for (auto& minion : playerTwo->getBoard()) {
        if (dynamic_cast<CanUseAbility>(minion)) {
            if (dynamic_cast<HasAbilityTriggered>(minion)) {
                row3.push_back(display_minion_triggered_ability(minion->getName(),minion->getCost(),minion->getAttack(),minion->getDefense,dynamic_cast<HasAbilityTriggered>(minion)->getAbilityDescription()));
            }
            else {
                // Activated ability
                row3.push_back(display_minion_activated_ability(minion->getName(),minion->getCost(),minion->getAttack(),minion->getDefense(),dynamic_cast<CanUseAbility>(minion)->getAbilityCost(),dynamic_cast<CanUseAbility>(minion)->getAbilityDescription()));
            }
        }
        else{
            // if minion has no ability
            row3.push_back(display_minion_no_ability(minion->getName(),minion->getCost(),minion->getAttack(),minion->getDefense()));
        }
    }
    for (int i=0; i<5-playerTwo->getBoardMinionCount(); i++) {
        // fill the rest with
        row3.push_back(CARD_TEMPLATE_BORDER);
    }

    if (playerTwo->getRitualField()) {
        //row4.push_back(display_ritual(playerOne->getRitualField()->name))
        row4.push_back(CARD_TEMPLATE_BORDER); // CHANGE LATER
    }
    else {
        row4.push_back(CARD_TEMPLATE_BORDER);
    }

    row4.push_back(CARD_TEMPLATE_EMPTY); // always empty
    row4.push_back(display_player_card(2, playerTwo->getName(), playerTwo->getHealth(), playerTwo->getMagic()));
    row4.push_back(CARD_TEMPLATE_EMPTY); // always empty

    if (playerTwo->getGraveFieldTop()){
        row4.push_back(CARD_TEMPLATE_BORDER); // CHANGE LATER
    }
    else {
        row4.push_back(CARD_TEMPLATE_BORDER);
    }

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
    int i = 1;
    for (auto& card : player->getHand()) {
        cout << i << ": " << card->getName() << endl;
        i++;
    }
}

void TextDisplay::printEnchantments(unique_ptr<Minion>& minion) {
    cout << minion->getName() << endl;
}

void TextDisplay::refresh(unique_ptr<Player>& playerOne, unique_ptr<Player>& playerTwo) {
    printBoard(playerOne, playerTwo);
}
