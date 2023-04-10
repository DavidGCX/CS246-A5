#include "enchantments.h"
#include <memory>
#include <string>
#include "state.h"
#include "player.h"
#include <iostream>
#include "gameController.h"
using namespace std;

bool GiantStrength::useAbility(std::unique_ptr<Minion>& target) {
    target->restoreAttack(2);
    target->restoreDefense(2);
}
void GiantStrength::reverseEffect(Minion* target) {
    if (target->getAttack() > 2) {
        target->setAttack(target->getAttack() - 2);
    } else {
        target->setAttack(0);
    }
    if (target->getDefense() > 2) {
        target->setDefense(target->getDefense() - 2);
    } else {
        target->setDefense(1);
    }
}

bool Enrage::useAbility(std::unique_ptr<Minion>& target) {
    target->setAttack(target->getAttack() * 2);
    target->setDefense(target->getDefense() * 2);
}
void Enrage::reverseEffect(Minion* target) {
    target->setAttack(target->getAttack() / 2);
    if (target->getDefense() > 1) {
        target->setDefense(target->getDefense() / 2);
    } else {
        target->setDefense(1);
    }

}
bool Haste::useAbility(std::unique_ptr<Minion>& target) {
    target->setActNum(target->getActNum()+1);
}
void Haste::reverseEffect(Minion* target) {
    return;
}
void Haste::notifyEnchant(StateInfo stateInfo, Minion* target) {
    if (gameController->getActivePlayer()->get() == getOwner() && 
    stateInfo == StateInfo::onTurnStart) {
        target->setActNum(target->getActNum()+1);
    }
}