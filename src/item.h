#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "object.h"

class Item: public Object {

    public:
        Item(char label, const std::string &name, 
            const std::string &color, int value, int x, int y);
        ~Item();
};

#endif
