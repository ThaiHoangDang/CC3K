#include "shade.h"

const int defaultHP = 125, defaultAtk = 25, defaultDef = 25;

Shade::Shade(int x, int y): Race {"Shade", x, y, defaultHP, defaultAtk, defaultDef} {}

Shade::~Shade() {}

void Shade::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}

void Shade::addScore(int x) { setValue(getValue() + x * 2); }
