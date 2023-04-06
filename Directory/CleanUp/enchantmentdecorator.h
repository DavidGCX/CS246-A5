#ifndef DEC_H
#define DEC_H
#include "minion.h"

class EnchantmentDecorator: public Minion {
    protected:
    Minion* next;
    public:
    EnchantmentDecorator(Minion *m);
    ~EnchantmentDecorator();
    virtual void applyEffect();
    virtual void Inspect();
};

#endif
