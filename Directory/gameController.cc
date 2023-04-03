#include "gameController.h"
#include <utility>
#include "player.h"
#include "graphicalDisplay.h"
#include "textDisplay.h"
using namespace std;

void GameController::onTurnStart() {
    (*activePlayer)->restoreMagic(1);
    (*activePlayer)->drawCard();
    notifyObservers(StateInfo::onTurnStart);
}

void GameController::onTurnEnd() {
    notifyObservers(StateInfo::onTurnEnd);
    swap(activePlayer, nonActivePlayer);
}

void GameController::onMinionEnter() {
    notifyObservers(StateInfo::onMinionEnter);
}

void GameController::onMinionExit() {
    notifyObservers(StateInfo::onMinionExit);
}

GameController::GameController(GraphicalDisplay *graphics, TextDisplay *text, 
Player *playerOne, Player *playerTwo) : playerOne{playerOne}, playerTwo{playerTwo} {
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

void GameController::refreshDisplay() {
    for(auto& adaptor : adaptors) {
        adaptor->refresh(playerOne, playerTwo);
    }
}