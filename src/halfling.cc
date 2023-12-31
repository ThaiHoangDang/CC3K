#include <cstdlib>
#include "halfling.h"


const int defaultHP = 100, defaultAtk = 15, defaultDef = 20;


Halfling::Halfling(int x, int y): 
    Enemy {'L', "Halfling", (rand() % 2) + 1, x, y, defaultHP, defaultAtk, defaultDef} {}


Halfling::~Halfling() {}


// 50% chance dodge attack
bool Halfling::defence(int damage) {
    if (rand() % 2 == 0) {
        return false;
    } else {
        setHp(getHp() - damage);
        return true;
    }
}


void Halfling::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;
}
