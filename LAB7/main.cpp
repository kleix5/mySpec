#include <iostream>
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Line.h"
#include "Scene.h"
#include "IMoveable.h"

using std::cout;
using std::endl;


int main(int argc, char** argv)
{
    cout << "We start with Shape. now:\n";
    Shape sh1;
    Shape& rsh1 = sh1;
    sh1.draw();
    cout << "\n\nThan we go for Point.:\n";    
    Point* p_p1 = new Point(15, 19, "green");
    // p1.moveBy(100, 100);
    // p1.draw();

    
    Point* p_p2 = new Point(120, 310, "yellow");
    // pp1->draw();
    // Shape* sp1 = pp1;
    // delete sp1;
    // cout << "\n\nThan we go for Circle.:\n";
    Circle*  p_cir = new Circle(10, 50, 250, "Pink");
    // c1.setR(100);
    // c1.setX(15);
    // c1.setY(99);
    // c1.draw();
    // c1.scale(5.45456);
    // c1.moveBy(1000, 5000);
    // c1.draw();
    
    // cout << "\n\nThan Line.:\n";    
    Line* p_line = new Line(4,6,12,48);
    // cout << std::get<0>(line1.getPoint(p)) << endl;
    // cout << line1 << endl;
    // cout << "AND NOW!!!\n";
    // line1.draw();
    // line1.setP1(2.3, 4.8);
    // line1.draw();
    // line1.moveBy(1000,333);
    // line1.draw();
    cout << "\n\nAnd now!!! The Scene. is wallking:\n";
    Scene* myObjects = new Scene;;

    myObjects->add(p_p1);
    myObjects->add(p_p2);
    myObjects->add(p_line);
    myObjects->add(p_cir);
    cout << myObjects->size() << endl;
    cout << "DRAW NEXT\ngetObj draw:\n";
    myObjects->getObj(1)->draw();
    cout << "JUST draw():\n"; 
    myObjects->draw(0);
    myObjects->moveBy(10000, 20000);
    myObjects->draw(0);


    delete myObjects;
    // delete p_p1;
    // delete p_p2;
    // delete p_line;
    return 0;
}