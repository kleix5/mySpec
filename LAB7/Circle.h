#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Shape.h"
#include "IMoveable.h"
#include "Coords.h"

class Circle : public Shape, public IMoveable, protected Coords {
protected:
    int x, y;
    double r;
public:
    Circle(int _x=0, int _y=0, int _r=1, const char* _color = DEFAULT_COLOR) 
    : Shape(_color), Coords(_x, _y) {
        cout << "Circle(int, int, int)\n";
    }

    ~Circle() {
        cout << "~Circle()\n";
    }

    int getX() const { return x; }
    int getY() const { return y; }

    void setX(int _x) { x=_x; }
    void setY(int _y) { y=_y; }

    int getR() const { return r; }
    void setR(int _r) { r=_r; } 

    void draw() const override
    {
        this->Shape::draw();
        cout << "Circle.(" << getX() << ", " << getY() << ") "
            << "Radius: " << getR();
    }

    void scale(int factor)
    {
        r *= factor;
    }
    void moveBy(int dx, int dy) override
    {
        x += dx;
        y += dy;
    }   

};






#endif