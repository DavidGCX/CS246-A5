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
    notifyObservers(StateInfo::onTurnEnd, activePlayer);
    notifyObservers(StateInfo::onTurnEnd, nonActivePlayer);
}

void GameController::onTurnEnd() {
    notifyObservers(StateInfo::onTurnEnd, activePlayer);
    notifyObservers(StateInfo::onTurnEnd, nonActivePlayer);
    swap(activePlayer, nonActivePlayer);
}

void GameController::onMinionEnter() {
    notifyObservers(StateInfo::onTurnEnd, activePlayer);
    notifyObservers(StateInfo::onTurnEnd, nonActivePlayer);
}

void GameController::onMinionExit() {
    notifyObservers(StateInfo::onTurnEnd, activePlayer);
    notifyObservers(StateInfo::onTurnEnd, nonActivePlayer);
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

void GameController::attachPlayers(Player* playerOne, Player* playerTwo) {
    unique_ptr<Player> tempOne{playerOne};
    unique_ptr<Player> tempTwo{playerTwo};
    this->playerOne.swap(tempOne);
    this->playerTwo.swap(tempTwo);
}

void GameController::refreshDisplay() {
    for(auto& adaptor : adaptors) {
        adaptor->refresh(playerOne, playerTwo);
    }
}

void GameController::attackNonActivePlayer(int attack)
{
    (*nonActivePlayer) ->takeDamage(attack);
}
