#include "spellAbility.h"
#include "player.h"
#include "gameController.h"
#include <string>
#include <memory>
#include "minion.h"
#include "ritual.h"
#include <vector>
using namespace std;

string Banish::getDescription() {
    return "Destroy target minion or ritual";
}
bool Banish::useAbility(unique_ptr<Minion>& target) {
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
    return true;
}
bool Banish::useAbility(unique_ptr<Ritual>& target) {
    target.~unique_ptr();
    return true;
}


string Unsummon::getDescription() {

}
bool Unsummon::useAbility(unique_ptr<Minion>& target) {
    int i = 0;
    vector<std::unique_ptr<Minion>>& board = target->getOwner()->getBoard();
    for (auto& minion : board) {
        if (minion.get() == target.get()) {
            (target->getOwner())->sendToHand(target);
            board.erase(board.begin() + i);
            break;
        }
        i++;
    }
    return true;
}