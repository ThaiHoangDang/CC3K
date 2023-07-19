#ifndef RHP_H
#define RHP_H

#include "potion.h"

class RestoreHp: public Potion {
    inline static bool unknown = true;

    public:
        RestoreHp(int x, int y);
        ~RestoreHp();
};

#endif
