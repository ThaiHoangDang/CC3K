#include <cstdlib>
#include "enemyGenerator.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"

using namespace std;


shared_ptr<Object> EnemyGenerator::createObject(int x, int y) {
    int random = rand() % 18;

    if (random >= 0 && random <= 3) return make_shared<Human>(x, y);
    else if (random >= 4 && random <= 6) return make_shared<Dwarf>(x, y);
    else if (random >= 7 && random <= 11) return make_shared<Halfling>(x, y);
    else if (random >= 12 && random <= 13) return make_shared<Elf>(x, y);
    else if (random >= 14 && random <= 15) return make_shared<Orcs>(x, y);
    else return make_shared<Merchant>(x, y);
}
