#ifndef MIN_H
#define MIN_H
#include "card.h"
#include <vector>
#include <memory>
#include "state.h"
#include "enchantments.h"
#include <string>
class GameController;
class Player;
class Minion: public Card {
protected:
    int attack;
    int defense;
    int numActions;
    std::vector<std::unique_ptr<Enchantment>> enchantments;
public:
    Minion(GameController *g,Player* owner, std::string name = "Air Elemental", 
    int cost = 1, int attack = 1, int defense = 1);
    void takeDamage(int amount);
    void attackPlayer();
    void attackMinion(unique_ptr<Minion>& target);
    void notify(StateInfo state) override;
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override;
    void setAttack(int a);
    void setDefense(int d);
    void setActNum(int n);
    void restoreDefense(int n) {defense += n;}
    void restoreAttack(int n) {attack += n;}
    int getAttack();
    int getDefense();
    int getActNum();
    void costAct(int n) { numActions -= n;}
    void attachEnchantment(unique_ptr<Enchantment>&& from);
    void removeAllEnchantment();
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