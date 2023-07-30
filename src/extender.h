#ifndef EXTEND_H
#define EXTEND_H

#include <vector>


class Extender {
    bool isExplored = false;
    std::vector<std::vector<int>> cells; // list of cells

    public:
        Extender(char c, int x, int y, const std::vector<char> &floorMap, int width);
        ~Extender();
        bool isIn(int x, int y);
        std::vector<int> getRandomCell();
        bool inOneBlockRadius(int x, int y);
        bool getIsExplored();
        void setIsExplored(bool status);
};

#endif
