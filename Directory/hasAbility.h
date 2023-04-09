#ifndef HAB_H
#define HAB_H
#include <memory>
#include <vector>
#include <string>

class Card;
class CanUseAbility{
    int abilityCost;
    bool silence = false;
public:
    int getAbilityCost() { return abilityCost; }
    int setAbilityCost(int cost) {abilityCost = cost;}
    virtual std::string getAbilityDescription() = 0;
    virtual bool checkUseCondition() {return true;};
    virtual ~CanUseAbility() = 0;
    void setSilence(bool state) {silence = state;}
    bool getSilence() { return silence; }
};

/*
class HasAbilityWithTargetGroup : public CanUseAbility {
public:
    virtual bool useAbility(std::vector<std::unique_ptr<Card>>& target) = 0;
};
*/
class HasAbilityWithTarget : public CanUseAbility {
public:
    virtual bool useAbility(std::unique_ptr<Card>& target) = 0;
};
class HasAbilityNoTarget : public CanUseAbility {
public:
    virtual bool useAbility() = 0;
};

class HasAbilityTriggered : public CanUseAbility {
public:
    virtual bool useAbility() = 0;
};

#endif