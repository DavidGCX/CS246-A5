#include "player.h"
#include "minion.h"
/*#include "enchantments.h"
#include "spell.h"
#include "ritual.h"*/
#include <utility>
#include <iostream>
#include <fstream>
#include "ritual.h"
#include "enchantments.h"
#include "spell.h"
#include <memory>
#include "card.h"
#include "gameController.h"
#include "state.h"
#include "hasAbility.h"
#include "PRNG.h"
using namespace std;


Player::Player(string name, GameController *gc, bool testMode , string deck) : 
name{name}, gameController{gc}
{
    initializeDeck(deck);
    if (testMode == false) {
        shuffDeck();
    }
    for (int i = 0; i < 5; i++){
        drawCard();
    }
    life = 20;
    magic = 3;
}

void Player::drawCard() {
    if (hand.size() < 5 && deck.size() > 0) {
        deck.back()->setState(State::onHand);
        hand.push_back(move(deck.back()));
        deck.pop_back();
    } else if (hand.size() >=5 && deck.size() > 0){
        cerr << "Cannot Draw if you already have 5 cards in hand"<< endl;
    } else if (deck.size() == 0) {
        cerr << "Deck is Empty" << endl;
    }
}

void Player::takeDamage(int amount) {
    life = life - amount >=0? life - amount : 0;
}


int Player::getHealth() const
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
    if (!insideHandBounday(i)) {
        cerr << "No Available Cards at Given Position!" << endl;
        return;
    } else {
        if (hand[i-1]->getCost() > magic && !gameController->getTestMode()) {
            cerr << "No Enough Magic for this Action" << endl;
            return;
        }
        if (dynamic_cast<Minion*>(hand[i-1].get())) {
            handleMagic(hand[i-1]->getCost());
            unique_ptr<Minion> tempMinion {dynamic_cast<Minion*>(hand[i-1].release())};
            sendToBoard(tempMinion);
            hand.erase(hand.begin() + i - 1);
        } else if (dynamic_cast<HasAbilityNoTarget*>(hand[i-1].get())) {
            if (dynamic_cast<Ritual*>(hand[i-1].get())) {
                handleMagic(hand[i-1]->getCost());
                hand[i-1]->setState(State::onBoard);
                ritualField.reset(dynamic_cast<Ritual*>(hand[i-1].release()));
                hand.erase(hand.begin() + i - 1);
            } else {
                if(dynamic_cast<HasAbilityNoTarget*>(hand[i-1].get())->useAbility()) {
                    handleMagic(hand[i-1]->getCost());
                    hand.erase(hand.begin() + i - 1);
                }
            }
        } else {
            cerr << "This Can Not Be Played without Target" << endl;
            return;
        }
    }
}

void Player::play(int i, unique_ptr<Minion>& target)
{
    if (!insideHandBounday(i)) {
        cerr << "No Available Cards at Given Position!" << endl;
        return;
    } else {
        if (hand[i-1]->getCost() > magic && !gameController->getTestMode()) {
            cerr << "No Enough Magic for this Action" << endl;
            return;
        } 
        if (dynamic_cast<HasAbilityWithTarget*>(hand[i-1].get())) {
            if (dynamic_cast<Spell*>(hand[i-1].get())) {
                if(dynamic_cast<HasAbilityWithTarget*>(hand[i-1].get())->useAbility(target)) {
                    handleMagic(hand[i-1]->getCost());
                    hand.erase(hand.begin() + i - 1);
                }
            } else if (dynamic_cast<Enchantment*>(hand[i-1].get())) {
                dynamic_cast<HasAbilityWithTarget*>(hand[i-1].get())->useAbility(target);
                handleMagic(hand[i-1]->getCost());
                unique_ptr<Enchantment> tempEnchant {dynamic_cast<Enchantment*>(hand[i-1].release())};
                target->attachEnchantment(move(tempEnchant));
                hand.erase(hand.begin() + i - 1);
            } else {
                cerr << "This Can Not Be Played with Target" << endl;
            }
        } else {
            cerr << "This Can Not Be Played with Target" << endl;
        }
    }
}

void Player::play(int i, unique_ptr<Ritual>& target)
{
    if (!insideHandBounday(i)) {
        cerr << "No Available Cards at Given Position!" << endl;
        return;
    } else {
        if (hand[i-1]->getCost() > magic && !gameController->getTestMode()) {
            cerr << "No Enough Magic for this Action" << endl;
            return;
        } 
        if (dynamic_cast<HasAbilityWithTargetRitual*>(hand[i-1].get())) {
            if (dynamic_cast<Spell*>(hand[i-1].get())) {
                if(dynamic_cast<HasAbilityWithTargetRitual*>(hand[i-1].get())->useAbility(target)) {
                    handleMagic(hand[i-1]->getCost());
                    hand.erase(hand.begin() + i - 1);
                }
            } 
        } else {
            cerr << "This Can Not Be Played with a Ritual Target" << endl;
        }
    }
}

void Player::use(int i, unique_ptr<Minion>& target)
{
    if (!insideBoardBounday(i)) {
        cerr << "No Available Cards at Given Position!" << endl;
        return;
    } else if (dynamic_cast<HasAbilityWithTarget*>(board[i-1].get())) {
        HasAbilityWithTarget* temp = dynamic_cast<HasAbilityWithTarget*>(board[i-1].get());
        if (temp->getAbilityCost() > magic && !gameController->getTestMode()) {
            cerr << "No Enough Magic for this Action" << endl;
            return;
        } else if (temp->getSilence()) {
            cerr << "This Minion is Silenced, can not use ability" << endl;
            return;
        } else if (board[i-1]->getActNum() <= 0){ 
            cerr << "This Minion Does Not Have Enough Action Point To Be Used" << endl;
        } else {
            if(temp->useAbility(target)) {
                handleMagic(temp->getAbilityCost());
                board[i-1]->costAct(1);
            }
        }     
    } else {
        cerr << "This Can Not Be Used without Target" << endl;
        return;
    }
}

