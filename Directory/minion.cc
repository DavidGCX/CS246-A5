#include "minion.h"
using namespace std;

Minion::Minion(string name, int cost, int attack, int defense, int magic_cost): Card{name, cost}, attack{attack}, defense{defense}, numactions{1}, magic_cost{magic_cost} {}

Minion::~Minion() {}


bool Minion::canBePlayed(); //check board space

bool Minion::canBeUsed() {
    if (remainingactions == 0) {
        return false;
    } else {
        return true;
    }
}

void Minion::takeDamage(Minion m) {
    defense = defense - m.getAttack();
    // if defense gets to 0 or below, remove from board
}

void Minion::attackMinion(Minion& m) {
    m.takeDamage(this);
}

void Minion::attackPlayer(); // deal damage to player health

void Minion::Inspect() { 
    // get attack, defense, name, cost, look through all enchantments
    int numofenchants = enchants.size();
    // for (int i = 0; i < numofenchants; ++i) {
        // Inspect(enhcants[i]);
        // if (i + 1 % 5 == 0), go to next line
    // }
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
void Minion::setMagCost(int c) {
    magic_cost = c;
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
int Minion::getMagCost() {
    return magic_cost;
}
int Minion::getRemAct() {
    return remainingactions;
}

BoneGolem::BoneGolem(): Minion{"Bone Golem", 2, 1, 3} {}
void BoneGolem::useAbility() { // activates when minion leaves play
    this.setAttack(this.getAttack() + 1);
    this.setDefense(this.getDefense() + 1);
}

PotionSeller::PotionSeller(): Minion{"Potion Seller", 2, 1, 3} {}
bool PotionSeller::useAbility(Minion& m) {
    m.setDefense(m.getDefense() + 1);
}

NovicePyromancer::NovicePyromancer(): Minion{"Novice Pyromancer", 1, 1, 1} {}
bool NovicePyromancer::useAbility(Minion& m) {
    // if magic not enough, return false, else:
    m.setDefense(m.getDefense() - 1);
    // if defense at 0, remove m from board
}

FireElement::FireElement(): Minion{"Fire Element", 2, 2, 2} , magic_cost{1} {}
void FireElement::useAbility(Minion& m) {
    // when minion enters play
    m.setDefense(m.getDefense() - 1);
    // if defense at 0, remove m from board
}

ApprenticeSummoner::ApprenticeSummoner(): Minion{"Apprentice Summoner", 1, 1, 1}, magic_cost{1}  {}
bool ApprenticeSummoner::useAbility(); {
    // if board isn't full
    // add to board Minion() (it'll default to air element)
}

MasterSummoner::MasterSummoner(): Minion{"Master Summoner", 3, 2, 3}, magic_cost{2} {}
bool MasterSummoner::useAbility() {
    // if board isn't full
    // add to board Minion() (it'll default to air element) through a for loop up until 3 or the amount of space left
}



