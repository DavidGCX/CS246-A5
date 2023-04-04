#include "player.h"
#include "minion.h"
#include "enchantments.h"
#include "spell.h"
#include "ritual.h"
#include <utility>
#include <iostream>
using namespace std;

Player::Player(std::string name, std::string deck): name{name} {
    init(deck);
}

void Player::init(string deck) {
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

void Player::damage(int amount) {
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

// implement deck initialization here
void Player::initializeDeck(std::string deck, GameController *g) {
    ifstream f{deck};
    string s;
    while (getline(f,s)) {
        if (f == "Air Elemental") {
            deck.push_back(Minion(g));
        } else if (f == "Earth Elemental") {
            deck.push_back(Minion(g, "Earth Elemental", 3, 4, 4));
        } else if (f == "Fire Elemental") {
            deck.push_back(FireElemental(g));
        } else if (f == "Bone Golem") {
            deck.push_back(BoneGolem(g));
        } else if (f == "Potion Seller") {
            deck.push_back(PotionSeller(g));
        } else if (f == "Novice Pyromancer") {
            deck.push_back(NovicePyromancer(g));
        } else if (f == "Apprentice Summoner") {
            deck.push_back(ApprenticeSummoner(g));
        } else if (f == "Master Summoner") {
            deck.push_back(MasterSummoner(g));
        } else if (f == "Banish") {
            deck.push_back(Banish(g));
        } else if (f == "Unsummon") {
            deck.push_back(Unsummon(g));
        } else if (f == "Recharge") {
            deck.push_back(Recharge(g));
        } else if (f == "Disenchant") {
            deck.push_back(Disenchant(g));
        } else if (f == "Raise Dead") {
            deck.push_back(RaiseDead(g));
        } else if (f == "Blizzard") {
            deck.push_back(Blizzard(g));
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
            deck.push_back(DarkRitual(g));
        } else if (f == "Aura of Power") {
            deck.push_back(AuraOfPower(g));
        } else if (f == "Standstill") {
            deck.push_back(Standstill(g));
        }
    }
}

void Player::play(int i) {

}
