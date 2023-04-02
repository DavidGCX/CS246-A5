#ifndef SPL_H
#define SPL_H
#include "card.h"
#include "ritual.h"
#include "hasability.h"
#include <vector>
#include <string>

class Spell: public Card {
    public:
    Spell(std::string name, int cost);
    bool canBePlayed();
};

class Blizzard: public Spell, public HasAbility {
    Blizzard();
    bool useAbility();
};
class RaiseDead: public Spell, public HasAbility {
    bool canBePlayed();
    RaiseDead();
    bool useAbility();
};
class Disenchant: public Spell, public HasAbilityTargetMinion {
    Disenchant();
    bool useAbility(Minion& m);
};
class Unsummon: public Spell, public HasAbilityTargetMinion {
    Unsummon();
    bool useAbility(Minion& m);
};
class Banish: public Spell, public HasAbilityTargetMinion, public HasAbilityTargetRitual {
    Banish();
    bool useAbility(Minion& m);
    bool useAbility(Ritual& r);
};
class Recharge: public Spell, public HasAbilityTargetMinion {
    Recharge();
    bool canBePlayed();
    bool useAbility(Ritual& r);
};
#endif