#include "ritual.h"
using namespace std;

Ritual::Ritual(GameController *g, string name, int cost, int charges, 
int cost_per_charge, Player* owner): Card{name, cost,g, owner}, charges{charges}, cost_per_charge{cost_per_charge} {}

bool Ritual::canBePlayed() {
    return true;
} // check if enough cost

bool Ritual::canBeUsed() {
    if (cost_per_charge > charges) {
        return false;
    } else {
        return true;
    }
}
/*
DarkRitual::DarkRitual(GameController *g): Ritual{g, "Dark Ritual", 0, 5, 1} {}
bool DarkRitual::useAbility() {
    if (canBeUsed()) {
        // player gains 1 magic
        return true;
    } else {
        return false;
    }
}

AuraOfPower::AuraOfPower(GameController *g): Ritual{g, "Aura of Power", 1, 4, 1} {}
bool AuraOfPower::useAbility(Minion& m) {
    if (canBeUsed()) {
        m.setAttack(m.getAttack() + 1);
        m.setDefense(m.getDefense() + 1);
        return true;
    } else {
        return false;
    }
}

Standstill::Standstill(GameController *g): Ritual{g, "Standstill", 3, 4, 2} {}
bool Standstill::useAbility(Minion& m) {
    if (canBeUsed()) {
        // destroy m
        return true;
    } else {
        return false;
    }
}
*/

