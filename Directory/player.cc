#include "player.h"
#include "minion.h"
/*#include "enchantments.h"
#include "spell.h"
#include "ritual.h"*/
#include <utility>
#include <iostream>
#include <fstream>
#include "ritual.h"
#include <memory>
#include "card.h"
#include "gameController.h"
using namespace std;

Player::Player(string name,GameController* gc, string deck): name{name}, gameController{gc} {
    initializeDeck(deck);
    for (int i = 0; i < 5; i++){
        drawCard();
    }
    life = 20;
    magic = 3;
}


void Player::drawCard() {
    if (hand.size() < 5 && deck.size() > 0) {
        hand.push_back(move(deck.back()));
        deck.pop_back();
    } else if (hand.size() >=5 && deck.size() > 0){
        cerr << "Cannot Draw if you already have 5 cards in hand"<< endl;
    }
}

void Player::takeDamage(int amount) {
    life = life - amount >=0? life - amount : 0;
}

bool Player::costMagic(int amount)
{
    if (magic - amount >= 0) {
        magic -= amount;
        return true;
    } else {
        return false;
    }
}

int Player::getHealth()
{
    return life;
}

void Player::restoreMagic(int amount) {
    magic += amount;
}

void Player::restoreHealth(int amount) {
    life += amount;
}


void Player::play(int i) {
    if (hand.size() < i) {
        cerr << "No Available Cards at Given Position!";
    } else {
        if (dynamic_cast<Minion*>(hand[i-1].get())) {
            hand[i-1]->setState(State::onBoard);
            
            gameController->onMinionEnter(hand[i-1]);
            board.push_back(move(hand[i-1]));
            hand.erase(hand.begin() + i - 1);
            
        } //else if (dynamic_cast<Spell*>(deck[i-1].get()))
    }
}

void Player::notifyAllCard(StateInfo info) {
    for(auto& card : board) {
        card->notify(info);
    }
    ritualField->notify(info);
}

void Player::notifyAllCard(StateInfo info, unique_ptr<Minion>& target) {
    for(auto& card : board) {
        card->notify(info, target);
    }
    ritualField->notify(info, target);
}

// implement deck initialization here
void Player::initializeDeck(string deck) {
    ifstream f{deck};
    string s;
    while (getline(f,s)) {
        if (s == "Air Elemental") {
            this->deck.push_back(make_unique<Minion>(gameController, this));
        } else if (s == "Earth Elemental") {
            this->deck.push_back(make_unique<Minion>(gameController, this,"Earth Elemental", 3, 4, 4));
        } /*else if (f == "Fire Elemental") {
            deck.push_back(FireElemental(gameController));
        } else if (f == "Bone Golem") {
            deck.push_back(BoneGolem(gameController));
        } else if (f == "Potion Seller") {
            deck.push_back(PotionSeller(gameController));
        } else if (f == "Novice Pyromancer") {
            deck.push_back(NovicePyromancer(gameController));
        } else if (f == "Apprentice Summoner") {
            deck.push_back(ApprenticeSummoner(gameController));
        } else if (f == "Master Summoner") {
            deck.push_back(MasterSummoner(gameController));
        } else if (f == "Banish") {
            deck.push_back(Banish(gameController));
        } else if (f == "Unsummon") {
            deck.push_back(Unsummon(gameController));
        } else if (f == "Recharge") {
            deck.push_back(Recharge(gameController));
        } else if (f == "Disenchant") {
            deck.push_back(Disenchant(gameController));
        } else if (f == "Raise Dead") {
            deck.push_back(RaiseDead(gameController));
        } else if (f == "Blizzard") {
            deck.push_back(Blizzard(gameController));
        } else if (f == "Giant Strength") {
            deck.push_back(GiantStrength());
        } else if (f == "Enrage") {
            deck.push_back(Enrage());
        } else if (f == "Haste") {
            deck.push_back(Haste());
        } else if (f == "Magic Fatigue") {
            deck.push_back(MagicFatigue());
        } else if (f == "Silence") {
            deck.push_back(Silence());
        } else if (f == "Dark Ritual") {
            deck.push_back(DarkRitual(gameController));
        } else if (f == "Aura of Power") {
            deck.push_back(AuraOfPower(gameController));
        } else if (f == "Standstill") {
            deck.push_back(Standstill(gameController));
        }*/
    }
}