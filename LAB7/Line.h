#ifndef _LINE_H_
#define _LINE_H_

#include "Shape.h"
#include <tuple>
#include <iostream>
#include "IMoveable.h"



class Line : public Shape, public IMoveable {
protected:
    struct Lboarders {
        int x;
        int y; 
    } lPoint1, lPoint2;
public:
    Line(int _x1=0, int _y1=0, int _x2=0, int _y2=0) : 
    lPoint1{_x1, _y1}, lPoint2{_x2, _y2} {
        cout << "Line(4*int)\n";
    }

    ~Line() {
        cout << "~Line()\n";
    }

    std::tuple<int, int> getPoint(int p) const 
    //This function returns the coordinates of lines point(1-st or 2-nd)
    {   
        std::tuple<int, int> answer;
        switch (p)
        {
        case 1:
            answer = std::make_tuple(this->lPoint1.x, this->lPoint1.y);
            break;
        case 2:
            answer = std::make_tuple(this->lPoint2.x, this->lPoint2.y);
            break;
        default:
            break;
        }
        return answer; 
    }

    
    void draw() const override
    {
        // this->Shape::draw();
        cout << "First point" << "(" << std::get<0>(this->getPoint(1)) << ", " 
                                << std::get<1>(this->getPoint(1)) << "), "
             << "Second point" << "(" << std::get<0>(this->getPoint(2)) << ", " 
                                << std::get<1>(this->getPoint(2)) << ")" << endl;
    }
 

    

    void setP1(int _x, int _y) { lPoint1.x=_x, lPoint1.y=_y; }
    void setP2(int _x, int _y) { lPoint2.x=_x, lPoint2.y=_y; }

   
    // void scale(double factor)
    // {
    //     r *= factor;
    // }
    
    void moveBy(int dx, int dy) override
    {
        this->lPoint1.x += dx;
        this->lPoint2.x += dx;
        this->lPoint1.y += dy;
        this->lPoint2.y += dy;
    }   

};


std::ostream& operator <<(std::ostream& s, const Line& line)
{
    s << "First point" << "(" << std::get<0>(line.getPoint(1)) << ", " 
                                << std::get<1>(line.getPoint(1)) << "), "
      << "Second point" << "(" << std::get<0>(line.getPoint(2)) << ", " 
                                << std::get<1>(line.getPoint(2)) << ")" << endl;
    return s;
}






#endif