#ifndef ENCH_H
#define ENCH_H
#include <string>
#include "card.h"
#include "state.h"
#include "hasAbility.h"
class Minion;
class GameController;
class Player;
class Enchantment: public Card {
public:
    Enchantment(std::string name, int cost, GameController* gameController, Player* owner) : 
    Card{name, cost, gameController, owner}{}
    virtual ~Enchantment() {}
    void notify(StateInfo state) override { return; }
    virtual bool isSimpleADBuff() = 0;
    // 1 for +    2 for * 
    virtual int buffType() { return 1;}
    virtual int buffValueAttack() { return 2; }
    virtual int buffValueDefense()  { return 2; }
    virtual void reverseEffect(Minion* target) = 0;
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override { return; }
    virtual void notifyEnchant(StateInfo stateInfo, Minion* target) { return; }
};

class GiantStrength: public Enchantment, public HasAbilityWithTarget {
public:
    GiantStrength(GameController* gameController, Player* owner, std::string name = "Giant Strength", int cost = 1) :
    Enchantment{name, cost, gameController, owner} {}
    bool isSimpleADBuff() override {return true;};
    int buffType() override { return 1;}
    int buffValueAttack() override { return 2; }
    int buffValueDefense() override { return 2; }
    std::string getDescription() override { return ""; }
    bool useAbility(std::unique_ptr<Minion>& target) override;
    void reverseEffect(Minion* target) override;
};
class Enrage: public Enchantment, public HasAbilityWithTarget {
public:
    Enrage(GameController* gameController, Player* owner, std::string name = "Enrage", int cost = 2) :
    Enchantment{name, cost, gameController, owner} {}
    bool isSimpleADBuff() override {return true;}
    int buffType() override { return 2;}
    int buffValueAttack() override { return 2; }
    int buffValueDefense() override { return 2; }
    std::string getDescription() override { return ""; }
    bool useAbility(std::unique_ptr<Minion>& target) override;
    void reverseEffect(Minion* target) override;
};
class Haste: public Enchantment, public HasAbilityWithTarget {
public:
    Haste(GameController* gameController, Player* owner, std::string name = "Haste", int cost = 1) :
    Enchantment{name, cost, gameController, owner} {}
    bool isSimpleADBuff() override {return false;};
    bool useAbility(std::unique_ptr<Minion>& target) override;
    void reverseEffect(Minion* target) override;
    std::string getDescription() override {
        return "Enchanted minion gains +1 action each turn";
    }
    void notifyEnchant(StateInfo stateInfo, Minion* target) override;
};

class MagicFatigue: public Enchantment, public HasAbilityWithTarget {
public:
    MagicFatigue(GameController* gameController, Player* owner, std::string name = "Magic Fatigue", int cost = 0) :
    Enchantment{name, cost, gameController, owner} {}
    bool isSimpleADBuff() override {return false;};
    bool useAbility(std::unique_ptr<Minion>& target) override;
    std::string getDescription() override {
        return "Enchanted minion's activated ability cost 2 more";
    }
    void reverseEffect(Minion* target) override;
};

class Silence: public Enchantment, public HasAbilityWithTarget {
public:
    Silence(GameController* gameController, Player* owner, std::string name = "Silence", int cost = 1) :
    Enchantment{name, cost, gameController, owner} {}
    bool isSimpleADBuff() override {return false;};
    bool useAbility(std::unique_ptr<Minion>& target) override;
    std::string getDescription() override {
        return "Enchanted minion cannot use abilities";
    }
    void reverseEffect(Minion* target) override;
};



#endif