#ifndef CHAMBER_H
#define CHAMBER_H

#include <vector>


class Chamber {
    std::vector<std::vector<int>> cells;

    public:
        Chamber(int x, int y, const std::vector<char> &floorMap, int height, int width);
        ~Chamber();
        bool is_in(int x, int y);
        std::vector<int> getRandomCell();
};

#endif
