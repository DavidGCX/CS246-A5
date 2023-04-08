#ifndef HAB_H
#define HAB_H
#include <memory>
#include <vector>
#include <string>

class Card;
class CanUseAbility{
    int abilityCost;
public:
    int getAbilityCost() { return abilityCost; }
    int setAbilityCost(int cost) {abilityCost = cost;}
    virtual std::string getAbilityDescription() = 0;
    virtual ~CanUseAbility() = 0;
};


class HasAbilityWithTargetGroup : public CanUseAbility {
public:
    virtual bool useAbility(std::vector<std::unique_ptr<Card>>& target) = 0;
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