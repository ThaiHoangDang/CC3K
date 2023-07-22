#ifndef EGEN_H
#define EGEN_H

#include "objectGenerator.h"
#include "enemy.h"

class EnemyGenerator: public ObjectGenerator {

    public:
        virtual std::shared_ptr<Object> createObject(int x, int y) override;
};

#endif
