#ifndef MIN_H
#define MIN_H
#include "card.h"
#include <vector>

class GameController;
class Minion: public Card {
    int attack;
    int defense;
    int numactions;
    int remainingactions;
    //int magic_cost;
    //std::vector<Enchantment> enchants;
public:
    //bool canUseAbility;

    Minion(GameController *g,Player* owner, std::string name = "Air Element", 
    int cost = 1, int attack = 1, int defense = 1);
    
    //bool canBePlayed();
    //bool canBeUsed();

    void takeDamage(Minion& m);
    void attackPlayer();

    void attackMinion(Minion& m);
    //virtual void applyEffect();
    //void Inspect();

    void notify(StateInfo state) override;
    void setAttack(int a);
    void setDefense(int d);
    void setActNum(int n);
    void setRemAct(int r = 2);
    int getAttack();
    int getDefense();
    int getActNum();
    int getRemAct();

    //int getMagCost();
    //void setMagCost(int c);
    
};

/*
class BoneGolem: public Minion, public HasAbility {
    public:
    BoneGolem(GameController *g);
    bool useAbility();
};

class PotionSeller: public Minion, public HasAbilityTargetMinion {
    public:
    PotionSeller(GameController *g);
    bool useAbility(Minion& m);
};

class NovicePyromancer: public Minion, public HasAbilityTargetMinion {
    public:
    NovicePyromancer(GameController *g);
    bool useAbility(Minion& m);
};

class FireElement: public Minion, public HasAbilityTargetMinion {
    public:
    FireElement(GameController *g);
    bool useAbility(Minion& m);
};

class ApprenticeSummoner: public Minion, public HasAbility {
    public:
    ApprenticeSummoner(GameController *g);
    bool useAbility();
};

class MasterSummoner: public Minion, public HasAbility {
    public:
    MasterSummoner(GameController *g);
    bool useAbility();
};
*/
#endif