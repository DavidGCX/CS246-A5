#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_
#include "subject.h"
#include <memory>
class Player;
class Adapter;
class GraphicalDisplay;
class TextDisplay;
enum class StateInfo {
    onTurnStart,
    onTurnEnd,
    onMinionEnter,
    onMinionExit
};
class GameController : public Subject {

    std::vector<unique_ptr<Adaptor>> adaptors;
    std::unique_ptr<Player> playerOne;
    std::unique_ptr<Player> playerTwo;
    std::unique_ptr<Player>* activePlayer;
    std::unique_ptr<Player>* nonActivePlayer;

    public:
        GameController(GraphicalDisplay* graphics, TextDisplay* text, 
        Player* playerOne, Player* playerTwo);
        void onTurnStart();
        void onTurnEnd();
        void onMinionEnter();
        void onMinionExit();
        void refreshDisplay();
};

#endif
