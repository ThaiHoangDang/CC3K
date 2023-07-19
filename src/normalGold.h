#ifndef NGOLD_H
#define NGOLD_H

#include "treasure.h"

class NormalGold: public Treasure {

    public:
        NormalGold(int x, int y);
        ~NormalGold();
};

#endif
