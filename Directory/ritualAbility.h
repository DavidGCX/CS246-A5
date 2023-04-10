#ifndef __RITUALABILITY_H__
#define __RITUALABILITY_H__

#include "ritual.h"
#include "hasAbility.h"
#include "state.h"
#include <string>
#include <memory>
class GameController;
class Player;
class Minion;
class DarkRitual : public Ritual, public HasAbilityTriggered {
    DarkRitual(GameController* gameController, Player* owner,std::string name = "Dark Ritual", int cost=0,
    int charges = 5, int cost_per_charge = 1): 
    Ritual{name, cost, gameController, owner, charges, cost_per_charge}{}

    void notify(StateInfo stateInfo) override;
    std::string getDescription() override;
};

class AuraOfPower : public Ritual, public HasAbilityTriggered {
    AuraOfPower(GameController* gameController, Player* owner,std::string name = "Aura of Power", int cost=1,
    int charges = 4, int cost_per_charge = 1): 
    Ritual{name, cost, gameController, owner, charges, cost_per_charge}{}
    
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override;
    std::string getDescription() override;
};

class StandStill : public Ritual, public HasAbilityTriggered {
    StandStill(GameController* gameController, Player* owner,std::string name = "StandStill", int cost=3,
    int charges = 4, int cost_per_charge = 2): 
    Ritual{name, cost, gameController, owner, charges, cost_per_charge}{}
    
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override;
    std::string getDescription() override;
};
#endif // __RITUALABILITY_H__