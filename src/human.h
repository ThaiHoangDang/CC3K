#ifndef HUMAN_H
#define HUMAN_H

#include "enemy.h"

class Human: public Enemy {

    public: 
        Human(int x, int y);
        ~Human();
        virtual void setHp(int h) override;
};

#endif
