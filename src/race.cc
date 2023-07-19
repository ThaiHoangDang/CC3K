#include "race.h"

using namespace std;

Race::Race(const std::string &name, int x, int y, int hp, int atk, int def): 
    Living {'@', name, "blue", 0, x, y, hp, atk, def} {}

Race::~Race() {}