void Player::use(int i, unique_ptr<Ritual>& target)
{
    if (!insideBoardBounday(i)) {
        cerr << "No Available Cards at Given Position!" << endl;
        return;
    } else if (dynamic_cast<HasAbilityWithTargetRitual*>(board[i-1].get())) {
        HasAbilityWithTargetRitual* temp = dynamic_cast<HasAbilityWithTargetRitual*>(board[i-1].get());
        if (temp->getAbilityCost() > magic && !gameController->getTestMode()) {
            cerr << "No Enough Magic for this Action" << endl;
            return;
        } else if (temp->getSilence()) {
            cerr << "This Minion is Silenced, can not use ability" << endl;
        } else if (board[i-1]->getActNum() <= 0){ 
            cerr << "This Minion Does Not Have Enough Action Point" << endl;
        } else {
            if(temp->useAbility(target)) {
                handleMagic(temp->getAbilityCost());
                board[i-1]->costAct(1);
            }
        }     
    } else {
        cerr << "This Can Not Be Used without Target" << endl;
        return;
    }
}


void Player::use(int i) {
    if (!insideBoardBounday(i)) {
        cerr << "No Available Cards at Given Position!" << endl;
        return;
    } else if (dynamic_cast<HasAbilityNoTarget*>(board[i-1].get())) {
        HasAbilityNoTarget* temp = dynamic_cast<HasAbilityNoTarget*>(board[i-1].get());
        if (temp->getAbilityCost() > magic && !gameController->getTestMode()) {
            cerr << "No Enough Magic for this Action" << endl;
            return;
        } else if (temp->getSilence()) {
            cerr << "This Minion is Silenced, can not use ability" << endl;
            return;
        } else if (board[i-1]->getActNum() <= 0){ 
            cerr << "This Minion Does Not Have Enough Action Point" << endl;
            return;
        } else {
            if(temp->useAbility()) {
                handleMagic(temp->getAbilityCost());
                board[i-1]->costAct(1);
            }
        }     
    } else {
        cerr << "This Can Not Be Used without Target" << endl;
        return;
    }
}


void Player::discarCard(int i) {
    if (!insideHandBounday(i)) {
        cerr << "No Available Cards at Given Position!"<< endl;
    } else {
        hand[i-1]->setState(State::removeFromTheGame);
        outOfGame.push_back(move(hand[i-1]));
        hand.erase(hand.begin() + i - 1);
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

unique_ptr<Minion>& Player::getMinionOnBoard(int i)
{
    return board[i-1];   
}

void Player::sendToBoard(unique_ptr<Minion>& minion)
{
    board.push_back(move(minion));
    board.back()->setState(State::onBoard);
    gameController->onMinionEnter(board.back());
}

void Player::sendToGrave(unique_ptr<Minion>& minion)
{
    gameController->onMinionExit(graveyard.back());
    graveyard.back()->setState(State::onGraveYard);
    graveyard.back()->removeAllEnchantment();
    graveyard.push_back(move(minion));
}

void Player::sendToHand(unique_ptr<Minion>& minion)
{
    gameController->onMinionExit(minion);
     minion->setState(State::onHand);
     minion->removeAllEnchantment();
    hand.push_back(move(minion));
}

void Player::shuffDeck() {
    PRNG p = PRNG();
    int size = deck.size();
    for (int i = 0; i < size; ++i) {
        std::swap(deck[p(size)], deck[p(size)]);
    }
    // shuff deck here
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
            this->deck.push_back(FireElemental(gameController));
        } else if (f == "Bone Golem") {
            this->deck.push_back(BoneGolem(gameController));
        } else if (f == "Potion Seller") {
            this->deck.push_back(PotionSeller(gameController));
        } else if (f == "Novice Pyromancer") {
            this->deck.push_back(NovicePyromancer(gameController));
        } else if (f == "Apprentice Summoner") {
            this->deck.push_back(ApprenticeSummoner(gameController));
        } else if (f == "Master Summoner") {
            this->deck.push_back(MasterSummoner(gameController));
        } else if (f == "Banish") {
            this->deck.push_back(Banish(gameController));
        } else if (f == "Unsummon") {
            this->deck.push_back(Unsummon(gameController));
        } else if (f == "Recharge") {
            this->deck.push_back(Recharge(gameController));
        } else if (f == "Disenchant") {
            this->deck.push_back(Disenchant(gameController));
        } else if (f == "Raise Dead") {
            this->deck.push_back(RaiseDead(gameController));
        } else if (f == "Blizzard") {
            this->deck.push_back(Blizzard(gameController));
        } else if (f == "Giant Strength") {
            this->deck.push_back(GiantStrength());
        } else if (f == "Enrage") {
            this->deck.push_back(Enrage());
        } else if (f == "Haste") {
            this->deck.push_back(Haste());
        } else if (f == "Magic Fatigue") {
            this->deck.push_back(MagicFatigue());
        } else if (f == "Silence") {
            this->deck.push_back(Silence());
        } else if (f == "Dark Ritual") {
            this->deck.push_back(DarkRitual(gameController));
        } else if (f == "Aura of Power") {
            this->deck.push_back(AuraOfPower(gameController));
        } else if (f == "Standstill") {
            this->deck.push_back(Standstill(gameController));
        }*/
    }
}
