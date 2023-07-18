#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "race.h"
#include "object.h"
#include "chamber.h"

class Board {
    Race &hero;
    std::vector<std::vector<char>> maps;
    std::vector<std::vector<std::unique_ptr<Object>>> objects;
    std::vector<std::vector<std::unique_ptr<Chamber>>> chambers;

    const int height = 25, width = 79;
    int currentFloor = 0;
    std::string message;

    public:
        Board(const std::string &map, Race &hero);
        ~Board();
        void display();
};

#endif
