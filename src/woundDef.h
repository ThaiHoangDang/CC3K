#ifndef WDEF_H
#define WDEF_H

#include "potion.h"

class WoundDef: public Potion {
    inline static bool unknown = true;

    public:
        WoundDef(int x, int y);
        ~WoundDef();
};

#endif
