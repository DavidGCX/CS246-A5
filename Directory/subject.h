// Code taken from horseracing example
#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "observer.h"
#include <memory>
#include "player.h"
class Player;
enum class StateInfo;

class Subject {
  std::vector<Observer*> observers;

 public:
  Subject();
  void attach( Observer *o );
  void detach( Observer *o );
  void notifyObservers(StateInfo info);
  void notifyObservers(StateInfo info, std::unique_ptr<Player>* player);
  void notifyObservers(StateInfo info, std::unique_ptr<Player>* player, std::unique_ptr<Minion>& target);
  virtual ~Subject() = 0;
};

#endif
