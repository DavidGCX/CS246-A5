#include "minion.h"
#include "card.h"
#include "gameController.h"
#include "player.h"
#include "enchantments.h"
using namespace std;

Minion::Minion(GameController *g, Player* owner, string name, int cost, 
int attack, int defense) : Card{name, cost, g, owner}, attack{attack}, 
defense{defense}, numactions{1} {}

void Minion::takeDamage(int amount) {
    defense = defense - amount;
    // if defense gets to 0 or below, remove from board
}

void Minion::attackMinion(unique_ptr<Minion>& target) {
    this->takeDamage(target->getAttack());
    target->takeDamage(attack);
}

void Minion::attackPlayer() {
    gameController->attackNonActivePlayer(getAttack());
}

void Minion::notify(StateInfo state) {
    if (state == StateInfo::onTurnStart){
        if (numactions < 1 && numactions) {
            numactions = 1;
        }
    }
    for(auto& enchantment : enchantments) {
       enchantment->notify(state);
   }
}
void Minion::notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) {
   return;
}

void Minion::removeAllEnchantment() {
    while(enchantments.size() > 0) {
        enchantments.back()->reverseEffect(this);
        enchantments.pop_back();
    }
}

void Minion::setAttack(int a) {
    attack = a;
}
void Minion::setDefense(int d) {
    defense = d;
}
void Minion::setActNum(int n) {
    numactions = n;
}

void Minion::setRemAct(int r) {
    if (r == 2) {
        remainingactions = numactions;
    } else {
        remainingactions = 1;
    }
}
int Minion::getAttack() {
    return attack;
}
int Minion::getDefense() {
    return defense;
}
int Minion::getActNum() {
    return numactions;
}

void Minion::attachEnchantment(unique_ptr<Enchantment>&& from) {
    enchantments.push_back(move(from));
}
