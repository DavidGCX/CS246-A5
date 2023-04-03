#ifndef _GRAPHICALDISPLAY_H_
#define _GRAPHICALDISPLAY_H_
#include "adaptor.h"
#include <memory>
class Player;

class GraphicalDisplay : public Adaptor {
    public:
    GraphicalDisplay(){}
        void init() override;
        void refresh(std::unique_ptr<Player>& playerOne, std::unique_ptr<Player>& playerTwo) override;
};

#endif