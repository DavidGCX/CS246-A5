#ifndef HAB_H
#define HAB_H
#include <memory>
#include <vector>
#include <string>
class Minion;
class Ritual;
class CanUseAbility{
    int abilityCost;
    bool silence = false;
public:
    int getAbilityCost() { return abilityCost; }
    void setAbilityCost(int cost) {abilityCost = cost;}
    void changeAbilityCost(int cost) {
        if  (abilityCost + cost >= 0 ) {
            abilityCost += cost;
        } else {
            abilityCost = 0;
        }
         
    }
    virtual std::string getDescription() = 0;
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
    virtual bool useAbility(std::unique_ptr<Minion>& target) = 0;
};
class HasAbilityWithTargetRitual : public CanUseAbility {
public:
    virtual bool useAbility(std::unique_ptr<Ritual>& target) = 0;
};
class HasAbilityNoTarget : public CanUseAbility {
public:
    virtual bool useAbility() = 0;
};

//nothing for this one, for classification only
class HasAbilityTriggered : public CanUseAbility { 
    
};

#endif