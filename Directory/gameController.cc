#include "gameController.h"
using namespace std;

void GameController::onTurnStart() {
    notifyObservers(StateInfo::onTurnStart);
}

void GameController::onTurnEnd() {
    notifyObservers(StateInfo::onTurnEnd);
}

void GameController::onMinionEnter() {
    notifyObservers(StateInfo::onMinionEnter);
}

void GameController::onMinionExit() {
    notifyObservers(StateInfo::onMinionExit);
}
