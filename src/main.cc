#include <string>
#include <fstream>
#include <iostream>
#include "board.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

using namespace std;


void printFile(const string &file) {
    ifstream f {file};

    string line;

    while (getline(f, line)) {
        cout << line << endl;
    }
}


shared_ptr<Object> pickHero() {
    printFile("display/heroes.txt");

    while (true) {
        string input;
        cout << "Enter (Shade/Drow/Vampire/Troll/Goblin):" << endl;
        cin >> input;

        if (input == "Shade" || input == "shade") {
            return make_shared<Shade>(0, 0);
        } else if (input == "Drow" || input == "drow") {
            return make_shared<Drow>(0, 0);
        } else if (input == "Vampire" || input == "vampire") {
            return make_shared<Vampire>(0, 0);
        } else if (input == "Troll" || input == "troll") {
            return make_shared<Troll>(0, 0);
        } else if (input == "Goblin" || input == "goblin") {
            return make_shared<Goblin>(0, 0);
        } else {
            cout << "Cannot find hero!" << endl;
        }
    }
}

void run(const string &map = "cc3k-emptySingleFloor.txt") {
    string input;

    printFile("display/welcome.txt");

    while (input != "y") {
        cout << "Start? (y/n)" << endl;
        cin >> input;
    }

    shared_ptr<Object> hero = pickHero();

    // generate map (Factory Method?)
    unique_ptr<Board> board = make_unique<Board>(map, hero);

    printFile("display/begin.txt");
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
