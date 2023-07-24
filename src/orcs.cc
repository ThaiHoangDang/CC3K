#include <cstdlib>
#include "orcs.h"

Orcs::Orcs(int x, int y): Enemy {'O', "Orcs", (rand() % 2) + 1, x, y, 180, 30, 25} {}

Orcs::~Orcs() {}

void Orcs::setHp(int h) {
    if (h > 180) hp = 180;
    else if (h < 0) hp = 0;
    else hp = h;
}
