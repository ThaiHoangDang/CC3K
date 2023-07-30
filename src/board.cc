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


// detect and create chambers
vector<vector<unique_ptr<Extender>>> createExtender
        (char c, const vector<vector<char>> &maps, int height, int width) {
    
    vector<vector<unique_ptr<Extender>>> extenders;

    // loop through each floor
    for (const auto &it : maps) {

        vector<unique_ptr<Extender>> floorExtenders;

        // create new chamber if there is no chamber contain a particular cell
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (it.at(i * width + j) == c) {
                    if (floorExtenders.size() == 0) {
                        floorExtenders.emplace_back(make_unique<Extender>
                                (c, j, i, it, width));
                    } else {
                        bool isIn = false;
                        for (auto &it : floorExtenders) {
                            if (it->isIn(j, i)) {
                                isIn = true;
                            }
                        }

                        if (! isIn) {
                            floorExtenders.emplace_back(make_unique<Extender>
                                    (c, j, i, it, width));
                        }
                    }
                }
            }
        }
        
        extenders.emplace_back(std::move(floorExtenders));
    }

    return extenders;
}


// return an available random floor cell in a random chamber
vector<int> getSpawnPlace(vector<unique_ptr<Extender>> &floorChamber, 
        vector<shared_ptr<Object>> &floorObject, int width) {
    
    while (true) {
        int randomChamber = rand() % floorChamber.size();
        vector<int> randomCell = floorChamber.at(randomChamber)->getRandomCell();

        // check if cell is empty
        if (floorObject.at(randomCell.at(1) * width + randomCell.at(0)) == nullptr) {
            return randomCell;
        }
    }
}


// return a vector of available blocks to move to
vector<vector<int>> availableOneRadiusBlock(vector<char> &floorMap, 
        const vector<shared_ptr<Object>> &floorObject, 
        vector<vector<int>> &blocks, int width) {
    
    vector<vector<int>> avaiBlocks;

    for (auto i : blocks) {
        int x = i.at(0);
        int y = i.at(1);

        // check if cell is available
        if (floorMap.at(y * width + x) == '.' && floorObject.at(y * width + x) == nullptr) {
            avaiBlocks.emplace_back(vector<int> {x, y});
        } 
    }

    return avaiBlocks;
}


// return the first valid combination of Dragon and Dragon Hoard
vector<vector<Object *>> DragonAndHoardCombine(vector<Object *> &dragons, vector<Object *> &dragonHoards) {
    std::vector<std::vector<Object *>> combination;
    
    for (size_t i = 0; i < dragons.size(); ++i) {
        for (size_t j = 0; j < dragonHoards.size(); ++j) {
            bool valid_combination = true;
            combination.clear();

            for (size_t k = 0; k < dragons.size(); ++k) {
                Object *a = dragons[(i + k) % dragons.size()];
                Object *b = dragonHoards[(j + k) % dragonHoards.size()];

                // check if dragon and dragon hoard are in one block radius
                if (! b->inOneBlockRadius(a)) {
                    valid_combination = false;
                    break;
                }
                std::vector<Object *> pair = {a, b};    
                combination.push_back(pair);
            }

            // return as soon as there is a valid combination
            if (valid_combination) {
                return combination;
            }
        }                                           
    }

    return combination;
}


// link Dragon and Dragon Hoard together
void linkDragonAndHoard(vector<vector<shared_ptr<Object>>> &objects) {

    for (auto floor : objects) {
        vector<Object *> dragons;
        vector<Object *> dragonHoards;
        
        // create 2 vectors of Dragon and Dragon Hoard
        for (auto obj : floor) {
            if (obj != nullptr && obj->getName() == "Dragon") {
                dragons.push_back(obj.get());
            } else if (obj != nullptr && obj->getName() == "Dragon Hoard") {
                dragonHoards.push_back(obj.get());
            }
        }

        // get first valid combination
        vector<vector<Object *>> combination = DragonAndHoardCombine(dragons, dragonHoards);

        // link Dragon and Dragon Hoard in a pair together
        for (auto pair : combination) {
            Dragon *dragonPtr = static_cast<Dragon *>(pair.at(0));
            DragonHoard *dragonHoardPtr = static_cast<DragonHoard *>(pair.at(1));

            dragonPtr->setGuard(dragonHoardPtr);
            dragonHoardPtr->setIsGuarded(true);
        }

    }
}


