#ifndef PGOLD_H
#define PGOLD_H

#include "treasure.h"

class PrizeGold: public Treasure {

    public:
        PrizeGold(const std::string &name, int value, int x, int y);
        ~PrizeGold();
};

#endif
