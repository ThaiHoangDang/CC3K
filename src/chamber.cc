#include <vector>
#include <iostream>
#include <cstdlib>
#include "chamber.h"

using namespace std;


bool in_cells(vector<vector<int>> &cells, int x, int y) {
    for (const auto &it : cells) {
        if (it.at(0) == x && it.at(1) == y) {
            return true;
        }
    }
    return false;
}

bool in_queue(vector<vector<int>> &queue, int x, int y) {
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

    while (! stack.empty()) {
        auto value = stack.back();
        stack.pop_back();

        cells.emplace_back(value);

        int x = value.at(0);
        int y = value.at(1);

        if ((floorMap.at((y + 1) * width + x) == '.') &&
                 (! in_cells(cells, x, y + 1)) && 
                 (! in_queue(stack, x, y + 1))) {
            stack.emplace_back(vector<int> {x, y + 1});
        }
    
        if ((floorMap.at((y - 1) * width + x) == '.') &&
                 (! in_cells(cells, x, y - 1)) && 
                 (! in_queue(stack, x, y - 1))) {
            stack.emplace_back(vector<int> {x, y - 1});
        }

        if ((floorMap.at(y * width + x - 1) == '.') &&
                 (! in_cells(cells, x - 1, y)) && 
                 (! in_queue(stack, x - 1, y))) {
            stack.emplace_back(vector<int> {x - 1, y});
        }

        if ((floorMap.at(y * width + x + 1) == '.') &&
                 (! in_cells(cells, x + 1, y)) && 
                 (! in_queue(stack, x + 1, y))) {
            stack.emplace_back(vector<int> {x + 1, y});
        }
    }
}

Chamber::~Chamber() {}

bool Chamber::is_in(int x, int y) {
    for (const auto &it : cells) {
        if (it.at(0) == x && it.at(1) == y) {
            return true;
        }
    }
    return false;
}

vector<int> Chamber::getRandomCell() {
    int random = rand() % cells.size();
    return cells.at(random);
}
