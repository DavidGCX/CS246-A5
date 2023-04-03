#ifndef _CARD_H_
#define _CARD_H_
#include "subject.h"
#include "observer.h"
#include <string>

class Card : public Subject, public Observer {
        std::string name;
        int cost;
    public:
        virtual bool canBePlayed() = 0;
        std::string getName() {return name;}
        int getCost() {return cost;}
};

#endif
