#include "enchantments.h"
#include <memory>
#include <string>
#include "state.h"
#include "player.h"
#include "hasAbility.h"
#include <iostream>
#include "gameController.h"
using namespace std;

bool GiantStrength::useAbility(std::unique_ptr<Minion>& target) {
    target->restoreAttack(2);
    target->restoreDefense(2);
    return true;
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
    return true;
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
    return true;
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



bool MagicFatigue::useAbility(std::unique_ptr<Minion>& target) {
    if (dynamic_cast<HasAbilityWithTarget*>(target.get())) {
        dynamic_cast<HasAbilityWithTarget*>(target.get())->changeAbilityCost(3);
    }
    if (dynamic_cast<HasAbilityWithTargetRitual*>(target.get())) {
        dynamic_cast<HasAbilityWithTargetRitual*>(target.get())->changeAbilityCost(3);
    }
    return true;
}
void MagicFatigue::reverseEffect(Minion* target) {
    if (dynamic_cast<HasAbilityWithTarget*>(target)) {
        dynamic_cast<HasAbilityWithTarget*>(target)->changeAbilityCost(-3);
    }
    if (dynamic_cast<HasAbilityWithTargetRitual*>(target)) {
        dynamic_cast<HasAbilityWithTargetRitual*>(target)->changeAbilityCost(-3);
    }
}


bool Silence::useAbility(std::unique_ptr<Minion>& target) {
    if (dynamic_cast<HasAbilityWithTarget*>(target.get())) {
        dynamic_cast<HasAbilityWithTarget*>(target.get())->setSilence(true);
    }
    if (dynamic_cast<HasAbilityWithTargetRitual*>(target.get())) {
        dynamic_cast<HasAbilityWithTargetRitual*>(target.get())->setSilence(true);
    }
    return true;
}
void Silence::reverseEffect(Minion* target) {
    if (dynamic_cast<HasAbilityWithTarget*>(target)) {
        dynamic_cast<HasAbilityWithTarget*>(target)->setSilence(false);
    }
    if (dynamic_cast<HasAbilityWithTargetRitual*>(target)) {
        dynamic_cast<HasAbilityWithTargetRitual*>(target)->setSilence(false);
    }
}
