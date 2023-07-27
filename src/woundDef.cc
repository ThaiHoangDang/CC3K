#include <cstdlib>
#include "woundDef.h"

using namespace std;

WoundDef::WoundDef(int x, int y): 
    Potion {"Wound Defence potion", 5, x, y} {}

WoundDef::~WoundDef() {}

string WoundDef::getName() { return (unknown) ? "Unknown potion" : "Wound Defence potion"; }

void WoundDef::setUnknown(bool status) { unknown = status; }
