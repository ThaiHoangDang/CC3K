#include <cstdlib>
#include "human.h"

Human::Human(int x, int y): Enemy {'H', "Human", 4, x, y, 140, 20, 20} {}

Human::~Human() {}

void Human::setHp(int h) {
    if (h > 140) hp = 140;
    else if (h < 0) hp = 0;
    else hp = h;
}
