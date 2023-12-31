#include <cmath>
#include "race.h"

using namespace std;


Race::Race(const std::string &name, int x, int y, int hp, int atk, int def): 
    Living {'@', name, "blue", 0, x, y, hp, atk, def} {}


Race::~Race() {}


int Race::attack(Living *e) {
    // damage calculation formula
    int damage = ceil((100.0/(100 + e->getDef())) * getTotalAtk());

    if (e->defence(damage)) {
        if (e->getHp() == 0) { 
            addScore(e->getValue()); // update score
            addEnemiesKilled(); // update # of enemies killed
        }
        return damage;
    }
    return 0;
}


bool Race::defence(int damage) {

    // 50% chance race dodge enemies attack
    if (rand() % 2 == 0) {
        setHp(getHp() - damage);
        return true;
    } else {
        return false;
    }
}


void Race::addScore(int x) { setValue(getValue() + x); }


// reset potion effect when get to new floor
void Race::resetEffect() {
    atkEffect = 0;
    defEffect = 0;
}


void Race::addNumMove() { numMoves++; }


void Race::addEnemiesKilled() { enemiesKilled++; }


void Race::addHpEffect(int x) { setHp(getHp() + x); }


void Race::addAtkEffect(int x) { 
    atkEffect += x;
    if (atkEffect < -atk) atkEffect = -atk; // make sure that total atk >= 0
}


void Race::addDefEffect(int x) {
    defEffect += x;
    if (defEffect < -def) defEffect = -def; // make sure that total def >= 0
}


int Race::getAtkEffect() { return atkEffect; }


int Race::getDefEffect() { return defEffect; }


int Race::getTotalAtk() { return getAtk() + getAtkEffect(); }


int Race::getTotalDef() { return getDef() + getDefEffect(); }


int Race::getNumMove() { return numMoves; }


int Race::getNumEnemiesKilled() { return enemiesKilled; }
