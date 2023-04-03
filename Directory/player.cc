#include "player.h"
#include <utility>
using namespace std;

Player::Player(std::string name, std::string deck): name{name} {
    init(deck);
}

void Player::init(string deck) {
    //initialize the deck here
    for (int i = 0; i < 5; i++){
        drawCard();
    }
    magic = 3;
}

void Player::drawCard()
{
    if (hand.size() < 5 && deck.size() > 0) {
        hand.push_back(move(deck.back()));
        deck.pop_back();
    } else if (hand.size() >=5 && deck.size() > 0){
        deck.pop_back();
    }
}

void Player::damage(int amount) {
    health = health - amount >=0? health - amount : 0;
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
    return health;
}

void Player::restoreMagic(int amount) {
    magic += amount;
}

void Player::restoreHealth(int amount) {
    health += amount;
}
