#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"

class Merchant: public Enemy {
    static bool isHostile;

    public: 
        Merchant(int x, int y);
        ~Merchant();
        virtual int attack(Living *l);
        virtual bool defence(int damage);
        virtual void setHp(int h) override;
        bool getIsHostile();
        void setIsHostile(bool status);
};

#endif
