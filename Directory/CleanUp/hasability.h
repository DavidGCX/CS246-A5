#ifndef HAB_H
#define HAB_H
#include "minion.h"
#include "ritual.h"
#include <vector>

class HasAbility {
    virtual bool useAbility() = 0;
};

class HasAbilityTargetMinion {
    virtual bool useAbility(Minion& m) = 0;
};

class HasAbilityTargetRitual {
    virtual bool useAbility(Ritual& r) = 0;
};
#endif