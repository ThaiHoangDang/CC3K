#ifndef OGEN_H
#define OGEN_H

#include <memory>
#include "object.h"
#include "enemy.h"
#include "potion.h"


class ObjectGenerator {

    public:
        virtual std::shared_ptr<Object> createObject(int x, int y) = 0;
};

#endif
