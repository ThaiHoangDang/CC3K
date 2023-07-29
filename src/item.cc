#include <string>
#include "item.h"

using namespace std;


Item::Item(char label, const string &name, const std::string &color, 
    int value, int x, int y): Object {label, name, color, value, x, y} {}


Item::~Item() {}
