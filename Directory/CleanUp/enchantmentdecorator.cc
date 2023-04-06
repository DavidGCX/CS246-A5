#include "enchantmentdecorator.h"

EnchantmentDecorator::EnchantmentDecorator(Minion *m): next{m} {}
EnchantmentDecorator::~EnchantmentDecorator() {delete next;}
