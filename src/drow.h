#ifndef DROW_H
#define DROW_H

#include "race.h"

class Drow: public Race {

    public:
        Drow(int x, int y);
        ~Drow();
        virtual void setHp(int h) override;
        virtual void addHpEffect(int x);
        virtual void addAtkEffect(int x);
        virtual void addDefEffect(int x);
};

#endif
