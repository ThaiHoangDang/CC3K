#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "race.h"
#include "object.h"
#include "chamber.h"

class Board {
    std::shared_ptr<Object> hero;
    std::vector<std::vector<int>> heroPositions;
    std::vector<std::vector<char>> maps;
    std::vector<std::vector<std::shared_ptr<Object>>> objects;
    std::vector<std::vector<std::unique_ptr<Chamber>>> chambers;

    const int height = 25, width = 79, numPotions = 10, numEnemies = 20, numGold = 10;
    unsigned int currentFloor = 0, enemiesTurn = 0;
    std::string message = "Player Character has been spawned";

    public:
        Board(const std::string &map, std::shared_ptr<Object> hero);
        ~Board();
        void addTurn();
        int getCurFloor();
        int getNumFloor();
        void moveHero(const std::string &dir);
        void display();
};

#endif
