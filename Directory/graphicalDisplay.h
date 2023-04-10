#ifndef _GRAPHICALDISPLAY_H_
#define _GRAPHICALDISPLAY_H_
#include "adaptor.h"
#include "window.h"
#include <memory>
#include <utility>
class Player;

class GraphicalDisplay : public Adaptor {
    const int CARD_W = 200;
    const int CARD_H = 125;
    const int BORDER_W = 25;
    const std::pair<int, int> p1ritual = std::make_pair(25, 25);
    const std::pair<int, int> p1name = std::make_pair(475, 25);
    const std::pair<int, int> p1grave = std::make_pair(925, 25);
    const std::pair<int, int> p1m1 = std::make_pair(25, 175);
    const std::pair<int, int> p1m2 = std::make_pair(250, 175);
    const std::pair<int, int> p1m3 = std::make_pair(475, 175);
    const std::pair<int, int> p1m4 = std::make_pair(700, 175);
    const std::pair<int, int> p1m5 = std::make_pair(925, 175);

    const std::pair<int, int> p2m1 = std::make_pair(25, 340);
    const std::pair<int, int> p2m2 = std::make_pair(250, 340);
    const std::pair<int, int> p2m3 = std::make_pair(475, 340);
    const std::pair<int, int> p2m4 = std::make_pair(700, 340);
    const std::pair<int, int> p2m5 = std::make_pair(925, 340);
    const std::pair<int, int> p2ritual = std::make_pair(25, 490);
    const std::pair<int, int> p2name = std::make_pair(475, 490);
    const std::pair<int, int> p2grave = std::make_pair(925, 490);

    const std::pair<int, int> hand1 = std::make_pair(25, 650);
    const std::pair<int, int> hand2 = std::make_pair(250, 650);
    const std::pair<int, int> hand3 = std::make_pair(475, 650);
    const std::pair<int, int> hand4 = std::make_pair(700, 650);
    const std::pair<int, int> hand5 = std::make_pair(925, 650);

    const int WIDTH = 1250;
    const int HEIGHT = 800;
    Xwindow* wp;
    Xwindow w{WIDTH, HEIGHT};

    std::pair<int,int> drawName(const std::pair<int,int> coord);
    std::pair<int,int> drawBottomLeft(const std::pair<int,int> coord);
    std::pair<int,int> drawBottomRight(const std::pair<int,int> coord);
    std::pair<int,int> drawDescription(const std::pair<int,int> coord);

    public:
        GraphicalDisplay();
        void refresh(std::unique_ptr<Player>& playerOne, std::unique_ptr<Player>& playerTwo) override;
        void printHand(std::unique_ptr<Player>& player) override;
        void printEnchantments(std::unique_ptr<Minion>& minion) override;
};

#endif