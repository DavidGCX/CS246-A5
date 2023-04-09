#ifndef RIT_H
#define RIT_H
#include "card.h"
//#include "hasability.h"
#include "minion.h"
#include <vector>
#include <string>

class Ritual: public Card {
    int charges;
    int cost_per_charge;

public:
    Ritual(std::string name, int cost, GameController* gameController, Player* owner) : 
    Card{name, cost, gameController, owner}{};
};

#endif