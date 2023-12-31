#ifndef DRAGON_H
#define DRAGON_H

#include <memory>
#include "enemy.h"
#include "dragonHoard.h"

class Dragon: public Enemy {
    DragonHoard* guard;

    public: 
        Dragon(int x, int y, DragonHoard *guard = nullptr);
        ~Dragon();
        virtual void setHp(int h) override;
        virtual bool inOneBlockRadius(const Object *other);
        void setGuard(DragonHoard* g);
};

#endif
