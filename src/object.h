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

        bool inOneBlockRadius(const Object *other);
        char getlabel();
        std::string getName();
        std::string getColor();
        int getValue();
        int getX() const;
        void setX(int x);
        int getY() const;
        void setY(int y);

};

#endif
