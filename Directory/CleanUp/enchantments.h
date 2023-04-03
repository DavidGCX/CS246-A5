#ifndef ENCH_H
#define ENCH_H
#include "enchantmentdecorator.h"
#include <string>

class GiantStrength: public Decorator {
    std::string name;
    public:
    GiantStrength(Minion *m);
    void Inspect();
    void applyEffect();
};

class Enrage: public Decorator {
    std::string name;
    public:
    Enrage(Minion *m);
    void Inspect();
    void applyEffect();
};

class Silence: public Decorator {
    std::string name;
    public:
    Silence(Minion *m);
    void Inspect();
    void applyEffect();
};

class Haste: public Decorator {
    std::string name;
    public:
    Haste(Minion *m);
    void Inspect();
    void applyEffect();
};

class MagicFatigue: public Decorator {
    std::string name;
    public:
    MagicFatigue(Minion *m);
    void Inspect();
    void applyEffect();
};

#endif