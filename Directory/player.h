#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "subject.h"
#include "card.h"
#include "minion.h"

class Player : public Subject {
    bool isActive;
    Card* deck;
    Card* hand;
    Minion* graveyard;
    int numActions;

    public:
        void init();
        bool isActivePlayer() {return isActive;}
};

#endif
