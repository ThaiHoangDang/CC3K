#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>

class Object {
    char label;
    std::string name;
    std::string color;
    int x;
    int y;

    protected:
        int value;

    public:
        Object(char label, const std::string &name, 
            const std::string &color, int value, int x, int y);
        ~Object();

        bool inOneBlockRadius(const Object *other);
        std::vector<std::vector<int>> getOneBlockRadius();
        char getlabel();
        std::string getName();
        std::string getColor();
        virtual int getValue();
        void setValue(int x);
        int getX() const;
        void setX(int x);
        int getY() const;
        void setY(int y);

};

#endif
