#include <cstdlib>
#include "halfling.h"

const int defaultHP = 100, defaultAtk = 15, defaultDef = 20;

Halfling::Halfling(int x, int y): 
    Enemy {'L', "Halfling", (rand() % 2) + 1, x, y, defaultHP, defaultAtk, defaultDef} {}

Halfling::~Halfling() {}

void Halfling::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}
