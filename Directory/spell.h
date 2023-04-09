#ifndef SPL_H
#define SPL_H
#include "card.h"
#include <string>

class Spell: public Card {
public:
    Spell(std::string name, int cost, GameController* gameController, Player* owner) : 
    Card{name, cost, gameController, owner}{}
};


#endif