#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <memory>
#include <vector>
#include "minion.h"
class Minion;
class Card;
class Ritual;
class GameController;
enum class StateInfo;
class Player {
    GameController* gameController;
    std::vector<std::unique_ptr<Card>> deck;
    std::vector<std::unique_ptr<Minion>> board;
    std::vector<std::unique_ptr<Card>> hand;
    std::vector<std::unique_ptr<Minion>> graveyard;
    std::unique_ptr<Ritual> ritualField;
    std::vector<std::unique_ptr<Card>> outOfGame;
    int magic;
    int life;
    std::string name;
    void shuffDeck();
public:
    Player(std::string name, GameController* gc, bool testMode, std::string deck = "default.deck");
    void drawCard();
    void takeDamage(int amount);
    bool costMagic(int amount);
    int getHealth() const;
    void restoreMagic(int amount);
    void restoreHealth(int amount);
    // initialize the deck
    void initializeDeck(std::string deck);
    void play(int i);
    void discarCard(int i);
    void notifyAllCard(StateInfo info);
    
    void notifyAllCard(StateInfo info, std::unique_ptr<Minion>& target);
    std::vector<std::unique_ptr<Minion>>& getBoard() { return board; }
    std::vector<std::unique_ptr<Card>>& getHand() { return hand; }
    std::unique_ptr<Ritual>& getRitualField() { return ritualField; }
    std::unique_ptr<Minion>& getMinionOnBoard(int i);
    int getBoardMinionCout() {return board.size();}
};

#endif
