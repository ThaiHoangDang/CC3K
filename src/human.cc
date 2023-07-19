#include <cstdlib>
#include "human.h"

Human::Human(int x, int y): Enemy {'H', "Human", 4, x, y, 140, 20, 20} {}

Human::~Human() {}
