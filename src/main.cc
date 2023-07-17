#include <string>
#include "gameFlow.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc == 1) {
        GameFlow gf;
        gf.run();
    } else {
        string arg {argv[1]};
        GameFlow gf {arg};
        gf.run();
    }
}
