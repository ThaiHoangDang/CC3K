#include <string>
#include <iostream>
#include <vector>
#include "object.h"

using namespace std;

Object::Object(char label, const string &name, const string &color, 
    int value, int x, int y): label {label}, name {name}, color {color},
    x {x}, y {y}, value {value} {}

Object::~Object() {}

bool Object::inOneBlockRadius(const Object *other) {
    if (other == nullptr) return false;
    return ((other->getX() >= x - 1) && (other->getX() <= x + 1) && 
        (other->getY() >= y - 1) && (other->getY() <= y + 1));
}

vector<vector<int>> Object::getOneBlockRadius() {
    vector<vector<int>> oneBlockCells;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) continue;
            else {
                oneBlockCells.emplace_back(vector<int> {i, j});
            }
        }
    }

    return oneBlockCells;
}

char Object::getlabel() { return label; }

string Object::getName() { return name; }

string Object::getColor() { return color; }

int Object::getValue() { return value; }

void Object::setValue(int x) { value = x; } 

int Object::getX() const { return x; }

void Object::setX(int x) { this->x = x; }

int Object::getY() const { return y; }

void Object::setY(int y) { this->y = y; }
