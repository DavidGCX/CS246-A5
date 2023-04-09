#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <memory>
#include <vector>
#include "minion.h"
#include "state.h"
#include "card.h"
#include "ritual.h"
class GameController;
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
    void play(int i, unique_ptr<Minion>& target);
    void play(int i, unique_ptr<Ritual>& target);
    void use(int i, unique_ptr<Minion>& target);
    void use(int i, unique_ptr<Ritual>& target);
    void use(int i);
    void discarCard(int i);
    void notifyAllCard(StateInfo info);
    bool insideBoardBounday(int i) {return board.size() >= i && i > 0;}
    bool insideHandBounday(int i) {return hand.size() >= i && i > 0;}
    void notifyAllCard(StateInfo info, std::unique_ptr<Minion>& target);
    std::vector<std::unique_ptr<Minion>>& getBoard() { return board; }
    std::vector<std::unique_ptr<Card>>& getHand() { return hand; }
    std::unique_ptr<Ritual>& getRitualField() { return ritualField; }
    // do the boundary check before calling this
    std::unique_ptr<Minion>& getMinionOnBoard(int i);
    int getBoardMinionCount() {return board.size();}
    std::string getName() { return name;}
    int getMagic() { return magic; }
    std::unique_ptr<Minion>* getGraveFieldTop() { 
        if (graveyard.empty()) {
            return nullptr;
        } else {
            return &graveyard.back();
        }
    }
    void sendToBoard(unique_ptr<Minion>&& minion);
    void sendToGrave(unique_ptr<Minion>&& minion);
};

#endif
