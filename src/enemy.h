#ifndef ENEMY_H
#define ENEMY_H

#include "living.h"

class Enemy: public Living {

    public:
        Enemy(char label, const std::string &name, int value, 
            int x, int y, int hp, int atk, int def);
        ~Enemy();
};

#endif
