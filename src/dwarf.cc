#include <cstdlib>
#include "dwarf.h"

Dwarf::Dwarf(int x, int y): Enemy {'W', "Dwarf", (rand() % 2) + 1, x, y, 100, 20, 30} {}

Dwarf::~Dwarf() {}
