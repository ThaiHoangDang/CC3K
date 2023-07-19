#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include "board.h"
#include "race.h"
#include "object.h"
#include "restoreHp.h"
#include "boostAtk.h"
#include "boostDef.h"
#include "poisonHp.h"
#include "woundAtk.h"
#include "woundDef.h"
#include "normalGold.h"
#include "smallGold.h"
#include "dragonHoard.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include "stair.h"

using namespace std;


shared_ptr<Object> makeObjFromLabel(char c, int x, int y) {
    if (c == '0') return make_shared<RestoreHp>(x, y);
    if (c == '1') return make_shared<BoostAtk>(x, y);
    if (c == '2') return make_shared<BoostDef>(x, y);
    if (c == '3') return make_shared<PoisonHp>(x, y);
    if (c == '4') return make_shared<WoundAtk>(x, y);
    if (c == '5') return make_shared<WoundDef>(x, y);
    if (c == '6') return make_shared<NormalGold>(x, y);
    if (c == '7') return make_shared<SmallGold>(x, y);
    // if (c == '8') return make_shared<>();
    if (c == '9') return make_shared<DragonHoard>(x, y);
    if (c == 'H') return make_shared<Human>(x, y);
    if (c == 'W') return make_shared<Dwarf>(x, y);
    if (c == 'E') return make_shared<Elf>(x, y);
    if (c == 'O') return make_shared<Orcs>(x, y);
    if (c == 'M') return make_shared<Merchant>(x, y);
    if (c == 'D') return make_shared<Dragon>(x, y);
    if (c == 'L') return make_shared<Halfling>(x, y);
    if (c == '\\') return make_shared<Stair>(x, y);
    return nullptr;
}


vector<vector<unique_ptr<Chamber>>> createChambers
        (const vector<vector<char>> &maps, int height, int width) {

    vector<vector<unique_ptr<Chamber>>> chambers;

    for (const auto &it : maps) {
        vector<unique_ptr<Chamber>> floorChambers;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (it.at(i * width + j) == '.') {
                    if (floorChambers.size() == 0) {
                        floorChambers.emplace_back(make_unique<Chamber>
                                (j, i, it, height, width));
                    } else {
                        bool is_in = false;
                        for (auto &it : floorChambers) {
                            if (it->is_in(j, i)) {
                                is_in = true;
                            }
                        }

                        if (! is_in) {
                            floorChambers.emplace_back(make_unique<Chamber>
                                    (j, i, it, height, width));
                        }
                    }
                }
            }
        }
        
        // test number of chambers
        // cout << "Number of chambers: " << floorChambers.size() << endl;
        
        chambers.emplace_back(std::move(floorChambers));
    }

    return chambers;
}

Board::Board(const std::string &map, shared_ptr<Object> hero): hero {hero} {
    string line;
    ifstream f {"layout/" + map};
    getline(f, line);
    
    while (line.length() != 0) {
        vector<char> floorMap;
        vector<shared_ptr<Object>> floorObj;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (line.at(j) != '|' && line.at(j) != '-' && 
                        line.at(j) != '#' && line.at(j) != '+' && 
                        line.at(j) != '.' && line.at(j) != ' ') {
                    if (line.at(j) == '@') {
                        floorObj.emplace_back(hero);
                    } else {
                        floorObj.emplace_back(makeObjFromLabel(line.at(j), j, i));
                    }
                    // randome algorithm
                    floorMap.emplace_back('.');
                } else {
                    floorObj.emplace_back(nullptr);
                    floorMap.emplace_back(line.at(j));
                }
            }
            line.clear();
            getline(f, line);
        }
        objects.emplace_back(floorObj);
        maps.emplace_back(floorMap);
    }

    chambers = createChambers(maps, height, width);
    
}

Board::~Board() {

}

int colorCode(const string &color) {
    if (color == "blue") return 36;
    if (color == "yellow") return 33;
    if (color == "green") return 32;
    else return 31;
}

void Board::display() {

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (objects.at(currentFloor).at(i * width + j) != nullptr) {
                string color = objects.at(currentFloor).at(i * width + j)->getColor();
                cout << "\033[" << colorCode(color) << "m" << 
                    objects.at(currentFloor).at(i * width + j)->getlabel() << "\033[m";
            } else {
                cout << maps.at(currentFloor).at(i * width + j);
            }
        }
        cout << endl;
    }
}
