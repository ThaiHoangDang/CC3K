#include <string>
#include "object.h"

using namespace std;

Object::Object(char label, const string &name, const string &color, 
    int value, int x, int y): label {label}, name {name}, color {color},
    value {value}, x {x}, y {y} {}

Object::~Object() {}

char Object::getlabel() {
    return label;
}

string Object::getColor() {
    return color;
}
