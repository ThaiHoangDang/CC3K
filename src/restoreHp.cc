#include <cstdlib>
#include "restoreHp.h"

RestoreHp::RestoreHp(int x, int y): 
    Potion {"Restore HP potion", (rand() % 10) + 1, x, y} {}

RestoreHp::~RestoreHp() {}
