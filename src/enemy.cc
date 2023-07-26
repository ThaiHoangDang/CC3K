#include <cmath>
#include <cstdlib>
#include "enemy.h"

using namespace std;

Enemy::Enemy(char label, const std::string &name, 
    int value, int x, int y, int hp, int atk, int def):
    Living {label, name, "red", value, x, y, hp, atk, def} {}

Enemy::~Enemy() {}

int Enemy::attack(Living *l) {
    int damage = ceil((100.0/(100 + l->getDef()))) * getAtk();
    if (l->defence(damage)) return damage;
    return 0;
}

bool Enemy::defence(int damage) {
    setHp(getHp() - damage);
    return true;
}

unsigned int Enemy::getTurn() { return turnCount; }

void Enemy::addOneTurn() { turnCount++; }
