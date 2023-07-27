#include <cstdlib>
#include "elf.h"

const int defaultHP = 140, defaultAtk = 30, defaultDef = 10;

Elf::Elf(int x, int y): 
    Enemy {'E', "Elf", (rand() % 2) + 1, x, y, defaultHP, defaultAtk, defaultDef} {}

Elf::~Elf() {}

void Elf::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}
