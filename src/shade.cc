#include "shade.h"

Shade::Shade(int x, int y): Race {"Shade", x, y, 125, 25, 25} {}

Shade::~Shade() {}

void Shade::addScore(int x) { setValue(getValue() + x * 2); }

void Shade::setHp(int h) {
    if (h > 125) hp = 125;
    else if (h < 0) hp = 0;
    else hp = h;
}
