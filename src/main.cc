#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
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
        // cout << line << endl;
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

        if (cin.eof() || input == "q") return nullptr;

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

bool end(Race *hero, string status) {
    const int space = 44;
    string input;

    if (status == "win") {
        // display win message
        printFile("display/win.txt");
    } else if (status == "lose") {
        // display lose message
        printFile("display/lose.txt");  
    }

    while (input != "y") {
        cout << "Get stat? (y)" << endl;
        cin >> input;

        if (cin.eof() || input == "q") return 0;
    }

    cout << setw(space) << "\033[" + to_string(33) + "m" + "Score: " 
            << hero->getValue() << "\033[m" << endl;
    cout << setw(space) << "\033[" + to_string(36) + "m" + "Race: " 
            << hero->getName() << "\033[m" << endl;
    cout << setw(space) << "\033[" + to_string(31) + "m" + "HP: " 
            << hero->getHp() << "\033[m" << endl;
    cout << setw(space) << "\033[" + to_string(31) + "m" + "Atk: " 
            << hero->getTotalAtk() << "\033[m" << endl;
    cout << setw(space) << "\033[" + to_string(31) + "m" + "Def: " 
            << hero->getTotalDef() << "\033[m" << endl;
    cout << setw(space) << "\033[" + to_string(32) + "m" + "# Moves: " 
            << hero->getNumMove() << "\033[m" << endl;
    cout << setw(space) << "\033[" + to_string(32) + "m" + "# Kills: " 
            << hero->getNumEnemiesKilled() << "\033[m" << endl << endl << endl;

    input = "";
    while (input != "y" && input != "n") {
        cout << "Play again? (y/n)" << endl;
        cin >> input;

        if (cin.eof() || input == "q") return 0;
    }

    if (input == "y") {
        return 1;
    } else {
        return 0;
    }
}

// run the game
bool run(const string &map, const int seed = seedGenerator()) {

    // check if map name is valid
    ifstream testMap {"layout/" + map};
    if (! testMap.is_open()) {
        cout << "Cannot find map!" << endl;
        return 0;
    }

    srand(seed); // run seed
    string input, command;
    bool enemyTurn = true;

    // welcome message
    printFile("display/welcome.txt");

    while (input != "y") {
        cout << "Start? (y)" << endl;
        cin >> input;

        if (cin.eof() || input == "q") return 0;
    }

    // pick hero
    shared_ptr<Object> hero = pickHero();
    if (hero == nullptr) return 0;
    Race *heroPtr = static_cast<Race *>(hero.get());

    // generate map
    unique_ptr<Board> board = make_unique<Board>(map, hero);

    // game begin message
    printFile("display/begin.txt");

    // display initial board
    board->display();

    // run command from user
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

        // hero wins
        if (board->getCurFloor() == board->getNumFloor()) {
            return end(heroPtr, "win");
        }

        // run enemies turn
        if (enemyTurn) {
            // enemies turn
            board->moveEnemies();
            board->addTurn(); // keep track of enemies turn
        }

        // hero dies
        if (heroPtr->getHp() <= 0) {
            return end(heroPtr, "lose");
        }

        // display map
        board->display();
    }

    return 0;
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
