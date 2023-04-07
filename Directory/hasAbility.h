#ifndef HAB_H
#define HAB_H
#include "minion.h"
#include "ritual.h"
#include <memory>
#include <vector>

class Card;
class CanUseAbility{
    int abilityCost;
public:
    int getAbilityCost() { return abilityCost; }
    int setAbilityCost(int cost) {abilityCost = cost;}
    virtual ~CanUseAbility() = 0;
};

class HasAbilityWithTarget : public CanUseAbility {
public:
    virtual bool useAbility(std::unique_ptr<Card>& target) = 0;
};
class HasAbilityNoTarget : public CanUseAbility {
public:
    virtual bool useAbility() = 0;
};


#endif