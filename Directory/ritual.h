#ifndef RIT_H
#define RIT_H
#include "card.h"
//#include "hasability.h"
#include <vector>
#include <string>

class Ritual: public Card {
    int charges;
    int cost_per_charge;
public:
    Ritual(std::string name, int cost, GameController* gameController, Player* owner,
    int charges, int cost_per_charge) :
    Card{name, cost, gameController, owner}, charges{charges}, cost_per_charge{cost_per_charge} {}
    void restoreCharges(int n) { charges += n; }
};

#endif