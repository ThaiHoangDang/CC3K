#include <cstdlib>
#include "orcs.h"

Orcs::Orcs(int x, int y): Enemy {'O', "Orcs", (rand() % 2) + 1, x, y, 180, 30, 25} {}

Orcs::~Orcs() {}
