#include "enemy.h"

using namespace std;

Enemy::Enemy(char label, const std::string &name, 
    int value, int x, int y, int hp, int atk, int def):
    Living {label, name, "red", value, x, y, hp, atk, def} {}

Enemy::~Enemy() {}
