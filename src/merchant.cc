#include <cstdlib>
#include "merchant.h"

Merchant::Merchant(int x, int y): Enemy {'M', "Merchant", 4, x, y, 30, 70, 5} {}

Merchant::~Merchant() {}
