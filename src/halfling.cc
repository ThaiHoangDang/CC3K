#include <cstdlib>
#include "halfling.h"

Halfling::Halfling(int x, int y): Enemy {'L', "Halfling", (rand() % 2) + 1, x, y, 100, 15, 20} {}

Halfling::~Halfling() {}

void Halfling::setHp(int h) {
    if (h > 100) hp = 100;
    else if (h < 0) hp = 0;
    else hp = h;
}
