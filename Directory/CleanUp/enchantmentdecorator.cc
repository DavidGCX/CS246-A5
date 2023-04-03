#include "enchantmentdecorator.h"

Decorator::Decorator(Minion *m): next{m} {}
Decorator::~Decorator() {delete next;}
