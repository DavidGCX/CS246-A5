#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "subject.h"
#include "card.h"
#include "minion.h"
#include <vector>
class Player : public Observer {
    std::vector<std::unique_ptr<Card>> deck;
    std::vector<std::unique_ptr<Card>> hand;
    std::vector<std::unique_ptr<Minion>> graveyard;
    int magic;
    int health;
    std::string name;
    void init(std::string deck);
public:
    // if deck is specified, initialized that here
    Player(std::string name, std::string deck = "default.deck");
    Player(std::string name);
    void drawCard();
    void damage(int amount);
    bool costMagic(int amount);
    int getHealth();
    void restoreMagic(int amount);
    void restoreHealth(int amount);
};

#endif
