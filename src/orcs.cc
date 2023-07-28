#include <cstdlib>
#include <cmath>
#include "orcs.h"

const int defaultHP = 180, defaultAtk = 30, defaultDef = 25;

Orcs::Orcs(int x, int y): 
    Enemy {'O', "Orcs", (rand() % 2) + 1, x, y, defaultHP, defaultAtk, defaultDef} {}

Orcs::~Orcs() {}

int Orcs::attack(Living *l) {
    int damage = ceil((100.0/(100 + l->getDef())) * getAtk());
    if (l->getName() == "Goblin") damage = damage * 15 / 10;
    if (l->defence(damage)) return damage;
    return 0;
}

void Orcs::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}
