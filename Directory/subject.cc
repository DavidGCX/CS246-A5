// Code taken from horseracing example
#include "subject.h"
#include <memory>
#include <vector>
#include "player.h"
using namespace std;

enum class StateInfo;
Subject::Subject() {}
Subject::~Subject() {}

void Subject::attach( Observer *o ) {
  observers.emplace_back(o);
}

void Subject::detach( Observer *o ) {
  for ( auto it = observers.begin(); it != observers.end(); ++it ) {
    if ( *it == o ) {
      observers.erase(it);
      break;
    }
  }
}

void Subject::notifyObservers(StateInfo info) {
  for (auto ob : observers) ob->notify(info);
}

void notifyObservers(StateInfo info, unique_ptr<Player>* player) {
    (*player)->notifyAllCard(info);
}

void notifyObservers(StateInfo info, unique_ptr<Player>* player,  unique_ptr<Minion>& target) {
    (*player)->notifyAllCard(info, target);
}
