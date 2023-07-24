#include <cmath>
#include "race.h"

using namespace std;

Race::Race(const std::string &name, int x, int y, int hp, int atk, int def): 
    Living {'@', name, "blue", 0, x, y, hp, atk, def} {}

Race::~Race() {}

void Race::attack(Living *e) {
    int damage = ceil((100.0/(100 + e->getDef()))) * getTotalAtk();
    if (e->defence(damage)) {
        if (e->getHp() == 0) { addScore(e->getValue()); }
    }
}

bool Race::defence(int damage) {

}

void Race::addScore(int x) { setValue(getValue() + x); }

void Race::resetEffect() {
    atkEffect = 0;
    defEffect = 0;
}

void Race::addHpEffect(int x) { setHp(getHp() + x); }

void Race::addAtkEffect(int x) { 
    atkEffect += x;
    if (atkEffect < -atk) atkEffect = -atk;
}

void Race::addDefEffect(int x) {
    defEffect += x;
    if (defEffect < -def) defEffect = -def;
}

int Race::getAtkEffect() { return atkEffect; }

int Race::getDefEffect() { return defEffect; }

int Race::getTotalAtk() { return getAtk() + getAtkEffect(); }

int Race::getTotalDef() { return getDef() + getDefEffect(); }
