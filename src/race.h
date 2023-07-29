#ifndef RACE_H
#define RACE_H

#include "living.h"

class Race: public Living {

    protected:
        int atkEffect = 0; // attack effect from potion
        int defEffect = 0; // defence effect from potion
        int numMoves = 0; // keep track of # moves
        int enemiesKilled = 0; // keep track of # kills

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
