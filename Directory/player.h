#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "observer.h"
#include <string>
#include <memory>
#include <vector>
class Minion;
class Card;
class Ritual;
class Player : public Observer {
    std::vector<std::unique_ptr<Card>> deck;
    std::vector<std::unique_ptr<Card>> hand;
    std::vector<std::unique_ptr<Minion>> graveyard;
    std::unique_ptr<Ritual> ritualField;
    std::vector<std::unique_ptr<Card>> outOfGame;
    int magic;
    int life;
    std::string name;
    void init(std::string deck);
public:
    
    Player(std::string name, std::string deck = "default.deck");
    Player(std::string name);
    void drawCard();
    void damage(int amount);
    bool costMagic(int amount);
    int getHealth();
    void restoreMagic(int amount);
    void restoreHealth(int amount);
    // initialize the deck
    void initializeDeck(std::string deck);
    void play(int i);
};

#endif
