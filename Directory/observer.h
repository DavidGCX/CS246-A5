// Code taken from horseracing example
#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Observer {
 public:
  virtual void notify(StateInfo stateInfo) = 0;
  virtual ~Observer();
};

#endif
