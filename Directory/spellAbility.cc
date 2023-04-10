#include "spellAbility.h"
#include "player.h"
#include "gameController.h"
#include <string>
#include <memory>
#include "minion.h"
#include "ritual.h"
#include <vector>
#include <iostream>
using namespace std;

string Banish::getDescription() {
    return "Destroy target minion or ritual";
}
bool Banish::useAbility(unique_ptr<Minion>& target) {
    int i = 0;
    
    vector<unique_ptr<Minion>>& board = target->getOwner()->getBoard();
    
    for (auto& minion : board) {
        
        if (minion.get() == target.get()) {
            (target->getOwner())->sendToGrave(target);
            board.erase(board.begin() + i);
            break;
        }
        i++;
    }
    return true;
}
bool Banish::useAbility(unique_ptr<Ritual>& target) {
    target.~unique_ptr();
    return true;
}


string Unsummon::getDescription() {
    return "Return target minion to its owner's hand";
}
bool Unsummon::useAbility(unique_ptr<Minion>& target) {
    if ( target->getOwner()->getHand().size() >= 5) {
        cerr << "Target wwner's hand is full can not Unsummon target minion" << endl;
        return false;
    } else {
        int i = 0;
        vector<unique_ptr<Minion>>& board = target->getOwner()->getBoard();
        for (auto& minion : board) {
            if (minion.get() == target.get()) {
                (target->getOwner())->sendToHand(target);
                board.erase(board.begin() + i);
                break;
            }
            i++;
        }
    return true;
    }
    
}

string Recharge::getDescription() {
    return "Your ritual gains 3 charges";
}
bool Recharge::useAbility() {
    if (getOwner()->getRitualField().get() == nullptr) {
        cerr << "No ritual on the board"<< endl;
        return false;
    } else {
        getOwner()->getRitualField().get()->restoreCharges(3);
        return true;
    }
}

string Disenchant::getDescription() {
    return "Destroy the top enchantment on target minion";
}
bool Disenchant::useAbility(unique_ptr<Minion>& target) {
    target->removeTopEnchantment();
    return true;
}

string RaiseDead::getDescription() {
    return "Resurrect the top minion in your graveyard and set its defence to 1";
}
bool RaiseDead::useAbility() {
     vector<unique_ptr<Minion>>& graveyard = this->getOwner()->getGraveyard();
    if (graveyard.size() > 0) {
        if (getOwner()->getBoardMinionCount() >=5) {
            cerr << "The board is full, can not resurrect target" << endl;
            return false;
        } else {
            graveyard.back()->setDefense(1);
            getOwner()->sendToBoard(graveyard.back());
            graveyard.pop_back();
            return true;
        }
        
    } else {
        cerr << "Graveyard is empty" << endl;
        return false;
    }
}

string Blizzard::getDescription() {
    return "Deal 2 damage to all minions";
}

bool Blizzard::useAbility() {
    for (auto& minion : getOwner()->getBoard()) {
        minion->takeDamage(2);
    }
    for (auto& minion : gameController->getNonActivePlayerBoard()) {
        minion->takeDamage(2);
    }
    return true;
}