#ifndef _ADAPTOR_H_
#define _ADAPTOR_H_
#include "gameController.h"
#include<memory>
class Player;
class Adaptor {
    public:
        Adaptor(){};
        virtual void init() = 0;
        virtual void refresh(std::unique_ptr<Player>& playerOne, std::unique_ptr<Player>& playerTwo) = 0;
};

#endif
