#ifndef __MINIONWITHABILITY_H__
#define __MINIONWITHABILITY_H__
#include "minion.h"
#include "hasAbility.h"
#include <string>
class GameController;
class Player;

class BoneGolem: public Minion, public HasAbilityTriggered{
public:
    BoneGolem(GameController *g, Player* owner, std::string name = "Bone Golem", 
    int cost = 2, int attack = 1, int defense = 3) : 
    Minion{g, owner, name, cost, attack, defense}{}
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override;
    std::string getAbilityDescription() override;
};


class FireElement : public Minion, public HasAbilityTriggered{
public:
    FireElement(GameController* g, Player* owner, std::string name = "Fire Elemental", 
    int cost = 2, int attack = 2, int defense = 2) :  
    Minion{g, owner, name, cost, attack, defense}{}
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override;
};

class PotionSeller: public Minion {
    public:
    PotionSeller(GameController *g, Player* owner, std::string name = "Bone Golem", 
    int cost = 2, int attack = 1, int defense = 3) :  
    Minion{g, owner, name, cost, attack, defense}{}
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override;
};

#endif // __MINIONWITHABILITY_H__