#include <cstdlib>
#include "elf.h"

Elf::Elf(int x, int y): Enemy {'E', "Elf", (rand() % 2) + 1, x, y, 140, 30, 10} {}

Elf::~Elf() {}

void Elf::setHp(int h) {
    if (h > 140) hp = 140;
    else if (h < 0) hp = 0;
    else hp = h;
}
