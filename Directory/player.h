#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <memory>
#include <vector>
class Minion;
class Card;
class Ritual;
class GameController;
enum class StateInfo;
class Player {
    GameController* gameController;
    std::vector<std::unique_ptr<Card>> deck;
    std::vector<std::unique_ptr<Card>> board;
    std::vector<std::unique_ptr<Card>> hand;
    std::vector<std::unique_ptr<Minion>> graveyard;
    std::unique_ptr<Ritual> ritualField;
    std::vector<std::unique_ptr<Card>> outOfGame;
    int magic;
    int life;
    std::string name;
public:
    Player(std::string name, GameController* gc, std::string deck = "default.deck");
    void drawCard();
    void takeDamage(int amount);
    bool costMagic(int amount);
    int getHealth();
    void restoreMagic(int amount);
    void restoreHealth(int amount);
    // initialize the deck
    void initializeDeck(std::string deck);
    void play(int i);
    void notifyAllCard(StateInfo info);
<<<<<<< HEAD
    void notifyAllCard(StateInfo info, std::unique_ptr<Minion>& target);
=======
    void notifyAllCard(StateInfo info, unique_ptr<Minion>& target);
    void setName(std::string name);
>>>>>>> edb411b37f1aae2ca45b4928333db2d0b6d2e5ce
};

#endif
