#include <cstdlib>
#include "boostDef.h"

using namespace std;

BoostDef::BoostDef(int x, int y): 
    Potion {"Boost Defence potion", 5, x, y} {}

BoostDef::~BoostDef() {}

string BoostDef::getName() { return (unknown) ? "Unknown potion" : "Boost Defence potion"; }

void BoostDef::setUnknown(bool status) { unknown = status; }