Board::Board(const std::string &map, shared_ptr<Object> hero): hero {hero} {
    int numObj = 0;
    string line;
    ifstream f {"layout/" + map};
    getline(f, line);
    
    // read map from file
    while (line.length() != 0) {
        vector<char> floorMap; // floor layout
        vector<shared_ptr<Object>> floorObj; // objects layout

        // create Objects at corresponding position
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
    chambers = createExtender('.', maps, height, width);

    // use algorithm to detect and create chambers
    passages = createExtender('#', maps, height, width);

    // link dragons and dragon hoards together
    linkDragonAndHoard(objects);


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

                // generate Dragon for Dragon Hoard
                if (newObj->getName() == "Dragon Hoard") {
                    vector<vector<int>> oneRaidusBlocks = newObj->getOneBlockRadius();
                    vector<vector<int>> avaiBlocks = availableOneRadiusBlock(maps.at(i), objects.at(i), oneRaidusBlocks, width);

                    // edge case: Dragon hoard will not be protected if there is no available blocks for the dragon
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

// set all static fields to correct state
Board::~Board() {
    unique_ptr<Merchant> merchant = make_unique<Merchant>(0, 0);
    merchant->setIsHostile(false);

    unique_ptr<Potion> potion = make_unique<RestoreHp> (0, 0);
    potion->setUnknown(true); 
    potion = make_unique<BoostAtk> (0, 0);
    potion->setUnknown(true); 
    potion = make_unique<BoostDef> (0, 0);
    potion->setUnknown(true); 
    potion = make_unique<PoisonHp> (0, 0);
    potion->setUnknown(true); 
    potion = make_unique<WoundAtk> (0, 0);
    potion->setUnknown(true); 
    potion = make_unique<WoundDef> (0, 0);
    potion->setUnknown(true); 
}


void Board::addTurn() { enemiesTurn++; }


void Board::resetTurn() { enemiesTurn = 0; }


int Board::getCurFloor() {
    return currentFloor;
}


int Board::getNumFloor() {
    return maps.size();
}


// return the position based on direction to obj
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


// hero turn
void Board::moveHero(const string &dir) {
    Race *heroPtr = static_cast<Race *>(hero.get());
    vector<int> newPosition = getNewPosition(hero.get(), dir);
    char c = maps.at(currentFloor).at(newPosition.at(0) + newPosition.at(1) * width);
    
    // update number of movement of player
    heroPtr->addNumMove();

    // check if it is a valid move
    if (c == '.' || c == '#' || c == '+') {
        shared_ptr<Object> o = objects.at(currentFloor).at(newPosition.at(0) + 
                newPosition.at(1) * width);

        if (o != nullptr) {
            if (o->getlabel() == '\\') {  // player goes to stair
                currentFloor++;
                if (currentFloor != maps.size()) {
                    heroPtr->setX(heroPositions.at(currentFloor).at(0));
                    heroPtr->setY(heroPositions.at(currentFloor).at(1));
                    heroPtr->resetEffect();
                    resetTurn();
                    message += "Player gets to floor " + to_string(currentFloor + 1) + ". ";
                }
                return;

            } else if (o->getlabel() == 'G') { // player pick up gold
                if (o->getName() == "Dragon Hoard") {
                    DragonHoard *dhPtr = static_cast<DragonHoard *>(o.get());
                    if (dhPtr->getIsGuarded()) {  // cannot pick up if Dragon Hoard is guarded
                        message += "Dragon Hoard is guarded. ";
                        return;
                    }
                }
                heroPtr->addScore(o->getValue());
                message += "Player picks up " + o->getName() + " (" + to_string(o->getValue()) + " value). ";

            } else if (o->getlabel() == 'P') {  // player uses potion

                // set Unknown status and apply potion effect to hero
                if (RestoreHp *p = dynamic_cast<RestoreHp *>(o.get()); p != nullptr) {
                    p->setUnknown(false);
                    heroPtr->addHpEffect(p->getValue());
                } else if (BoostAtk *p = dynamic_cast<BoostAtk *>(o.get()); p != nullptr) {
                    p->setUnknown(false);
                    heroPtr->addAtkEffect(o->getValue());
                } else if (BoostDef *p = dynamic_cast<BoostDef *>(o.get()); p != nullptr) {
                    p->setUnknown(false);
                    heroPtr->addDefEffect(o->getValue());
                } else if (PoisonHp *p = dynamic_cast<PoisonHp *>(o.get()); p != nullptr) {
                    p->setUnknown(false);
                    heroPtr->addHpEffect(-p->getValue());
                } else if (WoundAtk *p = dynamic_cast<WoundAtk *>(o.get()); p != nullptr) {
                    p->setUnknown(false);
                    heroPtr->addAtkEffect(-o->getValue());
                } else if (WoundDef *p = dynamic_cast<WoundDef *>(o.get()); p != nullptr) {
                    p->setUnknown(false);
                    heroPtr->addDefEffect(-o->getValue());
                }

                message += "Player uses " + o->getName() + ". ";

            } else {  // player attacks enemies
                Living *enemyPtr = static_cast<Living *>(o.get());
                int damage = heroPtr->attack(enemyPtr);

                if (enemyPtr->getHp() != 0) {  // enemy not die
                    if (damage == 0) {
                        message += "Player misses the attack! ";
                    } else {
                        message += "Player deals " + to_string(damage) + " damage to " + 
                            enemyPtr->getName() + " (" + to_string(enemyPtr->getHp()) + " HP). ";
                    }
                    return;

                } else {  // enemy dies
                    message += "Player kills " + enemyPtr->getName() + " and gets " + 
                        to_string((hero->getName() != "Goblin") ? enemyPtr->getValue() : 
                        enemyPtr->getValue() + 5) + " gold. ";
                }
            }
        }

        // set new position for hero
        objects.at(currentFloor).at(newPosition.at(0) + newPosition.at(1) * width) = hero;
        objects.at(currentFloor).at(hero->getX() + hero->getY() * width) = nullptr;
        heroPtr->setX(newPosition.at(0));
        heroPtr->setY(newPosition.at(1));

        // display potions that are in one block radius
        for (auto obj : objects.at(currentFloor)) {
            if (obj != nullptr && obj->getlabel() == 'P' && hero->inOneBlockRadius(obj.get())) {
                message += obj->getName() + " at " + hero->getDirectionTo(obj.get()) + ". ";
            }
        }
    }
}


// enemies turn
void Board::moveEnemies() {

    // move enemies in line by line fashion
    for (auto i : objects.at(currentFloor)) {
        Object *objPtr = i.get();
        Enemy *enemyPtr = dynamic_cast<Enemy *>(objPtr);

        // run if it is an Enemy and with a valid turn
        if (enemyPtr != nullptr && enemyPtr->getTurn() == enemiesTurn) {
            
            // attack hero if in one block radius
            if (enemyPtr->inOneBlockRadius(hero.get())) {
                Living *l = static_cast<Living *>(hero.get());
                int numAttacks = (enemyPtr->getName() == "Elf" && hero->getName() != "Drow") ? 2 : 1;

                for (int i = 0; i < numAttacks; i++) {
                    int damage = enemyPtr->attack(l);
                    if (damage != 0) {
                        message += enemyPtr->getName() + " deals " + to_string(damage) + " damage to PC. ";
                    }
                }

            // perform enemy movement if not dragon
            } else if (enemyPtr->getName() != "Dragon") {
                vector<vector<int>> oneRaidusBlocks = enemyPtr->getOneBlockRadius();
                vector<vector<int>> avaiBlocks = availableOneRadiusBlock
                    (maps.at(currentFloor), objects.at(currentFloor), oneRaidusBlocks, width);

                // edge case: enemy will not move if no available blocks
                if (avaiBlocks.size() != 0) {
                    int random = rand() % avaiBlocks.size();
                    int x = avaiBlocks.at(random).at(0);
                    int y = avaiBlocks.at(random).at(1);

                    objects.at(currentFloor).at(x + y * width) = i;
                    objects.at(currentFloor).at(enemyPtr->getX() + enemyPtr->getY() * width) = nullptr;
                    enemyPtr->setX(x);
                    enemyPtr->setY(y);
                }
            }

            // update turn
            enemyPtr->addOneTurn();
        }
    }
}


// return color code based on colors
int colorCode(const string &color) {
    if (color == "blue") return 36;
    if (color == "yellow") return 33;
    if (color == "green") return 32;
    else return 31;
}



// display board
void Board::display() {

    // update explored status of chamber
    for (auto &it : chambers.at(currentFloor)) {
        if ((it->isIn(hero->getX(), hero->getY())) || 
            (it->inOneBlockRadius(hero->getX(), hero->getY()))) it->setIsExplored(true);
    }

    // update explored status of passage
    for (auto &it : passages.at(currentFloor)) {
        if ((it->isIn(hero->getX(), hero->getY())) || 
            (it->inOneBlockRadius(hero->getX(), hero->getY()))) it->setIsExplored(true);
    }
    
    // print row by row and col by col within each row
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            bool inChambersOrPassage = false;

            for (auto &it : chambers.at(currentFloor)) {

                if (it->isIn(j, i) || it->inOneBlockRadius(j, i)) {
                    inChambersOrPassage = true;

                    if (it->getIsExplored()) {
                        if (objects.at(currentFloor).at(i * width + j) != nullptr) {
                            string color = objects.at(currentFloor).at(i * width + j)->getColor();
                            cout << "\033[" << colorCode(color) << "m" << 
                                objects.at(currentFloor).at(i * width + j)->getlabel() << "\033[m";
                        } else {
                            cout << maps.at(currentFloor).at(i * width + j);
                        }
                    } else {
                        if (maps.at(currentFloor).at(i * width + j) == '+') {
                            inChambersOrPassage = false;
                            break;
                        }
                        cout << " ";
                    }
                    break;
                }
            }

            
            if (inChambersOrPassage == false) {
                for (auto &it : passages.at(currentFloor)) {
                    if (it->isIn(j, i) || it->inOneBlockRadius(j, i)) {
                        inChambersOrPassage = true;

                        if (it->getIsExplored()) {
                            if (objects.at(currentFloor).at(i * width + j) != nullptr) {
                                string color = objects.at(currentFloor).at(i * width + j)->getColor();
                                cout << "\033[" << colorCode(color) << "m" << 
                                    objects.at(currentFloor).at(i * width + j)->getlabel() << "\033[m";
                            } else {
                                cout << maps.at(currentFloor).at(i * width + j);
                            }
                        } else {
                            cout << " ";
                        }
                        break;
                    }
                }
            }

            if (! inChambersOrPassage) {
                if (objects.at(currentFloor).at(i * width + j) != nullptr) {
                    string color = objects.at(currentFloor).at(i * width + j)->getColor();
                    cout << "\033[" << colorCode(color) << "m" << 
                        objects.at(currentFloor).at(i * width + j)->getlabel() << "\033[m";
                } else {
                    cout << maps.at(currentFloor).at(i * width + j);
                }
            }

        }
        cout << endl;
    }
    
    // print information board
    Race *heroPtr = static_cast<Race *>(hero.get());
    int score = (heroPtr->getName() == "Shade") ? heroPtr->getValue() / 2 : heroPtr->getValue();
    string firstLine = "Race: " + heroPtr->getName() + " | " + 
        "Gold: " + to_string(score);

    cout << firstLine;
    cout << setw(79 - firstLine.length()) << right << ("Floor " +  
        to_string(currentFloor + 1)) << endl;
    cout << "HP: " << heroPtr->getHp() << endl;
    cout << "Atk: " << heroPtr->getTotalAtk() << endl;
    cout << "Def: " << heroPtr->getTotalDef() << endl;
    cout << "Action: " << message << endl;

    message.clear();
}
