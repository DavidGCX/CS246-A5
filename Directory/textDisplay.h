#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include "adaptor.h"
#include "ascii_graphics.h"
#include <memory>
class Player;

class TextDisplay : public Adaptor {
        const int NUM_LINES = 11;
        const int NUM_CHARS = 165;
        void printRow(const vector<vector<string>>& v);
        void printTopBorder();
        void printBottomBorder();
        void printBoard();
    public:
        TextDisplay(){};
        void init() override;
        void refresh(std::unique_ptr<Player>& playerOne,std::unique_ptr<Player>& playerTwo) override;
};

#endif
