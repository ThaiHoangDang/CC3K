#include "drow.h"


const int defaultHP = 150, defaultAtk = 25, defaultDef = 15;


Drow::Drow(int x, int y): Race {"Drow", x, y, defaultHP, defaultAtk, defaultDef} {}


Drow::~Drow() {}


void Drow::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}

// x1.5 potion effect
void Drow::addHpEffect(int x) { setHp(getHp() + (x * 15 / 10)); }


// x1.5 potion effect
void Drow::addAtkEffect(int x) { 
    atkEffect += (x * 15 / 10);
    if (atkEffect < -atk) atkEffect = -atk;
}


// x1.5 potion effect
void Drow::addDefEffect(int x) {
    defEffect += (x * 15 / 10);
    if (defEffect < -def) defEffect = -def;
}
