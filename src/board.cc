#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
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
#include "objectGenerator.h"
#include "treasureGenerator.h"
#include "enemyGenerator.h"
#include "potionGenerator.h"

using namespace std;


// create object based on label
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


// detect and create chamber
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
        
        chambers.emplace_back(std::move(floorChambers));
    }

    return chambers;
}


// return random floor cell in a random chamber
vector<int> getSpawnPlace(vector<unique_ptr<Chamber>> &floorChamber, 
        vector<shared_ptr<Object>> &floorObject, int width) {
    
    while (true) {
        int randomChamber = rand() % floorChamber.size();
        vector<int> randomCell = floorChamber.at(randomChamber)->getRandomCell();

        if (floorObject.at(randomCell.at(1) * width + randomCell.at(0)) == nullptr) {
            return randomCell;
        }
    }
}

vector<vector<int>> availableOneRadiusBlock(vector<char> &floorMap, const vector<shared_ptr<Object>> floorObject, 
        vector<vector<int>> &blocks, int width) {
    
    vector<vector<int>> avaiBlocks;

    for (auto i : blocks) {
        int x = i.at(0);
        int y = i.at(1);

        if (floorMap.at(y * width + x) == '.' && floorObject.at(y * width + x) == nullptr) {
            avaiBlocks.emplace_back(vector<int> {x, y});
        } 
    }

    return avaiBlocks;
}


