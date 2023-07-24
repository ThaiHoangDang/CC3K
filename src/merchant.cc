#include <cstdlib>
#include "merchant.h"

Merchant::Merchant(int x, int y): Enemy {'M', "Merchant", 4, x, y, 30, 70, 5} {}

Merchant::~Merchant() {}

void Merchant::setHp(int h) {
    if (h > 30) hp = 30;
    else if (h < 0) hp = 0;
    else hp = h;
}
