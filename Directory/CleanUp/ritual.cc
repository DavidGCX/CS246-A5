#include "ritual.h"
using namespace std;

Ritual::Ritual(string name, int cost, GameController *g, Player* owner, 
int charges, int cost_per_charge): 
Card{name, cost, g, owner}, charges{charges}, cost_per_charge{cost_per_charge} {}


