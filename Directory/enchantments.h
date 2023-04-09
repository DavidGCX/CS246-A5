#ifndef ENCH_H
#define ENCH_H
#include <string>
#include "card.h"
#include "state.h"
#include "hasAbility.h"
class Minion;
class GameController;
class Enchantment: public Card {
public:
    Enchantment(std::string name, int cost, GameController* gameController, Player* owner) : 
    Card{name, cost, gameController, owner}{}
    virtual ~Enchantment() {}
    void notify(StateInfo state) override { return; }
    virtual bool isSimpleADBuff() = 0;
    virtual void reverseEffect(Minion* target) = 0;
};

class GiantStrength: public Enchantment, public HasAbilityWithTarget {
public:
    GiantStrength(std::string name, int cost, GameController* gameController, Player* owner) :
    Enchantment{name, cost, gameController, owner} {}
    bool useAbility(std::unique_ptr<Minion>& target) override;
    void reverseEffect(Minion* target) override;
};

#endif