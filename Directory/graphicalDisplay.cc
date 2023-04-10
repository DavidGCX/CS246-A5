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

pair<int,int> GraphicalDisplay::drawDescription(const pair<int,int> coord) {
    pair<int,int> ans;
    ans.first = coord.first + 10;
    ans.second = coord.second + 50;
    return ans;
}

void GraphicalDisplay::refresh(unique_ptr<Player>& playerOne, unique_ptr<Player>& playerTwo) {
    if (playerOne->getRitualField()) {
        wp->fillRectangle(p1ritual.first, p1ritual.second, CARD_W, CARD_H, Xwindow::Red);
        wp->drawString(drawName(p1ritual).first, drawName(p1ritual).second, 
        playerOne->getRitualField()->getName());
        wp->drawString(drawDescription(p1ritual).first, drawDescription(p1ritual).second,
        dynamic_cast<HasAbilityTriggered*>(playerOne->getRitualField().get())->getDescription());
        wp->drawString(drawBottomLeft(p1ritual).first, drawBottomLeft(p1ritual).second,
        to_string(playerOne->getRitualField()->getCost()));
        wp->drawString(drawBottomRight(p1ritual).first, drawBottomRight(p1ritual).second,
        to_string(playerOne->getRitualField()->getCharges()));
    }
    else {
        wp->fillRectangle(p1ritual.first, p1ritual.second, CARD_W, CARD_H, Xwindow::White);
    }

    wp->fillRectangle(p1name.first, p1name.second, CARD_W, CARD_H, Xwindow::Red);
    wp->drawString(drawName(p1name).first, drawName(p1name).second, playerOne->getName());
    wp->drawString(drawBottomLeft(p1name).first, drawBottomLeft(p1name).second, to_string(playerOne->getHealth()));
    wp->drawString(drawBottomRight(p1name).first, drawBottomRight(p1name).second, to_string(playerOne->getMagic()));

    if (playerOne->getGraveFieldTop()){
        wp->fillRectangle(p1grave.first, p1grave.second, CARD_W, CARD_H, Xwindow::Red);
        wp->drawString(drawName(p1grave).first, drawName(p1grave).second,
        playerOne->getGraveFieldTop()->get()->getName());
        // Description
        wp->drawString(drawBottomLeft(p1grave).first, drawBottomLeft(p1grave).second,
        to_string(playerOne->getGraveFieldTop()->get()->getAttack()));
        wp->drawString(drawBottomRight(p1grave).first, drawBottomRight(p1grave).second,
        to_string(playerOne->getGraveFieldTop()->get()->getDefense()));
    }
    else {
        wp->fillRectangle(p1grave.first, p1grave.second, CARD_W, CARD_H, Xwindow::White);
    }
    
    wp->fillRectangle(p1m2.first, p1m2.second, CARD_W, CARD_H, Xwindow::Red);
    wp->fillRectangle(p1m2.first, p1m2.second, CARD_W, CARD_H, Xwindow::Red);
    wp->fillRectangle(p1m3.first, p1m3.second, CARD_W, CARD_H, Xwindow::Red);
    wp->fillRectangle(p1m4.first, p1m4.second, CARD_W, CARD_H, Xwindow::Red);
    wp->fillRectangle(p1m5.first, p1m5.second, CARD_W, CARD_H, Xwindow::Red);

    if (playerOne->getBoardMinionCount() >= 1) {
        wp->drawString(drawName(p1m1).first, drawName(p1m1).second,
            playerOne->getBoard().at(0)->getName());
    }
    if (playerOne->getBoardMinionCount() >= 2) {
        wp->drawString(drawName(p1m2).first, drawName(p1m2).second,
            playerOne->getBoard().at(1)->getName());
    }
    if (playerOne->getBoardMinionCount() >= 3) {
        wp->drawString(drawName(p1m3).first, drawName(p1m3).second,
            playerOne->getBoard().at(2)->getName());
    }
    if (playerOne->getBoardMinionCount() >= 4) {
        wp->drawString(drawName(p1m4).first, drawName(p1m4).second,
            playerOne->getBoard().at(3)->getName());
    }
    if (playerOne->getBoardMinionCount() >= 5) {
        wp->drawString(drawName(p1m5).first, drawName(p1m5).second,
            playerOne->getBoard().at(4)->getName());
    }

    wp->fillRectangle(p2m1.first, p2m1.second, CARD_W, CARD_H, Xwindow::Blue);
    wp->fillRectangle(p2m2.first, p2m2.second, CARD_W, CARD_H, Xwindow::Blue);
    wp->fillRectangle(p2m3.first, p2m3.second, CARD_W, CARD_H, Xwindow::Blue);
    wp->fillRectangle(p2m4.first, p2m4.second, CARD_W, CARD_H, Xwindow::Blue);
    wp->fillRectangle(p2m5.first, p2m5.second, CARD_W, CARD_H, Xwindow::Blue);

    if (playerTwo->getBoardMinionCount() >= 1) {
        wp->drawString(drawName(p2m1).first, drawName(p2m1).second,
            playerTwo->getBoard().at(0)->getName());
    }
    if (playerTwo->getBoardMinionCount() >= 2) {
        wp->drawString(drawName(p2m2).first, drawName(p2m2).second,
            playerTwo->getBoard().at(1)->getName());
    }
    if (playerTwo->getBoardMinionCount() >= 3) {
        wp->drawString(drawName(p2m3).first, drawName(p2m3).second,
            playerTwo->getBoard().at(2)->getName());
    }
    if (playerTwo->getBoardMinionCount() >= 4) {
        wp->drawString(drawName(p2m4).first, drawName(p2m4).second,
            playerTwo->getBoard().at(3)->getName());
    }
    if (playerTwo->getBoardMinionCount() >= 5) {
        wp->drawString(drawName(p2m5).first, drawName(p2m5).second,
            playerTwo->getBoard().at(4)->getName());
    }

    if (playerTwo->getRitualField()) {
        wp->fillRectangle(p2ritual.first, p2ritual.second, CARD_W, CARD_H, Xwindow::Blue);
        wp->drawString(drawName(p2ritual).first, drawName(p2ritual).second, 
        playerTwo->getRitualField()->getName());
        wp->drawString(drawDescription(p2ritual).first, drawDescription(p2ritual).second,
        dynamic_cast<HasAbilityTriggered*>(playerTwo->getRitualField().get())->getDescription());
        wp->drawString(drawBottomLeft(p2ritual).first, drawBottomLeft(p2ritual).second,
        to_string(playerTwo->getRitualField()->getCost()));
        wp->drawString(drawBottomRight(p2ritual).first, drawBottomRight(p2ritual).second,
        to_string(playerTwo->getRitualField()->getCharges()));
    }
    else {
        wp->fillRectangle(p2ritual.first, p2ritual.second, CARD_W, CARD_H, Xwindow::White);
    }

    wp->fillRectangle(p2name.first, p2name.second, CARD_W, CARD_H, Xwindow::Blue);
    wp->drawString(drawName(p2name).first, drawName(p2name).second, playerTwo->getName());
    wp->drawString(drawBottomLeft(p2name).first, drawBottomLeft(p2name).second, to_string(playerTwo->getHealth()));
    wp->drawString(drawBottomRight(p2name).first, drawBottomRight(p2name).second, to_string(playerTwo->getMagic()));

    if (playerOne->getGraveFieldTop()){
        wp->fillRectangle(p2grave.first, p2grave.second, CARD_W, CARD_H, Xwindow::Blue);
        wp->drawString(drawName(p2grave).first, drawName(p2grave).second,
        playerTwo->getGraveFieldTop()->get()->getName());
        // Description
        wp->drawString(drawBottomLeft(p2grave).first, drawBottomLeft(p2grave).second,
        to_string(playerTwo->getGraveFieldTop()->get()->getAttack()));
        wp->drawString(drawBottomRight(p2grave).first, drawBottomRight(p2grave).second,
        to_string(playerTwo->getGraveFieldTop()->get()->getDefense()));
    }
    else {
        wp->fillRectangle(p2grave.first, p2grave.second, CARD_W, CARD_H, Xwindow::White);
    }

    wp->drawString(25, 640, "Active Player Hand:");

    wp->fillRectangle(hand1.first, hand1.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand2.first, hand2.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand3.first, hand3.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand4.first, hand4.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand5.first, hand5.second, CARD_W, CARD_H, Xwindow::Green);
    // active player hand
}

