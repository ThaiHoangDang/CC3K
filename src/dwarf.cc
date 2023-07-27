#include <cstdlib>
#include "dwarf.h"

const int defaultHP = 100, defaultAtk = 20, defaultDef = 30;

Dwarf::Dwarf(int x, int y): 
    Enemy {'W', "Dwarf", (rand() % 2) + 1, x, y, defaultHP, defaultAtk, defaultDef} {}

Dwarf::~Dwarf() {}

void Dwarf::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}
