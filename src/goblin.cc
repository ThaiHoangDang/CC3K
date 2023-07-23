#include "goblin.h"

Goblin::Goblin(int x, int y): Race {"Goblin", x, y, 110, 15, 20} {}

Goblin::~Goblin() {}

void Goblin::setHp(int h) {
    if (h > 110) hp = 110;
    else if (h < 0) hp = 0;
    else hp = h; 
}
