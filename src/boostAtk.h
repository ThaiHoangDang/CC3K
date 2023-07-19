#ifndef BATK_H
#define BATK_H

#include "potion.h"

class BoostAtk: public Potion {
    inline static bool unknown = true;

    public:
        BoostAtk(int x, int y);
        ~BoostAtk();
};

#endif
