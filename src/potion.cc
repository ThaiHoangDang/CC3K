#include "potion.h"


Potion::Potion(const std::string &name, int value, int x, int y):
    Item {'P', name, "green", value, x, y} {}


Potion::~Potion() {}
