#ifndef DGOLD_H
#define DGOLD_H

#include "treasure.h"

class DragonHoard: public Treasure {
    bool isGuarded = false;

    public:
        DragonHoard(int x, int y);
        ~DragonHoard();
        bool getIsGuarded();
        void setIsGuarded(bool status);
};

#endif
