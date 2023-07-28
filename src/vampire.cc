#include <cmath>
#include "vampire.h"

const int defaultHP = 50, defaultAtk = 25, defaultDef = 25;

Vampire::Vampire(int x, int y): Race {"Vampire", x, y, defaultHP, defaultAtk, defaultDef} {}

Vampire::~Vampire() {}

void Vampire::setHp(int h) {
    if (h < 0) hp = 0;
    else hp = h;
}

int Vampire::attack(Living *e) {
    int damage = ceil((100.0/(100 + e->getDef())) * getTotalAtk());
    if (e->defence(damage)) {
        if (e->getName() == "Dwarf") {
            setHp(getHp() - 5);
        } else {
            setHp(getHp() + 5);
        }
        if (e->getHp() == 0) { 
            addScore(e->getValue()); 
            addEnemiesKilled();
        }
        return damage;
    }
    return 0;
}
