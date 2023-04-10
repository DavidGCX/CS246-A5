#ifndef __MINIONWITHABILITY_H__
#define __MINIONWITHABILITY_H__
#include "minion.h"
#include "hasAbility.h"
#include "state.h"
#include <string>
#include <memory>
class GameController;
class Player;

class BoneGolem: public Minion, public HasAbilityTriggered{
public:
    BoneGolem(GameController *g, Player* owner, std::string name = "Bone Golem", 
    int cost = 2, int attack = 1, int defense = 3) : 
    Minion{g, owner, name, cost, attack, defense}{}
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override;
    std::string getDescription() override;
};

class FireElemental : public Minion, public HasAbilityTriggered{
public:
    FireElemental(GameController* g, Player* owner, std::string name = "Fire Elemental", 
    int cost = 2, int attack = 2, int defense = 2) :  
    Minion{g, owner, name, cost, attack, defense}{}
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override;
    std::string getDescription() override;
};

class PotionSeller: public Minion, public HasAbilityTriggered{
public:
    PotionSeller(GameController *g, Player* owner, std::string name = "Potion Seller", 
    int cost = 2, int attack = 1, int defense = 3) :  
    Minion{g, owner, name, cost, attack, defense}{}
    void notify(StateInfo stateInfo) override;
    std::string getDescription() override;
};

class NovicePyromancer: public Minion, public HasAbilityWithTarget{
public:
    NovicePyromancer(GameController *g, Player* owner, std::string name = "Novice Pyromancer", 
    int cost = 1, int attack = 0, int defense = 1) :  
    Minion{g, owner, name, cost, attack, defense}{
        setSilence(false);
        setAbilityCost(1);
    }
    std::string getDescription() override;
    bool useAbility(std::unique_ptr<Minion>& target) override;
};

class ApprenticeSummoner: public Minion, public HasAbilityNoTarget{
public:
    ApprenticeSummoner(GameController *g, Player* owner, std::string name = "Apprentice Summoner", 
    int cost = 1, int attack = 1, int defense = 1) :  
    Minion{g, owner, name, cost, attack, defense}{
        setSilence(false);
        setAbilityCost(1);
    }
    std::string getDescription() override;
    bool useAbility() override;
};

class MasterSummoner: public Minion, public HasAbilityNoTarget{
public:
    MasterSummoner(GameController *g, Player* owner, std::string name = "Master Summoner", 
    int cost = 3, int attack = 2, int defense = 3) :  
    Minion{g, owner, name, cost, attack, defense}{
        setSilence(false);
        setAbilityCost(2);
    }
    std::string getDescription() override;
    bool useAbility() override;
};
#endif // __MINIONWITHABILITY_H__