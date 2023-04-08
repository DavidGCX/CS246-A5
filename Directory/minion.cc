#include "minion.h"
#include "card.h"
#include "gameController.h"
#include "player.h"
#include "enchantments.h"
using namespace std;

Minion::Minion(GameController *g, Player* owner, string name, int cost, 
int attack, int defense) : Card{name, cost, g, owner}, attack{attack}, 
defense{defense}, numactions{1} {}

void Minion::takeDamage(int amount) {
    defense = defense - amount;
    // if defense gets to 0 or below, remove from board
}

void Minion::attackMinion(unique_ptr<Minion>& target) {
    this->takeDamage(target->getAttack());
    target->takeDamage(attack);
}

void Minion::attackPlayer() {
    gameController->attackNonActivePlayer(getAttack());
}

void Minion::notify(StateInfo state) {
    if (state == StateInfo::onTurnStart){
        if (numactions < 1 && numactions) {
            numactions = 1;
        }
    }
   // for(auto& enchantment : enchantments) {
     //   enchantment.notify(state);
   // }
}
void Minion::notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) {
   return;
}

void Minion::setAttack(int a) {
    attack = a;
}
void Minion::setDefense(int d) {
    defense = d;
}
void Minion::setActNum(int n) {
    numactions = n;
}

void Minion::setRemAct(int r) {
    if (r == 2) {
        remainingactions = numactions;
    } else {
        remainingactions = 1;
    }
}
int Minion::getAttack() {
    return attack;
}
int Minion::getDefense() {
    return defense;
}
int Minion::getActNum() {
    return numactions;
}

/*
int Minion::getMagCost() {
    return magic_cost;
}
void Minion::Inspect() { 
    // get attack, defense, name, cost, look through all enchantments
   // int numofenchants = enchants.size();
    // for (int i = 0; i < numofenchants; ++i) {
        // Inspect(enhcants[i]);
        // if (i + 1 % 5 == 0), go to next line
    // }
}

bool Minion::canBePlayed(); //check board space

bool Minion::canBeUsed() {
    if (remainingactions == 0) {
        return false;
    } else {
        return true;
    }
}


void Minion::setMagCost(int c) {
    magic_cost = c;
}
int Minion::getRemAct() {
    return remainingactions;
}

BoneGolem::BoneGolem(GameController *g): Minion{g, "Bone Golem", 2, 1, 3} {}
bool BoneGolem::useAbility() { // activates when minion leaves play
    this->setAttack(this->getAttack() + 1);
    this->setDefense(this->getDefense() + 1);
}

PotionSeller::PotionSeller(GameController *g): Minion{g, "Potion Seller", 2, 1, 3} {}
bool PotionSeller::useAbility(Minion& m) {
    m.setDefense(m.getDefense() + 1);
}

NovicePyromancer::NovicePyromancer(GameController *g): Minion{g, "Novice Pyromancer", 1, 1, 1} {}
bool NovicePyromancer::useAbility(Minion& m) {
    // if magic not enough, return false, else:
    m.setDefense(m.getDefense() - 1);
    // if defense at 0, remove m from board
}

FireElement::FireElement(GameController *g): Minion{g, "Fire Element", 2, 2, 2} , magic_cost{1} {}
bool FireElement::useAbility(Minion& m) {
    // when minion enters play
    m.setDefense(m.getDefense() - 1);
    // if defense at 0, remove m from board
}

ApprenticeSummoner::ApprenticeSummoner(GameController *g): Minion{g, "Apprentice Summoner", 1, 1, 1}, magic_cost{1}  {}
bool ApprenticeSummoner::useAbility() {
    // if board isn't full
    // add to board Minion() (it'll default to air element)
}

MasterSummoner::MasterSummoner(GameController *g): Minion{g, "Master Summoner", 3, 2, 3}, magic_cost{2} {}
bool MasterSummoner::useAbility() {
    // if board isn't full
    // add to board Minion() (it'll default to air element) through a for loop up until 3 or the amount of space left
}
*/


