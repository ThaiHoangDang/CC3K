#include <cstdlib>
#include <cmath>
#include "merchant.h"

const int defaultHP = 30, defaultAtk = 70, defaultDef = 5;

Merchant::Merchant(int x, int y): 
    Enemy {'M', "Merchant", 4, x, y, defaultHP, defaultAtk, defaultDef} {}

Merchant::~Merchant() {}

int Merchant::attack(Living *l) {
    if (! isHostile) return 0;

    int damage = ceil((100.0/(100 + l->getDef())) * getAtk());
    if (l->defence(damage)) return damage;
    return 0;
}

bool Merchant::defence(int damage) {
    isHostile = true;
    setHp(getHp() - damage);
    return true;
}

void Merchant::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}

bool Merchant::getIsHostile() { return isHostile; }

void Merchant::setIsHostile(bool status) { isHostile = status; }
