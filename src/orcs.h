#ifndef ORCS_H
#define ORCS_H

#include "enemy.h"

class Orcs: public Enemy {

    public: 
        Orcs(int x, int y);
        ~Orcs();
        virtual void setHp(int h) override;
};

#endif