#ifndef HAB_H
#define HAB_H
#include "minion.h"
#include "ritual.h"
#include <vector>

class CanUseAbility{
    int abilityCost;
public:
    int getAbilityCost() { return abilityCost; }
    int setAbilityCost(int cost) {abilityCost = cost;}
    virtual ~CanUseAbility() = 0;
}
class HasAbility : public CanUseAbility {
    virtual bool useAbility() = 0;
};

class HasAbilityTargetMinion : public CanUseAbility {
    virtual bool useAbility(unique_ptr<Minion>* Minion) = 0;
};

class HasAbilityTargetRitual : public CanUseAbility {
    virtual bool useAbility(unique_ptr<Ritual>* ritual) = 0;
};
#endif