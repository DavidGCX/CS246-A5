#include "textDisplay.h"
#include <memory>
#include "player.h"
#include "minion.h"
#include "hasAbility.h"
#include "spell.h"
#include "enchantments.h"
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

// Given minion, returns appropriate block of strings that displays it
vector<string> TextDisplay::generateMinion(unique_ptr<Minion>* minion) {
    if (dynamic_cast<CanUseAbility*>(minion->get())) {
        if (dynamic_cast<HasAbilityTriggered*>(minion->get())) {
            return display_minion_triggered_ability((*minion)->getName(),(*minion)->getCost(), 
            (*minion)->getAttack(), (*minion)->getDefense(),
            dynamic_cast<CanUseAbility*>(minion->get())->getDescription());
        }
        else {
            // Activated ability
            return display_minion_activated_ability((*minion)->getName(), (*minion)->getCost(),
            (*minion)->getAttack(),(*minion)->getDefense(),
            dynamic_cast<CanUseAbility*>((*minion).get())->getAbilityCost(),
            dynamic_cast<CanUseAbility*>((*minion).get())->getDescription());
        }
    }
    else {
        // if minion has no ability
        return display_minion_no_ability((*minion)->getName(), (*minion)->getCost(),
        (*minion)->getAttack(), (*minion)->getDefense());
    }
}
vector<string> TextDisplay::generateMinion(Minion* minion) {
    if (dynamic_cast<CanUseAbility*>(minion)) {
        if (dynamic_cast<HasAbilityTriggered*>(minion)) {
            return display_minion_triggered_ability(minion->getName(),minion->getCost(), 
            minion->getAttack(), minion->getDefense(),
            dynamic_cast<CanUseAbility*>(minion)->getDescription());
        }
        else {
            // Activated ability
            return display_minion_activated_ability(minion->getName(), minion->getCost(),
            minion->getAttack(),minion->getDefense(),
            dynamic_cast<CanUseAbility*>(minion)->getAbilityCost(),
            dynamic_cast<CanUseAbility*>(minion)->getDescription());
        }
    }
    else {
        // if minion has no ability
        return display_minion_no_ability(minion->getName(), minion->getCost(),
        minion->getAttack(), minion->getDefense());
    }
}

// Given card, returns appropriate block of strings that displays it
vector<string> TextDisplay::generateCard(unique_ptr<Card>* card) {
    if (dynamic_cast<Spell*>(card->get())) {
        string des;
        if(dynamic_cast<HasAbilityNoTarget*>(card->get())) {
            des = dynamic_cast<HasAbilityNoTarget*>(card->get())->getDescription();
        } else if (dynamic_cast<HasAbilityWithTarget*>(card->get())) {
            des = dynamic_cast<HasAbilityWithTarget*>(card->get())->getDescription();
        } else {
            des = dynamic_cast<HasAbilityWithTargetRitual*>(card->get())->getDescription();
        }
        return display_spell((*card)->getName(),(*card)->getCost(), des);
    }
    if (dynamic_cast<Minion*>(card->get())) {
        return generateMinion(dynamic_cast<Minion*>(card->get()));
    }
    if (dynamic_cast<Enchantment*>(card->get())) {
        if (dynamic_cast<Enchantment*>(card->get())->isSimpleADBuff()) {
            if (dynamic_cast<Enchantment*>(card->get())->buffType() == 1) {
                string attack = "+" + to_string(dynamic_cast<Enchantment*>(card->get())->buffValueAttack());
                string defense = "+" + to_string(dynamic_cast<Enchantment*>(card->get())->buffValueDefense());
                return display_enchantment_attack_defence((*card)->getName(), (*card)->getCost(),"",attack,defense);
            }
            if (dynamic_cast<Enchantment*>(card->get())->buffType() == 2) {
                string attack = "*" + to_string(dynamic_cast<Enchantment*>(card->get())->buffValueAttack());
                string defense = "*" + to_string(dynamic_cast<Enchantment*>(card->get())->buffValueDefense());
                return display_enchantment_attack_defence((*card)->getName(), (*card)->getCost(),"",attack,defense);
            }
        }
        else {
            return display_enchantment((*card)->getName(),(*card)->getCost(),
             (dynamic_cast<CanUseAbility*>(card->get()))->getDescription());
        }
    } else {
        return display_ritual((*card)->getName(),(*card)->getCost(),
        (dynamic_cast<Ritual*>(card->get()))->getCostPerCharges(),
        (dynamic_cast<HasAbilityTriggered*>(card->get()))->getDescription(),
        (dynamic_cast<Ritual*>(card->get()))->getCharges());
    }
}

