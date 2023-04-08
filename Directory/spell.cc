#include "spell.h"
#include "gameController.h"
using namespace std;

Spell::Spell(GameController *g, string name, int cost): Card{g, name, cost} {}

bool Spell::canBePlayed() {
    // if enough to satisfy cost, return true
}

/*
Blizzard::Blizzard(GameController *g): Spell{g, "Blizzard", 3} {}
bool Blizzard::useAbility() {
    // for all minions on each player's board, m.setDefense(m.getDefense - 2);
    // deal with those that are below or at 0 after
}

RaiseDead::RaiseDead(GameController *g): Spell{g, "Raise Dead", 1} {}
bool RaiseDead::useAbility() { // check if graveyard is full
    // take top minion from graveyard
    // m.setDefense(1);
}

Disenchant::Disenchant(GameController *g): Spell{g, "Disenchant", 1} {}
bool Disenchant::useAbility(Minion& m) {
    // look at m's enchantment list, m.pop_back(), reverse the effect
    // if statements for whatever effect we removed
}

Unsummon::Unsummon(GameController *g): Spell{g, "Unsummon", 1} {}
bool Unsummon::useAbility(Minion& m) {
    // make temp for the minion, remove original from board, add temp to hand
}

Banish(GameController *g): Spell{g, "Banish", 2} {}
bool Banish::useAbility(Minion& m); // remove from board, does not go into graveyard or hand
bool Banish::useAbility(Ritual& r); // remove from board

Recharge(GameController *g): Spell{g, "Recharge", 1} {}
bool Recharge::useAbility(Ritual& r); // add 3 charges to ritual r is ritual exists
*/