#include <cstdlib>
#include "halfling.h"

Halfling::Halfling(int x, int y): Enemy {'L', "Halfling", (rand() % 2) + 1, x, y, 100, 15, 20} {}

Halfling::~Halfling() {}
