#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"

class Merchant: public Enemy {
    inline static bool isHostile = false;

    public: 
        Merchant(int x, int y);
        ~Merchant();
};

#endif
