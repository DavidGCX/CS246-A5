// Code taken from horseracing example
#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "observer.h"

class Player;
enum class StateInfo;

class Subject {
  std::vector<Observer*> observers;

 public:
  Subject();
  void attach( Observer *o );
  void detach( Observer *o );
  void notifyObservers(StateInfo info);
  void notifyObservers(StateInfo info, unique_ptr<Player>* player);
  virtual ~Subject() = 0;
};

#endif
