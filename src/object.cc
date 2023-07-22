#include <string>
#include <iostream>
#include "object.h"

using namespace std;

Object::Object(char label, const string &name, const string &color, 
    int value, int x, int y): label {label}, name {name}, color {color},
    value {value}, x {x}, y {y} {}

Object::~Object() {}

bool Object::inOneBlockRadius(const Object *other) {
    if (other == nullptr) return false;
    return ((other->getX() >= x - 1) && (other->getX() <= x + 1) && 
        (other->getY() >= y - 1) && (other->getY() <= y + 1));
}

char Object::getlabel() { return label; }

string Object::getName() { return name; }

string Object::getColor() { return color; }

int Object::getValue() { return value; }

int Object::getX() const { return x; }

void Object::setX(int x) { this->x = x; }

int Object::getY() const { return y; }

void Object::setY(int y) { this->y = y; }
