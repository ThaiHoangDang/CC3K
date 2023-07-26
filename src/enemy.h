#ifndef ENEMY_H
#define ENEMY_H

#include "living.h"

class Enemy: public Living {
    unsigned int turnCount = 0;

    public:
        Enemy(char label, const std::string &name, int value, 
            int x, int y, int hp, int atk, int def);
        ~Enemy();
        virtual int attack(Living *l);
        virtual bool defence(int damage) override;
        unsigned int getTurn();
        void turn();
        void addOneTurn();
};

#endif
