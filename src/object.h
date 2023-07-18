#ifndef OBJECT_H
#define OBJECT_H

class Object {
    char label;
    // std::string name;

    public:
        Object(const char label);
        ~Object();
        char getlabel();
};

#endif
