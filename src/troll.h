#ifndef TROLL_H
#define TROLL_H

#include "race.h"

class Troll: public Race {

    public:
        Troll(int x, int y);
        ~Troll();
        virtual void setHp(int h) override;
        virtual void addNumMove() override;
};

#endif
