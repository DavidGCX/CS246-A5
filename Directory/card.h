#ifndef _CARD_H_
#define _CARD_H_
#include "subject.h"
#include "observer.h"

class Card : public Subject, public Observer {
        string name;
        int cost;
    public:
        virtual bool canBePlayed() = 0;
        string getName() {return name;}
        int getCost() {return cost;}
};

#endif
