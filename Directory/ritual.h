#ifndef RIT_H
#define RIT_H
#include "card.h"
//#include "hasability.h"
#include "minion.h"
#include <vector>
#include <string>

class Ritual: public Card {
    int charges;
    int cost_per_charge;
    public:
    Ritual(GameController *g, std::string name, int cost, int charges, int cost_per_charge, Player* owner);
    bool canBePlayed();
    bool canBeUsed();
};
/*
class DarkRitual: public Ritual, public HasAbility {
    public:
    DarkRitual(GameController *g);
    bool useAbility();
};

class AuraOfPower: public Ritual, public HasAbilityTargetMinion {
    public:
    AuraOfPower(GameController *g);
    bool useAbility(Minion &m);
};

class Standstill: public Ritual, public HasAbilityTargetMinion {
    public:
    Standstill(GameController *g);
    bool useAbility(Minion &m);
};
*/
#endif