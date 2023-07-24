#include <cstdlib>
#include "poisonHp.h"

PoisonHp::PoisonHp(int x, int y): 
    Potion {"Poison HP potion", (rand() % 10) + 1, x, y} {}

PoisonHp::~PoisonHp() {}
