#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include "adaptor.h"
#include <memory>
class Player;

class TextDisplay : public Adaptor {
    public:
        TextDisplay(){};
        void init() override;
        void refresh(std::unique_ptr<Player>& playerOne,std::unique_ptr<Player>& playerTwo) override;
};

#endif
