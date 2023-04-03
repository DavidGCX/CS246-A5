#ifndef DEC_H
#define DEC_H
#include "minion.h"

class Decorator: public Minion {
    protected:
    Minion* next;
    public:
    Decorator(Minion *m);
    ~Decorator();
    virtual void applyEffect();
    virtual void Inspect();
};

#endif
