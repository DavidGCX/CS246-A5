#include "gameController.h"
#include <utility>
#include "player.h"
#include "graphicalDisplay.h"
#include "textDisplay.h"
#include <memory>
using namespace std;

void GameController::onTurnStart() {
    (*activePlayer)->restoreMagic(1);
    (*activePlayer)->drawCard();
    notifyObservers(StateInfo::onTurnStart, activePlayer);
    notifyObservers(StateInfo::onTurnStart, nonActivePlayer);
}

void GameController::onTurnEnd() {
    notifyObservers(StateInfo::onTurnEnd, activePlayer);
    notifyObservers(StateInfo::onTurnEnd, nonActivePlayer);
}

void GameController::onMinionEnter() {
    notifyObservers(StateInfo::onMinionEnter, activePlayer);
    notifyObservers(StateInfo::onMinionEnter, nonActivePlayer);
}

void GameController::onMinionExit() {
    notifyObservers(StateInfo::onMinionExit, activePlayer);
    notifyObservers(StateInfo::onMinionExit, nonActivePlayer);
}

GameController::GameController(GraphicalDisplay *graphics, TextDisplay *text) {
    if (graphics == nullptr) {
        unique_ptr<TextDisplay> td{text};
        adaptors.push_back(move(td));
    } else {
        unique_ptr<TextDisplay> td{text};
        unique_ptr<GraphicalDisplay> gd{graphics};
        adaptors.push_back(move(td));
        adaptors.push_back(move(gd));
    }
    activePlayer = &this->playerOne;
    nonActivePlayer = &this->playerTwo;
}

void GameController::attachPlayer(string name, int index, string deck) {
    switch(index) {
        case 1 :
            playerOne = make_unique<Player>(name, this, deck);
            break;
        case 2 :
            playerTwo = make_unique<Player>(name, this, deck);
            break;
    }
}

void GameController::refreshDisplay() {
    for(auto& adaptor : adaptors) {
        adaptor->refresh(playerOne, playerTwo);
    }
}

void GameController::attackNonActivePlayer(int attack)
{
    (*nonActivePlayer)->takeDamage(attack);
}

void GameController::play(int i) {
    (*activePlayer)->play(i);
}

void GameController::endTurn() {
    onTurnEnd();
    swap(activePlayer, nonActivePlayer);
}
