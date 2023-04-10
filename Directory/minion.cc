#include "minion.h"
#include "card.h"
#include "gameController.h"
#include "player.h"
#include "enchantments.h"
#include <iostream>
using namespace std;

Minion::Minion(GameController *g, Player* owner, string name, int cost, 
int attack, int defense) : Card{name, cost, g, owner}, attack{attack}, 
defense{defense}, numActions{0} {}

void Minion::takeDamage(int amount) {
    defense = defense - amount;
    // if defense gets to 0 or below, remove from board
}

void Minion::attackMinion(unique_ptr<Minion>& target) {
    if (numActions > 0) {
        numActions -= 1;
        this->takeDamage(target->getAttack());
        target->takeDamage(attack);
    } else {
        cerr << "This Minion Does Not Have Enough ActionPoint" << endl;
    }
}

void Minion::attackPlayer() {
    if (numActions > 0) {
        numActions -= 1;
        gameController->attackNonActivePlayer(getAttack());
    } else {
        cerr << "This Minion Does Not Have Enough ActionPoint" << endl;
    }
}

void Minion::notify(StateInfo state) {
    if (state == StateInfo::onTurnStart && 
    (*gameController->getActivePlayer()).get() == getOwner()){
        numActions = 1;
    }
    for(auto& enchantment : enchantments) {
       enchantment->notify(state);
    }
}
void Minion::notify(StateInfo state, unique_ptr<Minion>& target) {
   for(auto& enchantment : enchantments) {
       enchantment->notify(state, target);
    }
}

void Minion::removeAllEnchantment() {
    while(enchantments.size() > 0) {
        enchantments.back()->reverseEffect(this);
        enchantments.pop_back();
    }
}

bool Minion::removeTopEnchantment()
{
    if (enchantments.size() > 0) {
        enchantments.back()->reverseEffect(this);
        enchantments.pop_back();
        return true;
    } else {
        return false;
    }
}

void Minion::setAttack(int a) {
    attack = a;
}
void Minion::setDefense(int d) {
    defense = d;
}
void Minion::setActNum(int n) {
    numActions = n;
}

int Minion::getAttack() {
    return attack;
}
int Minion::getDefense() {
    return defense;
}
int Minion::getActNum() {
    return numActions;
}

void Minion::attachEnchantment(unique_ptr<Enchantment>&& from) {
    enchantments.push_back(move(from));
}
