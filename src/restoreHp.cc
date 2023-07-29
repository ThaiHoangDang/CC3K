#include <cstdlib>
#include <string>
#include "restoreHp.h"

using namespace std;


RestoreHp::RestoreHp(int x, int y): 
    Potion {"Restore HP potion", (rand() % 10) + 1, x, y} {}


RestoreHp::~RestoreHp() {}


string RestoreHp::getName() { return (unknown) ? "Unknown potion" : "Restore HP potion"; }


void RestoreHp::setUnknown(bool status) { unknown = status; }
