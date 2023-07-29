#include <cstdlib>
#include "potionGenerator.h"
#include "potion.h"
#include "restoreHp.h"
#include "boostAtk.h"
#include "boostDef.h"
#include "poisonHp.h"
#include "woundAtk.h"
#include "woundDef.h"

using namespace std;


// create potion based on proportion
shared_ptr<Object> PotionGenerator::createObject(int x, int y) {
    int random = rand() % 6;

    if (random == 0) return make_shared<RestoreHp>(x, y);
    else if (random == 1) return make_shared<BoostAtk>(x, y);
    else if (random == 2) return make_shared<BoostDef>(x, y);
    else if (random == 3) return make_shared<PoisonHp>(x, y);
    else if (random == 4) return make_shared<WoundAtk>(x, y);
    else return make_shared<WoundDef>(x, y);
}
