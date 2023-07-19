#include <string>
#include "object.h"

Object::Object(char label, const std::string &name, const std::string &color, 
    int value, int x, int y): label {label}, name {name}, color {color},
    value {value}, x {x}, y {y} {}

Object::~Object() {}

char Object::getlabel() {
    return label;
}