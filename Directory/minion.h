#ifndef MIN_H
#define MIN_H
#include "card.h"
#include "hasability.h"
#include <vector>

class Minion: public Card {
    int attack;
    int defense;
    int numactions;
    int remainingactions;
    int magic_cost;
    std::vector<Enchantment> enchants;
public:
    bool canUseAbility;
    Minion(std::string name = "Air Element", int cost = 1, int attack = 1, int defense = 1, int magic_cost = 0);
    bool canBePlayed();
    bool canBeUsed();
    void takeDamage(Minion m);
    void attackPlayer();
    void attackMinion(Minion& m);
    virtual void applyEffect();
    void Inspect();

    void setAttack(int a);
    void setDefense(int d);
    void setActNum(int n);
    void setMagCost(int c);
    void setRemAct(int r = 2);
    int getAttack();
    int getDefense();
    int getActNum();
    int getMagCost();
    int getRemAct();
    ~Minion();
};

class BoneGolem: public Minion, public HasAbility {
    public:
    BoneGolem();
    void useAbility();
};

class PotionSeller: public Minion, public HasAbilityTargetMinion {
    public:
    PotionSeller();
    void useAbility(Minion& m);
};

class NovicePyromancer: public Minion, public HasAbilityTargetMinion {
    public:
    NovicePyromancer();
    bool useAbility(Minion& m);
};

class FireElement: public Minion, public HasAbilityTargetMinion {
    public:
    FireElement();
    void useAbility(Minion& m);
};

class ApprenticeSummoner: public Minion, public HasAbility {
    public:
    ApprenticeSummoner();
    bool useAbility();
};

class MasterSummoner: public Minion, public HasAbility {
    public:
    MasterSummoner();
    bool useAbility();
};

#endif