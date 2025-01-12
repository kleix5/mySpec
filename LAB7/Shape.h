#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <cstring>
#include <iostream>
#include "IMoveable.h"

using std::cout;
using std::endl;


class Shape {
private:
    void copyRef(const Shape& s)
    {
        this->color = strcpy(new char[strlen(s.color)+1], s.color);
    }
protected:
    char* color;

public:
    constexpr static char* DEFAULT_COLOR = "black";

    char* getColor() const { return color; }

    Shape(const char* _color = DEFAULT_COLOR) {
        color = new char[strlen(_color)+1];
        strcpy(color, _color);
        cout << "Shape(char*)\n"; 
    }

    Shape(const Shape& s) {
        copyRef(s);
    }

    Shape& operator = (const Shape& s)
    {
        copyRef(s);
        return *this;
    }

    virtual void draw() const
    {
        cout << "Shape." << this->getColor() << endl;
    }

    virtual ~Shape() {
        cout << "~Shape()\n";
        delete []color;
        color = NULL; 
    }
};





#endif