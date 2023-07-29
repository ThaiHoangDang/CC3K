#include "troll.h"


const int defaultHP = 120, defaultAtk = 25, defaultDef = 15;


Troll::Troll(int x, int y): Race {"Troll", x, y, defaultHP, defaultAtk, defaultDef} {}


Troll::~Troll() {}


void Troll::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}

// +5 HP after every move
void Troll::addNumMove() {
    numMoves++;
    setHp(getHp() + 5);
}
