#ifndef SPL_H
#define SPL_H
#include "card.h"
#include "ritual.h"
#include "hasability.h"
#include "gameController.h"
#include "minion.h"
#include <vector>
#include <string>

class Spell: public Card {
    public:
    Spell(GameController *g, std::string name, int cost);
    bool canBePlayed();
};

class Blizzard: public Spell, public HasAbility {
    public:
    Blizzard(GameController *g);
    bool useAbility();
};
class RaiseDead: public Spell, public HasAbility {
    public:
    bool canBePlayed();
    RaiseDead(GameController *g);
    bool useAbility();
};
class Disenchant: public Spell, public HasAbilityTargetMinion {
    public:
    Disenchant(GameController *g);
    bool useAbility(Minion& m);
};
class Unsummon: public Spell, public HasAbilityTargetMinion {
    public:
    Unsummon(GameController *g);
    bool useAbility(Minion& m);
};
class Banish: public Spell, public HasAbilityTargetMinion, public HasAbilityTargetRitual {
    public:
    Banish(GameController *g);
    bool useAbility(Minion& m);
    bool useAbility(Ritual& r);
};
class Recharge: public Spell, public HasAbilityTargetMinion {
    public:
    Recharge(GameController *g);
    bool canBePlayed();
    bool useAbility(Ritual& r);
};
#endif