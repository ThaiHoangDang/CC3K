#ifndef GOBLIN_H
#define GOBLIN_H

#include "race.h"

class Goblin: public Race {

    public:
        Goblin(int x, int y);
        ~Goblin();
        virtual void setHp(int h) override;
        virtual int attack(Living *e);
};

#endif
