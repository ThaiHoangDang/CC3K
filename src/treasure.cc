#include "treasure.h"


Treasure::Treasure(const std::string &name, int value, int x, int y):
    Item {'G', name, "yellow", value, x, y} {}


Treasure::~Treasure() {}
