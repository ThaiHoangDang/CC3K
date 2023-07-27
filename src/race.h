#ifndef RACE_H
#define RACE_H

#include "living.h"

class Race: public Living {
    protected:
        int atkEffect = 0;
        int defEffect = 0;
        int numMoves = 0;
        int enemiesKilled = 0;

    public:
        Race(const std::string &name, int x, int y, int hp, int atk, int def);
        ~Race();
        virtual int attack(Living *e);
        virtual bool defence(int damage) override;
        virtual void addScore(int);
        void resetEffect();
        virtual void addNumMove();
        void addEnemiesKilled();
        virtual void addHpEffect(int x);
        virtual void addAtkEffect(int x);
        virtual void addDefEffect(int x);
        int getAtkEffect();
        int getDefEffect();
        int getTotalAtk();
        int getTotalDef();
        int getNumMove();
        int getNumEnemiesKilled();
};

#endif