// Given enchantment, returns appropriate block of strings that displays it
vector<string> TextDisplay::generateEnchantment(unique_ptr<Enchantment>* enchantment) {
    if (enchantment->get()->isSimpleADBuff()) {
        if (enchantment->get()->buffType() == 1) {
            string attack = "+" + to_string(enchantment->get()->buffValueAttack());
            string defense = "+" + to_string(enchantment->get()->buffValueDefense());
            return display_enchantment_attack_defence((*enchantment)->getName(), (*enchantment)->getCost(),"",attack,defense);
        }
        if (enchantment->get()->buffType() == 2) {
            string attack = "*" + to_string(enchantment->get()->buffValueAttack());
            string defense = "*" + to_string(enchantment->get()->buffValueDefense());
            return display_enchantment_attack_defence((*enchantment)->getName(), (*enchantment)->getCost(),"",attack,defense);
        }
    }
    else {
        return display_enchantment((*enchantment)->getName(),(*enchantment)->getCost(),
             ((dynamic_cast<CanUseAbility*>(enchantment->get())))->getDescription());
    }
}

void TextDisplay::printBoard(unique_ptr<Player>& playerOne, unique_ptr<Player>& playerTwo) {
    vector<vector<string>> row1;
    vector<vector<string>> row2;
    vector<vector<string>> row3;
    vector<vector<string>> row4;

    if (playerOne->getRitualField()) {
        row1.push_back(display_ritual(playerOne->getRitualField()->getName(),
        playerOne->getRitualField()->getCost(),
        playerOne->getRitualField()->getCostPerCharges(),
        dynamic_cast<HasAbilityTriggered*>(playerOne->getRitualField().get())->getDescription(),
        playerOne->getRitualField()->getCharges())); 
    }
    else {
        row1.push_back(CARD_TEMPLATE_BORDER);
    }

    row1.push_back(CARD_TEMPLATE_EMPTY); // always empty
    row1.push_back(display_player_card(1, playerOne->getName(), playerOne->getHealth() , playerOne->getMagic()));
    row1.push_back(CARD_TEMPLATE_EMPTY); // always empty

    if (playerOne->getGraveFieldTop()){
        row1.push_back(generateMinion(playerOne->getGraveFieldTop()));
    }
    else {
        row1.push_back(CARD_TEMPLATE_BORDER);
    }

    // Player 1 minions
    for (auto& minion : playerOne->getBoard()) {
        row2.push_back(generateMinion(&minion));
    }
    for (int i=0; i<5-playerOne->getBoardMinionCount(); i++) {
        // fill the rest with blanks
        row2.push_back(CARD_TEMPLATE_BORDER);
    }

    // Player 2 minions
    for (auto& minion : playerTwo->getBoard()) {
        row3.push_back(generateMinion(&minion));
    }
    for (int i=0; i<5-playerTwo->getBoardMinionCount(); i++) {
        // fill the rest with blanks
        row3.push_back(CARD_TEMPLATE_BORDER);
    }

    if (playerTwo->getRitualField()) {
        row4.push_back(display_ritual(playerTwo->getRitualField()->getName(),
        playerTwo->getRitualField()->getCost(),
        playerTwo->getRitualField()->getCostPerCharges(),
        dynamic_cast<HasAbilityTriggered*>(playerTwo->getRitualField().get())->getDescription(),
        playerTwo->getRitualField()->getCharges()));
    }
    else {
        row4.push_back(CARD_TEMPLATE_BORDER);
    }

    row4.push_back(CARD_TEMPLATE_EMPTY); // always empty
    row4.push_back(display_player_card(2, playerTwo->getName(), playerTwo->getHealth(), playerTwo->getMagic()));
    row4.push_back(CARD_TEMPLATE_EMPTY); // always empty

    if (playerTwo->getGraveFieldTop()){
        row4.push_back(generateMinion(playerTwo->getGraveFieldTop()));
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
    vector<vector<string>> row;
    for (auto& card : player->getHand()) {
        //cout << card->getName() << endl;
        row.push_back(generateCard(&card));
        //cout << card->getName() << endl;
    }
    printRow(row);
}

void TextDisplay::printEnchantments(unique_ptr<Minion>& minion) {
    vector<vector<string>> row;
    row.push_back(generateMinion(&minion));
    printRow(row);
    
    int numEnchantments = minion->getEnchantments()->size();

    // 5 enchantments per row
    for (int j=0; j<numEnchantments/5; j++) {
        row.clear();
        for (int i=0; i<5; i++) {
            if (j*5+i < numEnchantments) {
                row.push_back(generateEnchantment(minion->getEnchantments()->at(j*5+i)));
            }
            else {
                break;
            }
        }
        printRow(row);
    }
}

void TextDisplay::refresh(unique_ptr<Player>& playerOne, unique_ptr<Player>& playerTwo) {
    printBoard(playerOne, playerTwo);
}
