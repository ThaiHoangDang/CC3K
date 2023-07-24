#ifndef ENEMY_H
#define ENEMY_H

#include "living.h"

class Enemy: public Living {
    int turnCount = 0;

    public:
        Enemy(char label, const std::string &name, int value, 
            int x, int y, int hp, int atk, int def);
        ~Enemy();
        virtual bool defence(int damage) override;
        void turn();
        void addOneTurn();
};

#endif
