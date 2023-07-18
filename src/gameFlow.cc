#include <iostream>
#include <string>
#include <memory>
#include "gameFlow.h"
#include "race.h"
#include "board.h"

using namespace std;

GameFlow::GameFlow(const string &map): map {map} {}

GameFlow::~GameFlow() {}

void GameFlow::run() {
    
    // welcome
    cout << "Welcome to CC3k" << endl;

    // choose race
    cout << "Choose your hero" << endl;
    unique_ptr<Race> hero = make_unique<Race>();

    // generate map (Factory Method?)
    unique_ptr<Board> board = make_unique<Board>(map, *hero.get());

    // loop
    // while (true) {
    board->display();
    // }


    // end / replay
}
