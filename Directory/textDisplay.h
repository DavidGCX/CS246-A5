#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include "adaptor.h"
#include "ascii_graphics.h"
#include <memory>
class Player;

class TextDisplay : public Adaptor {
        void printTitle();
    public:
        TextDisplay(){};
        void init() override;
        void refresh(std::unique_ptr<Player>& playerOne,std::unique_ptr<Player>& playerTwo) override;
};

#endif
