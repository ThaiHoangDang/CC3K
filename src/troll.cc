#include "troll.h"

Troll::Troll(int x, int y): Race {"Troll", x, y, 120, 25, 15} {}

Troll::~Troll() {}

void Troll::setHp(int h) {
    if (h > 120) hp = 120;
    else if (h < 0) hp = 0;
    else hp = h;
}
