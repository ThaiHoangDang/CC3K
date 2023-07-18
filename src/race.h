#ifndef CHAR_H
#define CHAR_H

#include "object.h"

class Race: public Object {
    int score;

    public:
        Race();
        ~Race();
};

#endif
