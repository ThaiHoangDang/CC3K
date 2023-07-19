#include <cstdlib>
#include "elf.h"

Elf::Elf(int x, int y): Enemy {'E', "Elf", (rand() % 2) + 1, x, y, 140, 30, 10} {}

Elf::~Elf() {}