void GraphicalDisplay::printHand(unique_ptr<Player>& player) {
    wp->fillRectangle(hand1.first, hand1.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand2.first, hand2.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand3.first, hand3.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand4.first, hand4.second, CARD_W, CARD_H, Xwindow::Green);
    wp->fillRectangle(hand5.first, hand5.second, CARD_W, CARD_H, Xwindow::Green);

    int handSize = player->getHand().size();
    if (handSize>=1) {
        wp->drawString(drawName(hand1).first, drawName(hand1).second,
        player->getHand().at(0)->getName());
    }
    if (handSize>=2) {
        wp->drawString(drawName(hand2).first, drawName(hand2).second,
        player->getHand().at(1)->getName());
    }
    if (handSize>=3) {
        wp->drawString(drawName(hand3).first, drawName(hand3).second,
        player->getHand().at(2)->getName());
    }
    if (handSize>=4) {
        wp->drawString(drawName(hand4).first, drawName(hand4).second,
        player->getHand().at(3)->getName());
    }
    if (handSize>=1) {
        wp->drawString(drawName(hand5).first, drawName(hand5).second,
        player->getHand().at(4)->getName());
    }
}

void GraphicalDisplay::printEnchantments(unique_ptr<Minion>& minion) {
    wp->drawString(WIDTH,HEIGHT,"enchantments");
}
