#include <cstdlib>
#include "treasureGenerator.h"
#include "treasure.h"
#include "normalGold.h"
#include "smallGold.h"
#include "dragonHoard.h"

using namespace std;


shared_ptr<Object> TreasureGenerator::createObject(int x, int y) {
    int random = rand() % 8;

    if (random >= 0 && random <= 4) return make_shared<NormalGold>(x, y);
    else if (random == 5) return make_shared<DragonHoard>(x, y);
    else return make_shared<SmallGold>(x, y);
}
