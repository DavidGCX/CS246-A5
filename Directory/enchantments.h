#ifndef ENCH_H
#define ENCH_H
#include "enchantmentsdecorator.h"
#include <string>

class GiantStrength: public Decorator {
    public:
    GiantStrength(std::string name, Minion *m);
    void Inspect();
    void applyEffect();
}

class Enrage: public Decorator {
    public:
    Enrage(std::string name, Minion *m);
    void Inspect();
    void applyEffect();
}

class Silence: public Decorator {
    public:
    Silence(std::string name, Minion *m);
    void Inspect();
    void applyEffect();
}

class Haste: public Decorator {
    public:
    Haste(std::string name, Minion *m);
    void Inspect();
    void applyEffect();
}

class MagicFatigue: public Decorator {
    public:
    MagicFatigue(std::string name, Minion *m);
    void Inspect();
    void applyEffect();
}

#endif