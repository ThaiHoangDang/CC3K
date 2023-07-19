#ifndef DRAGON_H
#define DRAGON_H

#include <memory>
#include "enemy.h"
#include "dragonHoard.h"

class Dragon: public Enemy {
    std::shared_ptr<DragonHoard> guard;

    public: 
        Dragon(int x, int y, std::shared_ptr<DragonHoard> guard = nullptr);
        ~Dragon();
};

#endif
