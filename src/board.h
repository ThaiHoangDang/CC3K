#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "character.h"
#include "object.h"

class Board {
    Character &hero;
    std::vector<std::vector<char>> maps;
    std::vector<std::vector<std::unique_ptr<Object>>> objects;

    const int height = 25, width = 79;
    int currentFloor = 0;
    std::string message;

    public:
        Board(const std::string &map, Character &hero);
        ~Board();
        void display();
};

#endif
