#ifndef GAME_H
#define GAME_H

#include <string>

class GameFlow {
    std::string map;

    public:
        explicit GameFlow(const std::string &map = "cc3k-emptySingleFloor.txt");
        ~GameFlow();
        void run();

};

#endif