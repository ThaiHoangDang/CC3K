#ifndef WATK_H
#define WATK_H

#include "potion.h"

class WoundAtk: public Potion {
    inline static bool unknown = true;

    public:
        WoundAtk(int x, int y);
        ~WoundAtk();
        virtual std::string getName() override;
        virtual void setUnknown(bool status) override;
};

#endif
