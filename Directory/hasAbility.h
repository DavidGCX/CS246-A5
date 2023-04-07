#ifndef HAB_H
#define HAB_H
#include "minion.h"
#include "ritual.h"
#include <memory>
#include <vector>

class CanUseAbility{
    int abilityCost;
public:
    int getAbilityCost() { return abilityCost; }
    int setAbilityCost(int cost) {abilityCost = cost;}
    virtual ~CanUseAbility() = 0;
};

template <typename T>
class canUseAbilityWithTarget : public CanUseAbility {
    virtual bool useAbility(T target) = 0;
};
class HasAbility : public CanUseAbility {
    virtual bool useAbility() = 0;
};


#endif