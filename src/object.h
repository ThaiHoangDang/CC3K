#ifndef OBJECT_H
#define OBJECT_H

class Object {
    char label;
    std::string name;
    std::string color;
    int value;
    int x;
    int y;

    public:
        Object(char label, const std::string &name, 
            const std::string &color, int value, int x, int y);
        ~Object();
        char getlabel();
};

#endif
