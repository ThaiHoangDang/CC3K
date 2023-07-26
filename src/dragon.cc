#include "dragon.h"

using namespace std;

Dragon::Dragon(int x, int y, DragonHoard *guard): 
    Enemy {'D', "Dragon", 0, x, y, 150, 20, 20}, guard {guard} {}

Dragon::~Dragon() {}

void Dragon::setHp(int h) {
    if (h > 150) hp = 150;
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
