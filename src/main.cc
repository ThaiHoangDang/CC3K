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


// print content of file
void printFile(const string &file) {
    ifstream f {file};

    string line;

    while (getline(f, line)) {
        cout << line << endl;
    }
}

// choose hero based on input
shared_ptr<Object> pickHero() {

    // display heroes
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

// generate seed and write to file
int seedGenerator() {
    ofstream os {"data/seeds.txt", std::ios::app};

    if (! os) {
        cerr << "Cannot find seeds.txt!" << endl;
        exit(1);
    }

    int seed = time(NULL);

    os << seed << endl;

    return seed;
}

// run the game
void run(const string &map, const int seed = seedGenerator()) {
    srand(seed);
    string input;

    // welcome message
    printFile("display/welcome.txt");

    while (input != "y") {
        cout << "Start? (y/n)" << endl;
        cin >> input;
    }

    // hero used in the game
    shared_ptr<Object> hero = pickHero();

    // generate map
    unique_ptr<Board> board = make_unique<Board>(map, hero);

    // game begin message
    printFile("display/begin.txt");

    // while (true) {
    board->display();
    // }


    // end / replay
}

// int main(int argc, char *argv[]) {
//     int seed;

//     if (argc == 1) {
//         run();
//     } else {
//         string arg {argv[1]};
//         run(arg);
//     }
// }

int main(int argc, char *argv[]) {

    if (argc == 1) {
        run("default.txt");
    } else {
        string map, seed;
        for (int i = 1; i < argc; i++) {
            string temp = argv[i];

            if ((temp == "-m") && (i != argc - 1)) {
                i++;
                map = argv[i];
            } else if ((temp == "-s") && (i != argc - 1)) {
                i++;
                seed = argv[i];
            }
        }

        if (map != "" && seed != "") run(map, stoi(seed));
        else if (map != "") run(map);
        else if (seed != "") run("default.txt", stoi(seed));
    }
}