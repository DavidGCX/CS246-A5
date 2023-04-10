#include "graphicalDisplay.h"
#include <memory>
#include "player.h"
using namespace std;

GraphicalDisplay::GraphicalDisplay(): wp{&w} {
    wp->drawString(565, 325, "SORCERY");
}

pair<int,int> GraphicalDisplay::drawName(const pair<int,int> coord) {
    pair<int,int> ans;
    ans.first = coord.first + 10;
    ans.second = coord.second + 15;
    return ans;
}

pair<int,int> GraphicalDisplay::drawBottomLeft(const pair<int,int> coord) {
    pair<int,int> ans;
    ans.first = coord.first + 10;
    ans.second = coord.second + 120;
    return ans;
}

pair<int,int> GraphicalDisplay::drawBottomRight(const pair<int,int> coord) {
    pair<int,int> ans;
    ans.first = coord.first + 190;
    ans.second = coord.second + 120;
    return ans;
}

void GraphicalDisplay::refresh(unique_ptr<Player>& playerOne, unique_ptr<Player>& playerTwo) {
    wp->fillRectangle(p1ritual.first, p1ritual.second, CARD_W, CARD_H, Xwindow::Red);

    wp->fillRectangle(p1name.first, p1name.second, CARD_W, CARD_H, Xwindow::Red);
    wp->drawString(drawName(p1name).first, drawName(p1name).second, playerOne->getName());
    wp->drawString(drawBottomLeft(p1name).first, drawBottomLeft(p1name).second, to_string(playerOne->getHealth()));
    wp->drawString(drawBottomRight(p1name).first, drawBottomRight(p1name).second, to_string(playerOne->getMagic()));

    wp->fillRectangle(p1grave.first, p1grave.second, CARD_W, CARD_H, Xwindow::Red);

    wp->fillRectangle(p1m1.first, p1m1.second, CARD_W, CARD_H, Xwindow::Red);
    wp->fillRectangle(p1m2.first, p1m2.second, CARD_W, CARD_H, Xwindow::Red);
    wp->fillRectangle(p1m3.first, p1m3.second, CARD_W, CARD_H, Xwindow::Red);
    wp->fillRectangle(p1m4.first, p1m4.second, CARD_W, CARD_H, Xwindow::Red);
    wp->fillRectangle(p1m5.first, p1m5.second, CARD_W, CARD_H, Xwindow::Red);

    wp->fillRectangle(p2m1.first, p2m1.second, CARD_W, CARD_H, Xwindow::Blue);
    wp->fillRectangle(p2m2.first, p2m2.second, CARD_W, CARD_H, Xwindow::Blue);
    wp->fillRectangle(p2m3.first, p2m3.second, CARD_W, CARD_H, Xwindow::Blue);
    wp->fillRectangle(p2m4.first, p2m4.second, CARD_W, CARD_H, Xwindow::Blue);
    wp->fillRectangle(p2m5.first, p2m5.second, CARD_W, CARD_H, Xwindow::Blue);

    wp->fillRectangle(p2ritual.first, p2ritual.second, CARD_W, CARD_H, Xwindow::Blue);

    wp->fillRectangle(p2name.first, p2name.second, CARD_W, CARD_H, Xwindow::Blue);
    wp->drawString(drawName(p2name).first, drawName(p2name).second, playerTwo->getName());
    wp->drawString(drawBottomLeft(p2name).first, drawBottomLeft(p2name).second, to_string(playerTwo->getHealth()));
    wp->drawString(drawBottomRight(p2name).first, drawBottomRight(p2name).second, to_string(playerTwo->getMagic()));

    wp->fillRectangle(p2grave.first, p2grave.second, CARD_W, CARD_H, Xwindow::Blue);

    wp->drawString(25, 640, "Active Player Hand:");

    wp->fillRectangle(hand1.first, hand1.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand2.first, hand2.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand3.first, hand3.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand4.first, hand4.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand5.first, hand5.second, CARD_W, CARD_H, Xwindow::Green);
    // active player hand
}
