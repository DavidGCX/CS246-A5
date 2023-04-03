#include "player.h"
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
void Player::initializeDeck(std::string deck)
{
}

void Player::play(int i) {

}
