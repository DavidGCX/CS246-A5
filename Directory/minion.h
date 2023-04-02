#ifndef MIN_H
#define MIN_H
#include "card.h"
#include <vector>

class Minion: public Card {
    int attack;
    int defense;
    bool hasAction;
    vector<Enchantment> enchants;
public:
    Minion(std::string name = "Air Element", int cost = 1, int attack = 1, int defense = 1);
    bool canBePlayed();
    void takeDamage();
    void attackPlayer();
    void attackMinion(Minion& m);
    void applyEffect();
    void Inspect();

    void setAttack();
    void setDefense();
    void getAttack();
    void getDefense();
    ~Minion();
}

class BoneGolem: public Minion {
    public:
    BoneGolem(int attack, int defense);
    void useAbility();
}

class PotionSeller: public Minion {
    public:
    PotionSeller(int attack, int defense);
    void useAbility(Minion& m);
}

class NovicePyromancer: public Minion {
    public:
    NovicePyromancer(int attack, int defense);
    bool useAbility(Minion& m);
}

class FireElement: public Minion {
    public:
    FireElement(int attack, int defense);
    void useAbility(Minion& m);
}

class ApprenticeSummoner: public Minion {
    public:
    ApprenticeSummoner(int attack, int defense);
    bool useAbility();
}

class MasterSummoner: public Minion {
    public:
    MasterSummonder(int attack, int defense);
    bool useAbility();
}

#endif