#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_
#include "subject.h"
#include <memory>
class Player;
class Adaptor;
class GraphicalDisplay;
class TextDisplay;
class Minion;
#include "state.h"
class GameController : public Subject {

    std::vector<unique_ptr<Adaptor>> adaptors;
    std::unique_ptr<Player> playerOne;
    std::unique_ptr<Player> playerTwo;
    std::unique_ptr<Player>* activePlayer;
    std::unique_ptr<Player>* nonActivePlayer;
    bool testMode;
    public:
        GameController(TextDisplay* text);
        GameController(GraphicalDisplay* graphics, TextDisplay* text);
        void attachPlayer(std::string name, int index, std::string deck = "default.deck");
        void attachAdapter(unique_ptr<Adaptor>&&  oneAdaptor);
        void onTurnStart();
        void onTurnEnd();
        void onMinionEnter(std::unique_ptr<Minion>& target);
        void onMinionExit(std::unique_ptr<Minion>& target);
        void refreshDisplay();
        void attackNonActivePlayer(int attack);
        void endTurn();
        //not Finished
        void play(int i);
        void play(int i,  int player, char target);
        void use(int i);
        void use(int i, int player, char target);
        void attack(int i);
        void attack(int i, int j);
        void inspect(int i);
        void hand();
        void board();
        void setTestMode();
        void drawCard();
        void discardCard(int i);
        std::vector<std::unique_ptr<Minion>>& getNonActivePlayerBoard();
};

#endif
