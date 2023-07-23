#include "dragon.h"

using namespace std;

Dragon::Dragon(int x, int y, DragonHoard *guard): 
    Enemy {'D', "Dragon", 0, x, y, 150, 20, 20}, guard {guard} {}

Dragon::~Dragon() {}
