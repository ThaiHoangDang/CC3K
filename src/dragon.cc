#include "dragon.h"

using namespace std;

const int defaultHP = 150, defaultAtk = 20, defaultDef = 20;

Dragon::Dragon(int x, int y, DragonHoard *guard): 
    Enemy {'D', "Dragon", 0, x, y, defaultHP, defaultAtk, defaultDef}, guard {guard} {}

Dragon::~Dragon() {}

void Dragon::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h;

    if (hp == 0) guard->setIsGuarded(false);
}

bool Dragon::inOneBlockRadius(const Object *other) {
    if (other == nullptr) return false;
    return (((other->getX() >= getX() - 1) && (other->getX() <= getX() + 1) && 
        (other->getY() >= getY() - 1) && (other->getY() <= getY() + 1))) || 
        guard->inOneBlockRadius(other);
}

void Dragon::setGuard(DragonHoard* g) { guard = g; }
