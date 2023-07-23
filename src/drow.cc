#include "drow.h"

Drow::Drow(int x, int y): Race {"Drow", x, y, 150, 25, 15} {}

Drow::~Drow() {}

void Drow::setHp(int h) {
    if (h > 150) hp = 150;
    else if (h < 0) hp = 0;
    else hp = h;
}

void Drow::addHpEffect(int x) { setHp(getHp() + (x * 15 / 10)); }

void Drow::addAtkEffect(int x) { 
    atkEffect += (x * 15 / 10);
    if (atkEffect < -atk) atkEffect = -atk;
}

void Drow::addDefEffect(int x) {
    defEffect += (x * 15 / 10);
    if (defEffect < -def) defEffect = -def;
}
