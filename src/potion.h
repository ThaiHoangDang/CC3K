#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion: public Item {

    public:
        Potion(const std::string &name, int value, int x, int y);
        ~Potion();
        virtual void setUnknown(bool status) = 0;
};

#endif
