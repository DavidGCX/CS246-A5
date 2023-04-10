#include "ritualAbility.h"
#include "gameController.h"
#include "ritual.h"
#include <memory>
#include <string>
#include "state.h"
#include "player.h"
#include <iostream>
using namespace std;
void DarkRitual::notify(StateInfo stateInfo) {
    if (getState() == State::onBoard) {
        if (stateInfo == StateInfo::onTurnStart &&
        gameController->getActivePlayer()->get() == getOwner()) {
            if (useRitual()) {
                getOwner()->restoreMagic(1);
            }
        }
    }
}
string DarkRitual::getDescription() {
    return "At the start of your turn, gain 1 magic";
}

void AuraOfPower::notify(StateInfo stateInfo, unique_ptr<Minion>& target) {
    if (getState() == State::onBoard) {
        if (stateInfo == StateInfo::onMinionEnter &&
        target->getOwner() == this->getOwner()) {
            if (useRitual()) {
                target->restoreAttack(1);
                target->restoreDefense(1);
            }
        }
    }
}
string AuraOfPower::getDescription() {
    return "Whenever a minion enters play under your control, it gian +1/+1";
}

void StandStill::notify(StateInfo stateInfo, unique_ptr<Minion>& target) {
    if (getState() == State::onBoard) {
        if (stateInfo == StateInfo::onMinionEnter) {
            if (useRitual()) {
                int i = 0;
                vector<std::unique_ptr<Minion>>& board = target->getOwner()->getBoard();
                for (auto& minion : board) {
                    if (minion.get() == target.get()) {
                        target->getOwner()->sendToGrave(target);
                        board.erase(board.begin() + i);
                        break;
                    }
                    i++;
                }
            }
        }
    }
}
string StandStill::getDescription() {
    return "Whenever a minion enters play, destroy it";
}