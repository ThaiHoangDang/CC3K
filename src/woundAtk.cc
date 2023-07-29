#include <cstdlib>
#include "woundAtk.h"

using namespace std;


WoundAtk::WoundAtk(int x, int y): 
    Potion {"Wound Attack potion", 5, x, y} {}


WoundAtk::~WoundAtk() {}


string WoundAtk::getName() { return (unknown) ? "Unknown potion" : "Wound Attack potion"; }


void WoundAtk::setUnknown(bool status) { unknown = status; }
