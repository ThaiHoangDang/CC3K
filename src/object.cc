#include <string>
#include "object.h"

Object::Object(const char label): label {label} {}

Object::~Object() {

}

char Object::getlabel() {
    return label;
}