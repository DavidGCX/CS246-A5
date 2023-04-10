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
private:
    int attack;
    int defense;
    int numActions;
    std::vector<std::unique_ptr<Enchantment>> enchantments;
public:
    Minion(GameController *g,Player* owner, std::string name = "Air Elemental", 
    int cost = 1, int attack = 1, int defense = 1);
    void takeDamage(int amount);
    void attackPlayer();
    void attackMinion(std::unique_ptr<Minion>& target);
    void notify(StateInfo state) override;
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override;
    void setAttack(int a);
    void setDefense(int d);
    void setActNum(int n);
    void restoreDefense(int n) {defense += n;}
    void restoreAttack(int n) {attack += n;}
    void restoreActNum(int n) {numActions += n;}
    int getAttack();
    int getDefense();
    int getActNum();
    void costAct(int n) { numActions -= n;}
    void attachEnchantment(std::unique_ptr<Enchantment>&& from);
    void removeAllEnchantment();
    bool removeTopEnchantment();
    std::vector<std::unique_ptr<Enchantment>>* getEnchantments() {return &enchantments;}
};

#endif