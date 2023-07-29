#include <vector>
#include <iostream>
#include <cstdlib>
#include "chamber.h"

using namespace std;


// check if block with x, y is in cells
bool in_cells(vector<vector<int>> &cells, int x, int y) {
    for (const auto &it : cells) {
        if (it.at(0) == x && it.at(1) == y) {
            return true;
        }
    }
    return false;
}


// check if a block is in stack
bool in_stack(vector<vector<int>> &queue, int x, int y) {
    for (const auto &it : queue) {
        if (it.at(0) == x && it.at(1) == y) {
            return true;
        }
    }
    return false;    
}


Chamber::Chamber(int x, int y, const std::vector<char> &floorMap, int height, int width) {

    vector<vector<int>> stack;
    stack.emplace_back(vector<int> {x, y});

    // continiously expanding
    while (! stack.empty()) {
        auto value = stack.back();
        stack.pop_back();

        cells.emplace_back(value); // add new blocks cells

        int x = value.at(0);
        int y = value.at(1);

        // expand down
        if ((floorMap.at((y + 1) * width + x) == '.') &&
                 (! in_cells(cells, x, y + 1)) && 
                 (! in_stack(stack, x, y + 1))) {
            stack.emplace_back(vector<int> {x, y + 1});
        }
    
        // expand up
        if ((floorMap.at((y - 1) * width + x) == '.') &&
                 (! in_cells(cells, x, y - 1)) && 
                 (! in_stack(stack, x, y - 1))) {
            stack.emplace_back(vector<int> {x, y - 1});
        }

        // expand left
        if ((floorMap.at(y * width + x - 1) == '.') &&
                 (! in_cells(cells, x - 1, y)) && 
                 (! in_stack(stack, x - 1, y))) {
            stack.emplace_back(vector<int> {x - 1, y});
        }

        // expand right
        if ((floorMap.at(y * width + x + 1) == '.') &&
                 (! in_cells(cells, x + 1, y)) && 
                 (! in_stack(stack, x + 1, y))) {
            stack.emplace_back(vector<int> {x + 1, y});
        }
    }
}


Chamber::~Chamber() {}


// check if a block is in chamber
bool Chamber::is_in(int x, int y) {
    for (const auto &it : cells) {
        if (it.at(0) == x && it.at(1) == y) {
            return true;
        }
    }
    return false;
}


// get a random cell in chamber
vector<int> Chamber::getRandomCell() {
    int random = rand() % cells.size();
    return cells.at(random);
}
