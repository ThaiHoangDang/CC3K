#include <cstdlib>
#include "dwarf.h"

Dwarf::Dwarf(int x, int y): Enemy {'W', "Dwarf", (rand() % 2) + 1, x, y, 100, 20, 30} {}

Dwarf::~Dwarf() {}

void Dwarf::setHp(int h) {
    if (h > 100) hp = 100;
    else if (h < 0) hp = 0;
    else hp = h;
}
