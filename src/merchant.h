#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"

class Merchant: public Enemy {
    inline static bool isHostile = false; // only attack if hostile

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
