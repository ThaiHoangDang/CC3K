#include <cstdlib>
#include "human.h"


const int defaultHP = 140, defaultAtk = 20, defaultDef = 20;


Human::Human(int x, int y): Enemy {'H', "Human", 4, x, y, defaultHP, defaultAtk, defaultDef} {}


Human::~Human() {}


void Human::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}
