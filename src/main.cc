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

        cout << "Hero: ";
        cin >> input;

        if (cin.eof()) return nullptr;

        if (input == "Shade" || input == "shade" || input == "s") {
            return make_shared<Shade>(0, 0);
        } else if (input == "Drow" || input == "drow" || input == "d") {
            return make_shared<Drow>(0, 0);
        } else if (input == "Vampire" || input == "vampire" || input == "v") {
            return make_shared<Vampire>(0, 0);
        } else if (input == "Troll" || input == "troll" || input == "t") {
            return make_shared<Troll>(0, 0);
        } else if (input == "Goblin" || input == "goblin" || input == "g") {
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
bool run(const string &map, const int seed = seedGenerator()) {

    srand(seed); // run seed
    string input, command;
    bool enemyTurn = true;

    // welcome message
    printFile("display/welcome.txt");

    while (input != "y") {
        cout << "Start? (y/n)" << endl;
        cin >> input;

        if (cin.eof() || input == "q") return 0;
    }

    // pick hero
    shared_ptr<Object> hero = pickHero();
    if (hero == nullptr) return 0;

    // generate map
    unique_ptr<Board> board = make_unique<Board>(map, hero);

    // game begin message
    printFile("display/begin.txt");

    // 
    board->display();

    while (cin >> command) {
        if (command == "no") {
            board->moveHero("no");
        } else if (command == "so") {
            board->moveHero("so");
        } else if (command == "ea") {
            board->moveHero("ea");
        } else if (command == "we") {
            board->moveHero("we");
        } else if (command == "ne") {
            board->moveHero("ne");
        } else if (command == "nw") {
            board->moveHero("nw");
        } else if (command == "se") {
            board->moveHero("se");
        } else if (command == "sw") {
            board->moveHero("sw");
        } else if (command == "u" || command == "a") {
            cin >> input;
            if (input == "no" || input == "so" || input == "ea" || input == "we" || 
                input == "ne" || input == "nw" || input == "se" || input == "sw") {
                board->moveHero(input);
            } else {
                cout << "Invalid direction!" << endl;
                continue;
            }
        } else if (command == "f") {
            enemyTurn = (enemyTurn == true) ? false : true;
        } else if (command == "r") {
            return 1;
        } else if (command == "q") {
            return 0;
        } else {
            cout << "Invalid command!" << endl;
            continue;
        }

        if (enemyTurn) {
            // enemies turn

            board->addTurn();
        }

        board->display();

    }

    if (cin.eof()) return 0;


    // end / replay
}

int main(int argc, char *argv[]) {

    if (argc == 1) {
        while (run("default.txt"));
    } else if (argc == 2) {
        string map = argv[1];
        while (run(map));
    } else {
        string map, seed;
        for (int i = 1; i < argc; i++) {
            string temp = argv[i];

            if ((temp == "-s") && (i != argc - 1)) {
                i++;
                seed = argv[i];
            } else {
                map = argv[i];
            }
        }

        if (map != "" && seed != "") while(run(map, stoi(seed)));
        else if (map != "") while(run(map));
        else if (seed != "") while(run("default.txt", stoi(seed)));
    }
}
