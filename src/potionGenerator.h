#ifndef PGEN_H
#define PGEN_H

#include "objectGenerator.h"
#include "potion.h"

class PotionGenerator: public ObjectGenerator {

    public:
        virtual std::shared_ptr<Object> createObject(int x, int y) override;
};

#endif
