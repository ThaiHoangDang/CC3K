#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "race.h"
#include "object.h"
#include "extender.h"

class Board {
    std::shared_ptr<Object> hero;
    std::string mode; // game mode
    std::vector<std::vector<int>> heroPositions; // hero positions in each floor 
    std::vector<std::vector<char>> maps; // map layout of all floors
    std::vector<std::vector<std::shared_ptr<Object>>> objects; // objects layout of all floors
    std::vector<std::vector<std::unique_ptr<Extender>>> chambers; // chambers of all floors
    std::vector<std::vector<std::unique_ptr<Extender>>> passages; // passages of all floors

    const int numPotions = 10, numEnemies = 20, numGold = 10;
    int width, height;
    unsigned int currentFloor = 0, enemiesTurn = 0;
    std::string message = "Player Character has been spawned";

    public:
        Board(const std::string &map, std::shared_ptr<Object> hero, std::string mode);
        ~Board();
        void addTurn();
        void resetTurn();
        int getCurFloor();
        int getNumFloor();
        void moveHero(const std::string &dir);
        void moveEnemies();
        void printTile(int x, int y);
        void display();
};

#endif
