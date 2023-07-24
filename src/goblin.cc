#include <cmath>
#include "goblin.h"

Goblin::Goblin(int x, int y): Race {"Goblin", x, y, 110, 15, 20} {}

Goblin::~Goblin() {}

void Goblin::setHp(int h) {
    if (h > 110) hp = 110;
    else if (h < 0) hp = 0;
    else hp = h; 
}

void Goblin::attack(Living *e) {
    int damage = ceil((100.0/(100 + e->getDef()))) * getTotalAtk();
    if (e->defence(damage)) {
        if (e->getHp() == 0) { addScore(e->getValue() + 5); }
    }
}
