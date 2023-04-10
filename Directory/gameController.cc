#include "gameController.h"
#include <utility>
#include "player.h"
#include "graphicalDisplay.h"
#include "textDisplay.h"
#include <memory>
#include <iostream>
using namespace std;

void GameController::onTurnStart() {
    (*activePlayer)->restoreMagic(1);
    (*activePlayer)->drawCard();
    notifyObservers(StateInfo::onTurnStart, activePlayer);
    notifyObservers(StateInfo::onTurnStart, nonActivePlayer);
    cleanUpBoard();
}

void GameController::onTurnEnd() {
    notifyObservers(StateInfo::onTurnEnd, activePlayer);
    notifyObservers(StateInfo::onTurnEnd, nonActivePlayer);
    cleanUpBoard();
}

void GameController::onMinionEnter(unique_ptr<Minion>& target) {
    notifyObservers(StateInfo::onMinionEnter, activePlayer, target);
    notifyObservers(StateInfo::onMinionEnter, nonActivePlayer, target);
}

void GameController::onMinionExit(unique_ptr<Minion>& target) {
    notifyObservers(StateInfo::onMinionExit, activePlayer, target);
    notifyObservers(StateInfo::onMinionExit, nonActivePlayer,  target);
}
/*
GameController::GameController(GraphicalDisplay *graphics, TextDisplay *text) {
    unique_ptr<TextDisplay> td{text};
    unique_ptr<GraphicalDisplay> gd{graphics};
    adaptors.push_back(move(td));
    adaptors.push_back(move(gd));
    activePlayer = &this->playerOne;
    nonActivePlayer = &this->playerTwo;
}

GameController::GameController(TextDisplay *text) {
    unique_ptr<TextDisplay> td{text};
    adaptors.push_back(move(td));
    activePlayer = &this->playerOne;
    nonActivePlayer = &this->playerTwo;
}
*/
void GameController::attachAdapter(unique_ptr<Adaptor>&& oneAdaptor) {
    adaptors.push_back(move(oneAdaptor));
}

void GameController::attachPlayer(string name, int index, string deck) {
    
    switch(index) {
        case 1 :
            playerOne = make_unique<Player>(name, this, testMode, deck);
            activePlayer = &this->playerOne;
            break;
        case 2 :
            playerTwo = make_unique<Player>(name, this, testMode, deck);
            nonActivePlayer = &this->playerTwo;
            break;
    }
}

void GameController::refreshDisplay() {
    for(auto& adaptor : adaptors) {
        adaptor->refresh(playerOne, playerTwo);
    }
}
bool GameController::gameEnd () {
    if ((*nonActivePlayer)->getHealth() <= 0) {
        cout << (*activePlayer)->getName() << " win!"<< endl;
        return true;
    } else {
        return false;
    }
}
void GameController::attackNonActivePlayer(int attack)
{
    (*nonActivePlayer)->takeDamage(attack);
}

void GameController::endTurn() {
    onTurnEnd();
    swap(activePlayer, nonActivePlayer);
    cout << (*activePlayer)->getName() << " Turn"<< endl;
    onTurnStart();
}

void GameController::play(int i) {
    (*activePlayer)->play(i);
    cleanUpBoard();
}

void GameController::play(int i, int player, int target) {
    if (player == 1) {
        if (target == 6) {
            (*activePlayer)->play(i, playerOne->getRitualField());
        } else {
            if (playerOne->insideBoardBounday(target)) {
                (*activePlayer)->play(i, playerOne->getMinionOnBoard(target));
            } else {
                cerr << "No Target At Given Position" << endl;
            }
        }
    } else {
        if (target == 6) {
            (*activePlayer)->play(i, playerTwo->getRitualField());
        } else {
            if (playerTwo->insideBoardBounday(target)) {
                (*activePlayer)->play(i, playerTwo->getMinionOnBoard(target));
            } else {
                cerr << "No Target At Given Position" << endl;
            }
        }
    }
    cleanUpBoard();
}

void GameController::play(int i, int player, char target) {
    int targetCard;
    switch (target) {
        case '1':
            targetCard = 1;
            break;
        case '2':
            targetCard = 2;
            break;
        case '3':
            targetCard = 3;
            break;
        case '4':
            targetCard = 4;
            break;
        case '5':
            targetCard = 5;
            break;
        case 'r':
            targetCard = 6;
            break;
    }
    play(i, player, targetCard);
}

