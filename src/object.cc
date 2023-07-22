#include <string>
#include <iostream>
#include "object.h"

using namespace std;

Object::Object(char label, const string &name, const string &color, 
    int value, int x, int y): label {label}, name {name}, color {color},
    value {value}, x {x}, y {y} {}

Object::~Object() {}

char Object::getlabel() { return label; }

string Object::getName() { return name; }

string Object::getColor() { return color; }

int Object::getValue() { return value; }

void Object::setX(int x) { this->x = x; }

void Object::setY(int y) { this->y = y; }
