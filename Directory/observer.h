// Code taken from horseracing example
#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "state.h"
#include <memory>
class Minion;
class Observer {
 public:
  virtual void notify(StateInfo stateInfo) = 0;
  virtual void notify(StateInfo stateInfo, std::unique_ptr<Minion>& target) = 0;
  virtual ~Observer();
};

#endif
