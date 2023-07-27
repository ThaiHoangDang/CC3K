#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "race.h"

class Vampire: public Race {

    public:
        Vampire(int x, int y);
        ~Vampire();
        virtual void setHp(int h) override;
        virtual int attack(Living *e);
};

#endif
