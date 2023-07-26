#ifndef SHADE_H
#define SHADE_H

#include "race.h"

class Shade: public Race {

    public:
        Shade(int x, int y);
        ~Shade();
        virtual void setHp(int h) override;
        virtual int getValue() override;
};

#endif
