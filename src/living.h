#ifndef LIVING_H
#define LIVING_H

#include <string>
#include "object.h"

class Living: public Object {

    protected:
        int hp;
        int atk;
        int def;

    public:
        Living(char label, const std::string &name, const std::string &color, 
            int value, int x, int y, int hp, int atk, int def);
        virtual ~Living();
        virtual int attack(Living *l) = 0;
        virtual bool defence(int damage) = 0;
        virtual int getHp();
        virtual int getAtk();
        virtual int getDef();
        virtual void setHp(int h);
        virtual void setAtk(int a);
        virtual void setDef(int d);
};

#endif
