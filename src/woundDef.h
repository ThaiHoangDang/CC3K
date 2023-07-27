#ifndef WDEF_H
#define WDEF_H

#include "potion.h"

class WoundDef: public Potion {
    inline static bool unknown = true;

    public:
        WoundDef(int x, int y);
        ~WoundDef();
        virtual std::string getName() override;
        virtual void setUnknown(bool status) override;
};

#endif
