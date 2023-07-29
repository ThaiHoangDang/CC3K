#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

class Treasure: public Item {

    public:
        Treasure(const std::string &name, int value, int x, int y);
        virtual ~Treasure();
};

#endif
