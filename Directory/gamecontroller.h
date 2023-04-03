#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_
#include "adaptor.h"
#include "subject.h"
#include "observer.h"
#include <memory>
class player;
struct InternalData{ 
    std::unique_ptr<player> playerOne;
    std::unique_ptr<player> playerTwo;
};

enum class StateInfo {
    onTurnStart,
    onTurnEnd,
    onMinionEnter,
    onMinionExit
};
class GameController : public Subject {
    bool useGraphics;
    std::unique_ptr<Adaptor> graphics;
    std::unique_ptr<Adaptor> text;
    std::unique_ptr<player> playerOne;
    std::unique_ptr<player> playerTwo;
    public:
        GameController(Adaptor* graphics, Adaptor* text, player* playerOne, player* playerTwo) : 
        graphics{graphics}, text{text}, playerOne{playerOne}, playerTwo{playerTwo} {
            if (graphics == nullptr) {
                useGraphics = false;
            } else {
                useGraphics = true;
            }
        }
        void onTurnStart();
        void onTurnEnd();
        void onMinionEnter();
        void onMinionExit();
};

#endif
