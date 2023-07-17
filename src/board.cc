#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include "board.h"
#include "character.h"
#include "object.h"

using namespace std;

Board::Board(const std::string &map, Character &hero): hero {hero} {
    string line;
    ifstream f {"layout/" + map};
    getline(f, line);

    while (line.length() != 0) {
        vector<char> floorMap;
        vector<unique_ptr<Object>> floorObj;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (line.at(j) != '|' && line.at(j) != '-' && 
                        line.at(j) != '#' && line.at(j) != '+' && 
                        line.at(j) != '.' && line.at(j) != ' ') {
                    floorObj.emplace_back(make_unique<Object>(line.at(j)));
                    // different for hero
                    floorMap.emplace_back('.');
                } else {
                    floorObj.emplace_back(nullptr);
                    floorMap.emplace_back(line.at(j));
                }
            }
            line.clear();
            getline(f, line);
        }
        objects.emplace_back(std::move(floorObj));
        maps.emplace_back(floorMap);
    }
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