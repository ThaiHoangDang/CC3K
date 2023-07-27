#ifndef BDEF_H
#define BDEF_H

#include "potion.h"

class BoostDef: public Potion {
    inline static bool unknown = true;

    public:
        BoostDef(int x, int y);
        ~BoostDef();
        virtual std::string getName() override;
        virtual void setUnknown(bool status) override;
};

#endif
