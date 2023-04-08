#ifndef MIN_H
#define MIN_H
#include "card.h"
#include <vector>
#include <memory>
class Enchantment;
class GameController;
class Minion: public Card {
    int attack;
    int defense;
    int numactions;
    int remainingactions;
    vector<unique_ptr<Enchantment>> enchants;
public:
    Minion(GameController *g,Player* owner, std::string name = "Air Element", 
    int cost = 1, int attack = 1, int defense = 1);
    void takeDamage(int amount);
    void attackPlayer();
    void attackMinion(unique_ptr<Minion>& target);
    //virtual void applyEffect();
    //void Inspect();
    void notify(StateInfo state) override;
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override;
    void setAttack(int a);
    void setDefense(int d);
    void setActNum(int n);
    void setRemAct(int r = 2);
    int getAttack();
    int getDefense();
    int getActNum();
    int getRemAct();
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