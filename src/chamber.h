#ifndef CHAMBER_H
#define CHAMBER_H

#include <vector>


class Chamber {
    bool isExplored = false;
    std::vector<std::vector<int>> cells; // list of cells in chamber

    public:
        Chamber(int x, int y, const std::vector<char> &floorMap, int height, int width);
        ~Chamber();
        bool isIn(int x, int y);
        std::vector<int> getRandomCell();
        bool inOneBlockRadius(int x, int y);
        bool getIsExplored();
        void setIsExplored(bool status);
};

#endif
