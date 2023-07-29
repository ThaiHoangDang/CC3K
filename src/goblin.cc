#include <cmath>
#include "goblin.h"


const int defaultHP = 110, defaultAtk = 15, defaultDef = 20;


Goblin::Goblin(int x, int y): Race {"Goblin", x, y, defaultHP, defaultAtk, defaultDef} {}


Goblin::~Goblin() {}


void Goblin::setHp(int h) {
    if (h > defaultHP) hp = defaultHP;
    else if (h < 0) hp = 0;
    else hp = h; 
}


// get 5 gold after killing an enemies
int Goblin::attack(Living *e) {
    int damage = ceil((100.0/(100 + e->getDef())) * getTotalAtk());
    if (e->defence(damage)) {
        if (e->getHp() == 0) { 
            addScore(e->getValue() + 5); 
            addEnemiesKilled();    
        }
        return damage;
    }
    return 0;

}
