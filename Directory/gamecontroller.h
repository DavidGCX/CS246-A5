#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_
#include "adaptor.h"
#include "subject.h"
#include "observer.h"

class GameController : public Subject, public Observer {
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
