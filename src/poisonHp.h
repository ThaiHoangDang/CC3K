#ifndef PHP_H
#define PHP_H

#include "potion.h"

class PoisonHp: public Potion {
    inline static bool unknown = true;

    public:
        PoisonHp(int x, int y);
        ~PoisonHp();
};

#endif
