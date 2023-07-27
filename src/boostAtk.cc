#include <cstdlib>
#include <string>
#include "boostAtk.h"

using namespace std;

BoostAtk::BoostAtk(int x, int y): 
    Potion {"Boost Attack potion", 5, x, y} {}

BoostAtk::~BoostAtk() {}

string BoostAtk::getName() { return (unknown) ? "Unknown potion" : "Boost Attack potion"; }

void BoostAtk::setUnknown(bool status) { unknown = status; }