Board::Board(const std::string &map, shared_ptr<Object> hero): hero {hero} {
    int numObj = 0;
    string line;
    ifstream f {"layout/" + map};
    getline(f, line);
    
    // read map from file
    while (line.length() != 0) {
        vector<char> floorMap;
        vector<shared_ptr<Object>> floorObj;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (line.at(j) != '|' && line.at(j) != '-' && 
                        line.at(j) != '#' && line.at(j) != '+' && 
                        line.at(j) != '.' && line.at(j) != ' ') {
                    numObj++;
                    if (line.at(j) == '@') {
                        floorObj.emplace_back(hero);
                        heroPositions.emplace_back(vector<int> {j, i});
                    } else {
                        floorObj.emplace_back(makeObjFromLabel(line.at(j), j, i));
                    }
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

    // use algorithm to detect and create chambers
    chambers = createChambers(maps, height, width);

    // generate objects if input map is empty
    if (numObj == 0) {

        for (size_t i = 0; i < maps.size(); i++) {

            // hero spawn
            int heroChamber = rand() % chambers.at(i).size();
            vector<int> heroPosition = chambers.at(i).at(heroChamber)->getRandomCell();
            objects.at(i).at(heroPosition.at(1) * width + heroPosition.at(0)) = hero;
            heroPositions.emplace_back(heroPosition);

            // stair spawn
            int stairChamber = heroChamber;
            while (stairChamber == heroChamber) stairChamber = rand() % chambers.at(i).size();
            vector<int> stairPosition = chambers.at(i).at(stairChamber)->getRandomCell();
            objects.at(i).at(stairPosition.at(1) * width + stairPosition.at(0)) = 
                make_shared<Stair>(stairPosition.at(0), stairPosition.at(1));
            
            // potions spawn
            unique_ptr<ObjectGenerator> generator = make_unique<PotionGenerator>();
            for (int p = 0; p < numPotions; p++) {
                vector<int> pp = getSpawnPlace(chambers.at(i), objects.at(i), width);
                objects.at(i).at(pp.at(1) * width + pp.at(0)) = generator->createObject(pp.at(0), pp.at(1));
            }

            // gold spawn
            generator = make_unique<TreasureGenerator>();
            for (int t = 0; t < numGold; t++) {
                vector<int> gp = getSpawnPlace(chambers.at(i), objects.at(i), width);
                shared_ptr<Object> newObj = generator->createObject(gp.at(0), gp.at(1));
                objects.at(i).at(gp.at(1) * width + gp.at(0)) = newObj;

                // generate dragon for Dragon Hoard
                if (newObj->getName() == "Dragon Hoard") {
                    vector<vector<int>> oneRaidusBlocks = newObj->getOneBlockRadius();
                    vector<vector<int>> avaiBlocks = availableOneRadiusBlock(maps.at(i), objects.at(i), oneRaidusBlocks, width);

                    // The dragon will not be protected if there is no available blocks for the dragon
                    if (avaiBlocks.size() != 0) {
                        int random = rand() % avaiBlocks.size();
                        int x = avaiBlocks.at(random).at(0);
                        int y = avaiBlocks.at(random).at(1);

                        DragonHoard *dh = static_cast<DragonHoard *>(newObj.get());
                        objects.at(i).at(y * width + x) = make_shared<Dragon>(x, y, dh);
                        dh->setIsGuarded(true);
                    }
                }
            }

            // enemies spawn
            generator = make_unique<EnemyGenerator>();
            for (int e = 0; e < numEnemies; e++) {
                vector<int> ep = getSpawnPlace(chambers.at(i), objects.at(i), width);
                objects.at(i).at(ep.at(1) * width + ep.at(0)) = generator->createObject(ep.at(0), ep.at(1));
            }
        }
    }

    // set position for hero based on current floor
    hero->setX(heroPositions.at(currentFloor).at(0));
    hero->setY(heroPositions.at(currentFloor).at(1));
}

Board::~Board() {}

void Board::addTurn() { enemiesTurn++; }

vector<int> getNewPosition(Object* obj, const string &dir) {
    if (dir == "no") return vector<int> {obj->getX(), obj->getY() - 1};
    if (dir == "so") return vector<int> {obj->getX(), obj->getY() + 1};
    if (dir == "ea") return vector<int> {obj->getX() + 1, obj->getY()};
    if (dir == "we") return vector<int> {obj->getX() - 1, obj->getY()};
    if (dir == "ne") return vector<int> {obj->getX() + 1, obj->getY() - 1};
    if (dir == "nw") return vector<int> {obj->getX() - 1, obj->getY() - 1};
    if (dir == "se") return vector<int> {obj->getX() + 1, obj->getY() + 1};
    return vector<int> {obj->getX() - 1, obj->getY() + 1};
    
}

void Board::moveHero(const string &dir) {
    Race *heroPtr = static_cast<Race *>(hero.get());
    vector<int> newPosition = getNewPosition(hero.get(), dir);
    char c = maps.at(currentFloor).at(newPosition.at(0) + newPosition.at(1) * width);
    if (c == '.' || c == '#' || c == '+') {
        shared_ptr<Object> o = objects.at(currentFloor).at(newPosition.at(0) + newPosition.at(1) * width);

        if (o != nullptr) {
            if (o->getlabel() == '\\') {
                currentFloor++;
                heroPtr->setX(heroPositions.at(currentFloor).at(0));
                heroPtr->setY(heroPositions.at(currentFloor).at(1));
                heroPtr->resetEffect();
                return;

            } else if (o->getlabel() == 'G') {
                if (o->getName() == "Dragon Hoard") {
                    DragonHoard *dhPtr = static_cast<DragonHoard *>(o.get());
                    if (dhPtr->getIsGuarded()) {
                        return;
                    } else {
                        heroPtr->addScore(o->getValue());
                    }
                } else {
                    heroPtr->addScore(o->getValue());
                }

            } else if (o->getlabel() == 'P') {
                if (o->getName() == "Restore HP potion") {
                    heroPtr->addHpEffect(o->getValue());
                } else if (o->getName() == "Poison HP potion") {
                    heroPtr->addHpEffect(-o->getValue());
                } else if (o->getName() == "Boost Attack potion") {
                    heroPtr->addAtkEffect(o->getValue());
                } else if (o->getName() == "Wound Attack potion") {
                    heroPtr->addAtkEffect(-o->getValue());
                } else if (o->getName() == "Boost Defence potion") {
                    heroPtr->addDefEffect(o->getValue());
                } else if (o->getName() == "Wound Defence potion") {
                    heroPtr->addDefEffect(-o->getValue());
                }

            } else {
                Living *enemyPtr = static_cast<Living *>(o.get());
                heroPtr->attack(enemyPtr);

                if (enemyPtr->getHp() != 0) {
                    return;
                }
            }
        }

        objects.at(currentFloor).at(newPosition.at(0) + newPosition.at(1) * width) = hero;
        objects.at(currentFloor).at(hero->getX() + hero->getY() * width) = nullptr;
        heroPtr->setX(newPosition.at(0));
        heroPtr->setY(newPosition.at(1));
    }
}


int colorCode(const string &color) {
    if (color == "blue") return 36;
    if (color == "yellow") return 33;
    if (color == "green") return 32;
    else return 31;
}

void Board::display() {

    // for (size_t z = 0; z < maps.size(); z++) {
    //     for (int i = 0; i < height; i++) {
    //         for (int j = 0; j < width; j++) {
    //             if (objects.at(z).at(i * width + j) != nullptr) {
    //                 string color = objects.at(z).at(i * width + j)->getColor();
    //                 cout << "\033[" << colorCode(color) << "m" << 
    //                     objects.at(z).at(i * width + j)->getlabel() << "\033[m";
    //             } else {
    //                 cout << maps.at(z).at(i * width + j);
    //             }
    //         }
    //         cout << endl;
    //     }
    // }
    
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

    Race *heroPtr = static_cast<Race *>(hero.get());
    string firstLine = "Race: " + heroPtr->getName() + " | " + 
        "Gold: " + to_string(heroPtr->getValue());

    cout << firstLine;
    cout << setw(79 - firstLine.length()) << right << ("Floor " +  
        to_string(currentFloor + 1)) << endl;
    cout << "HP: " << heroPtr->getHp() << endl;
    cout << "Atk: " << heroPtr->getTotalAtk() << endl;
    cout << "Def: " << heroPtr->getTotalDef() << endl;
    cout << "Action: " << message << endl;
}
