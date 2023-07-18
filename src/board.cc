#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include "board.h"
#include "race.h"
#include "object.h"

using namespace std;


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
                        floorObj.emplace_back(make_shared<Object>(line.at(j)));
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

void Board::display() {

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (objects.at(currentFloor).at(i * width + j) != nullptr) {
                cout << objects.at(currentFloor).at(i * width + j)->getlabel();
            } else {
                cout << maps.at(currentFloor).at(i * width + j);
            }
        }
        cout << endl;
    }
}

