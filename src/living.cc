#include "living.h"

Living::Living(char label, const std::string &name, const std::string &color,
    int value, int x, int y, int hp, int atk, int def): 
    Object {label, name, color, value, x, y}, 
    hp {hp}, atk {atk}, def {def} {}

Living::~Living() {}

int Living::getHp() { return hp; }

int Living::getAtk() { return atk; }

int Living::getDef() { return def; }

void Living::setHp(int h) { hp = h; }

void Living::setAtk(int a) { atk = a; }

void Living::setDef(int d) { def = d; }
