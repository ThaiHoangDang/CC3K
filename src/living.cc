#include "living.h"

Living::Living(char label, const std::string &name, const std::string &color,
    int value, int x, int y, int hp, int atk, int def): 
    Object {label, name, color, value, x, y}, 
    hp {hp}, atk {atk}, def {def} {}

Living::~Living() {}

