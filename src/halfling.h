#ifndef HALF_H
#define HALF_H

#include "enemy.h"

class Halfling: public Enemy {

    public: 
        Halfling(int x, int y);
        ~Halfling();
        virtual bool defence(int damage) override;
        virtual void setHp(int h) override;
};

#endif
