#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_
#include "adaptor.h"

class GameController {
    Adaptor* graphics;
    Adaptor* text;
    public:
        void init();
        void onTurnStart();
        void onTurnEnd();
        void onMinionEnter();
        void onMinionExit();
};

#endif
