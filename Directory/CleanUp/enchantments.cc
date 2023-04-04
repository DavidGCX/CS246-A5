#include "enchantments.h"
using namespace std;


GiantStrength::GiantStrength(Minion *m): EnchantmentDecorator{m}, name{"Giant Strength"} , Card{g, "Giant Strength", 1} {}
void GiantStrength::Inspect();
void GiantStrength::applyEffect() {
    m.setAttack(m.getAttack() + 2);
    m.setDefense(m.getDefense() + 2);
}

Enrage::Enrage(Minion *m): EnchantmentDecorator{m}, name{"Enrage"} , Card{"Enrage", 2} {}
void Enrage::Inspect();
void Enrage::applyEffect() {
    m.setAttack(m.getAttack() * 2);
    m.setDefense(m.getDefense() * 2);
}

Silence::Silence(Minion *m): EnchantmentDecorator{m}, name{"Silence"} , Card{"Silence", 1} {}
void Silence::Inspect();
void Silence::applyEffect() {
    m.canUseAbility = false;
}

Haste::Haste(Minion *m): EnchantmentDecorator{m}, name{"Haste"} , Card{"Haste", 1} {}
void Haste::Inspect();
void Haste::applyEffect() {
    m.setActNum(m.getActNum() + 1);
    m.setRemAct(m.getRemAct() + 1);
}

MagicFatigue::MagicFatigue(Minion *m): EnchantmentDecorator{m}, name{"Magic Fatigue"} , Card{"Magic Fatigue", 0} {}
void MagicFatigue::Inspect();
void MagicFatigue::applyEffect() {
    m.setMagCost(m.getMagCost() + 2);
}
