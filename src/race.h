#ifndef RACE_H
#define RACE_H

#include "living.h"

class Race: public Living {

    public:
        Race(const std::string &name, int x, int y, int hp, int atk, int def);
        ~Race();
};

#endif
