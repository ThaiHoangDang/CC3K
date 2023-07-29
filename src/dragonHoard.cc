#include "dragonHoard.h"


DragonHoard::DragonHoard(int x, int y): Treasure {"Dragon Hoard", 6, x, y} {}


DragonHoard::~DragonHoard() {}


bool DragonHoard::getIsGuarded() { return isGuarded; }


void DragonHoard::setIsGuarded(bool status) { isGuarded = status; }
