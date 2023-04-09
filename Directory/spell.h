#ifndef SPL_H
#define SPL_H
#include "card.h"
#include "ritual.h"
#include "hasAbility.h"
#include "gameController.h"
#include "minion.h"
#include <vector>
#include <string>

class Spell: public Card {
public:
    Spell(std::string name, int cost, GameController* gameController, Player* owner) : 
    Card{name, cost, gameController, owner}{}
};


#endif