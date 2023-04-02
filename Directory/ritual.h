#ifndef RIT_H
#define RIT_H
#include "card.h"
#include "hasability.h"
#include <vector>
#include <string>

class Ritual: public Card {
    int charges;
    int cost_per_charge;
    public:
    Ritual(std::string name, int cost, int charges, int cost_per_charge);
    bool canBePlayed();
    bool canBeUsed();
};

class DarkRitual: public Ritual, public HasAbility {
    public:
    DarkRitual();
    bool useAbility();
};

class AuraOfPower: public Ritual, public HasAbilityTargetMinion {
    public:
    AuraofPower();
    bool useAbility();
};

class Standstill: public Ritual, public HasAbilityTargetMinion {
    public:
    Standstill();
    bool useAbility();
};

#endif