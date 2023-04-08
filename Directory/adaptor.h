#ifndef _ADAPTOR_H_
#define _ADAPTOR_H_
#include "gameController.h"
#include<memory>
class Player;
class Adaptor {
    public:
        Adaptor(){};
        virtual void refresh(std::unique_ptr<Player>& playerOne, std::unique_ptr<Player>& playerTwo) = 0;
        virtual void printHand(std::unique_ptr<Player>& player) = 0;
        virtual void printEnchantments(std::unique_ptr<Minion>& minion) = 0;
};

#endif
