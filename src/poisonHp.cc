#include <cstdlib>
#include "poisonHp.h"

using namespace std;

PoisonHp::PoisonHp(int x, int y): 
    Potion {"Poison HP potion", (rand() % 10) + 1, x, y} {}

PoisonHp::~PoisonHp() {}

string PoisonHp::getName() { return (unknown) ? "Unknown potion" : "Poison HP potion"; }

void PoisonHp::setUnknown(bool status) { unknown = status; }
