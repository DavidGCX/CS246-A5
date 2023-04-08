#ifndef ENCH_H
#define ENCH_H
#include <string>
#include "card.h"
#include "state.h"
class Minion;
class Enchantment: public Card {
public:
    Enchantment(std::string name, int cost, GameController* gameController, Player* owner) : 
    Card{name, cost, gameController, owner}{}
    virtual ~Enchantment() {}
    void notify(StateInfo state) override { return; }
    virtual void applyEffect(Minion& target) = 0;
    virtual void reverseEffect(Minion& target) = 0;
};


/*
class GiantStrength: {
    std::string name;
    public:
    GiantStrength(Minion *m);
    void Inspect();
    void applyEffect();
};

class Enrage: public EnchantmentDecorator {
    std::string name;
    public:
    Enrage(Minion *m);
    void Inspect();
    void applyEffect();
};

class Silence: public EnchantmentDecorator {
    std::string name;
    public:
    Silence(Minion *m);
    void Inspect();
    void applyEffect();
};

class Haste: public EnchantmentDecorator {
    std::string name;
    public:
    Haste(Minion *m);
    void Inspect();
    void applyEffect();
};

class MagicFatigue: public EnchantmentDecorator {
    std::string name;
    public:
    MagicFatigue(Minion *m);
    void Inspect();
    void applyEffect();
};
*/
#endif