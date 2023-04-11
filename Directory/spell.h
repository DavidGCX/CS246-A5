#ifndef SPL_H
#define SPL_H
#include "card.h"
#include "state.h"
#include <string>
#include <memory>
class Player;
class GameController;
class Minion;
class Spell: public Card {
public:
    Spell(std::string name, int cost, GameController* gameController, Player* owner) : 
    Card{name, cost, gameController, owner}{}
    void notify(StateInfo stateInfo) override { return; }
    void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) override { return; }
};



#endif

