#include "vampire.h"

Vampire::Vampire(int x, int y): Race {"Vampire", x, y, 50, 25, 25} {}

Vampire::~Vampire() {}

void Vampire::setHp(int h) {
    if (h < 0) hp = 0;
    else hp = h;
}