void GameController::use(int i, int player, int target)
{
    if (player == 1) {
        if (target == 6) {
            (*activePlayer)->use(i, playerOne->getRitualField());
        } else {
            if (playerOne->insideBoardBounday(target)) {
                (*activePlayer)->use(i, playerOne->getMinionOnBoard(target));
            } else {
                cerr << "No Target At Given Position" << endl;
            }
        }
    } else {
        if (target == 6) {
            (*activePlayer)->use(i, playerTwo->getRitualField());
        } else {
            if (playerTwo->insideBoardBounday(target)) {
                (*activePlayer)->use(i, playerTwo->getMinionOnBoard(target));
            } else {
                cerr << "No Target At Given Position" << endl;
            }
        }
    }
    cleanUpBoard();
}

void GameController::use(int i) {
    (*activePlayer)->use(i);
    cleanUpBoard();
}

void GameController::use(int i, int player, char target) {
    int targetCard;
    switch (target) {
        case '1':
            targetCard = 1;
            break;
        case '2':
            targetCard = 2;
            break;
        case '3':
            targetCard = 3;
            break;
        case '4':
            targetCard = 4;
            break;
        case '5':
            targetCard = 5;
            break;
        case 'r':
            targetCard = 6;
            break;
    }
    use(i, player, targetCard);
}

void GameController::cleanUpBoard() {
    for (auto minion = (*activePlayer)->getBoard().begin(); minion < (*activePlayer)->getBoard().end(); ++minion){
        //cout << "asd" << endl;
        //cout << (*minion)->getName() << endl;
        if ((*minion)->getDefense() <= 0) {
            (*activePlayer)->sendToGrave(*minion);
            (*activePlayer)->getBoard().erase(minion);
            minion -= 1;
        }
    }
    for (auto minion = (*nonActivePlayer)->getBoard().begin(); minion < (*nonActivePlayer)->getBoard().end(); ++minion){
        if ((*minion)->getDefense() <= 0) {
            (*nonActivePlayer)->sendToGrave(*minion);
            (*nonActivePlayer)->getBoard().erase(minion);
            minion -= 1;
        }
    }
    refreshDisplay();
}

void GameController::inspect(int i) {
    if (!(*activePlayer)->insideBoardBounday(i)) {
         cerr << "No Available Cards at Given Position!" << endl;
    } else {
        //cout << (*activePlayer)->getMinionOnBoard(i)->getEnchantments().size()<<endl;
        for(auto& adaptor : adaptors) {
            adaptor->printEnchantments((*activePlayer)->getMinionOnBoard(i));
        }
    }
}

void GameController::hand() {
    for(auto& adaptor : adaptors) {
        //cout << "adaptor enter" <<endl;
        adaptor->printHand((*activePlayer));
        //cout << "adaptor enter" <<endl;
    }
}

void GameController::board()
{
    for(auto& adaptor : adaptors) {
        adaptor->refresh(playerOne, playerTwo);
    }
}

void GameController::attack(int i, int j) {
    if (!(*activePlayer)->insideBoardBounday(i)) {
         cerr << "No Available Cards at Given Position!" << endl;
    } else if (!(*nonActivePlayer)->insideBoardBounday(j)) {
            cerr << "No Available Cards at Given targert Position!" << endl;
    } else {
        ((*activePlayer)->getMinionOnBoard(i))->attackMinion((*nonActivePlayer)->getMinionOnBoard(j));
    }
    cleanUpBoard();
}

void GameController::attack(int i)
{
    if (!(*activePlayer)->insideBoardBounday(i)) {
         cerr << "No Available Cards at Given Position!" << endl;
    } else {
        ((*activePlayer)->getMinionOnBoard(i))->attackPlayer();
    }
    cleanUpBoard();
}

void GameController::setTestMode() {
    testMode = true;
}

void GameController::discardCard(int i) {
    (*activePlayer)->discarCard(i);
}

void GameController::drawCard() {
    (*activePlayer)->drawCard();
}

vector<unique_ptr<Minion>>& GameController::getNonActivePlayerBoard() {
    return (*nonActivePlayer)->getBoard();
}


