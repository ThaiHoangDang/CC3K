#ifndef TGEN_H
#define TGEN_H

#include "objectGenerator.h"
#include "treasure.h"

class TreasureGenerator: public ObjectGenerator {

    public:
        virtual std::shared_ptr<Object> createObject(int x, int y) override;
};

#endif
