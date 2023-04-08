#ifndef _GRAPHICALDISPLAY_H_
#define _GRAPHICALDISPLAY_H_
#include "adaptor.h"
#include <memory>
class Player;

class GraphicalDisplay : public Adaptor {
    public:
        GraphicalDisplay(){}
        void refresh(std::unique_ptr<Player>& playerOne, std::unique_ptr<Player>& playerTwo) override;
        void printHand(std::unique_ptr<Player>& player) override;
        void printEnchantments(std::unique_ptr<Minion>& minion) override;
};

#endif