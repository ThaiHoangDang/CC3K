#ifndef SGOLD_H
#define SGOLD_H

#include "treasure.h"

class SmallGold: public Treasure {

    public:
        SmallGold(int x, int y);
        ~SmallGold();
};

#endif
