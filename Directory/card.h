#ifndef _CARD_H_
#define _CARD_H_
#include "subject.h"
#include "observer.h"
#include <string>

class gameController;


// so for minions, they can only be in first three states, but for spells, 
// rituls and enchantments, if they are out of scope, then they are simply
// removed from the game;
enum class State {
    onDeck,
    onHand,
    onGraveYard,
    removeFromTheGame
};
class Card : public Observer {
        gameController* gc;
        std::string name;
        int cost;
        State state;
    public:
        Card(std::string name, int cost, gameController* gameController):name{name}, cost{cost}, gc{gameController} {
            state = State::onDeck; // by default, all cards are in deck;
        }
        virtual bool canBePlayed() = 0;
        std::string getName() {return name;}
        int getCost() {return cost;}
};

#endif
