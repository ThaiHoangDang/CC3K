#include <cstdlib>
#include "merchant.h"

const int defaultHP = 30, defaultAtk = 70, defaultDef = 5;

Merchant::Merchant(int x, int y): 
    Enemy {'M', "Merchant", 4, x, y, defaultHP, defaultAtk, defaultDef} {}

Merchant::~Merchant() {}

void Merchant::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}
