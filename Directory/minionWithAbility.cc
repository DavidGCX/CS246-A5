#include "minionWithAbility.h"
#include "minion.h"
#include <memory>
#include <string>
#include "state.h"
#include "player.h"
#include <iostream>
#include "gameController.h"
using namespace std;

void BoneGolem::notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) {
    if (getState() == State::onBoard) {
        if (stateInfo == StateInfo::onMinionExit) {
            setAttack(getAttack() + 1);
            setDefense(getDefense() + 1);
        }
    }
}
string BoneGolem::getDescription() {
    return "Gain +1/+1 whenever a minion leaves play.";
}

void  FireElemental::notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) {
    if (getState() == State::onBoard) {
        if (target->getOwner() != this->getOwner() && 
        stateInfo == StateInfo::onMinionEnter) {
            target->takeDamage(1);
        }
    }
    
}
string FireElemental::getDescription() {
    return "Whenever an opponent's minion enters play, deal 1 damage to it.";
}

void  PotionSeller::notify(StateInfo stateInfo) {
    Minion::notify(stateInfo);
    if (getState() == State::onBoard) {
        if (gameController->getActivePlayer()->get() == this->getOwner() && 
        stateInfo == StateInfo::onTurnEnd) {
            for(auto& minion : getOwner()->getBoard()) {
                minion->restoreDefense(1);
            }
        }
    }
    
}
string PotionSeller::getDescription() {
    return "At the end of your turn, all your minion gain +0/+1.";
}

string NovicePyromancer::getDescription() {
    return "Deal 1 damage to target minion";
}

bool NovicePyromancer::useAbility(std::unique_ptr<Minion>& target) {
    target->takeDamage(1);
    return true;
}

string ApprenticeSummoner::getDescription() {
    return "Summon a 1/1 air elemental";
}

bool ApprenticeSummoner::useAbility() {
    if (getOwner()->getBoardMinionCount() < 5) {
        getOwner()->getBoard().push_back(make_unique<Minion>(gameController, getOwner()));
        gameController->onMinionEnter(getOwner()->getBoard().back());
        return true;
    } else {
        cerr << "There are already 5 minions on the board, can not summon more" << endl;
        return false;
    }
}

string MasterSummoner::getDescription() {
    return "Summon up to three 1/1 air elementals";
}

bool MasterSummoner::useAbility() {
    if (getOwner()->getBoardMinionCount() < 5) {
        int count = 0;
        while (getOwner()->getBoardMinionCount() < 5 && count < 3) {
            getOwner()->getBoard().push_back(make_unique<Minion>(gameController, getOwner()));
            gameController->onMinionEnter(getOwner()->getBoard().back());
            count++;
        }
        return true;
    } else {
        cerr << "There are already 5 minions on the board, can not summon more" << endl;
        return false;
    }
}