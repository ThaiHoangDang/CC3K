#include <string>
#include <iostream>
#include "board.h"

using namespace std;


void welcome() {
    cout << "__________ welcome to __________" << endl;
    cout << " ______  ______  ______  __  __" << endl;
    cout << "|   ___||   ___||___   ||  |/ /" << endl;
    cout << "|   |__ |   |__ |___   ||     \\" << endl;
    cout << "|______||______||______||__|\\__\\ " << endl;
    cout << "________________________________" << endl << endl << endl;
}

// unique_ptr<Object> pickHero() {

// }

void run(const string &map = "cc3k-emptySingleFloor.txt") {
    // welcome
    welcome();

    // choose race
    cout << "Choose your hero" << endl;
    shared_ptr<Object> hero = make_shared<Race>("Hoang", 0, 0, 1000, 1000, 1000);

    // generate map (Factory Method?)
    unique_ptr<Board> board = make_unique<Board>(map, hero);

    // loop
    // while (true) {
    board->display();
    // }


    // end / replay
}

int main(int argc, char *argv[]) {

    if (argc == 1) {
        run();
    } else {
        string arg {argv[1]};
        run(arg);
    }
}
