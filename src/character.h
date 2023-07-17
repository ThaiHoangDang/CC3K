#ifndef CHAR_H
#define CHAR_H

#include "object.h"

class Character: public Object {
    int score;

    public:
        Character();
        ~Character();
};

#endif
