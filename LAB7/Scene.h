#ifndef _SCENEH_
#define _SCENE_H_

#include "Shape.h"
#include <vector>
#include <iostream>
#include "IMoveable.h"

using std::cout;
using std::endl;

// const int MAX_SCENE_SIZE = 100;

class Scene {
private:   
    std::vector<Shape*> objects; // Declared with size 10, but can be declared without size!
public:
    Scene() {
    };

    virtual ~Scene() {  
        for (Shape* shape : objects) {  
            delete shape; // Delete each Shape* to free memory  
        }  
    // No need to delete objects as it's a std::vector  
    } 

    void add(Shape* obj)//, int place)
    {
        // objects.insert(place, obj); // If need to insert to current position!
        this->objects.push_back(obj);
    }

    Shape* getObj(int place)
    {
        cout << "getObject RUN!!!\n";
        return this->objects.at(place);
    }

    void draw(int place)
    {
        cout << "\n************Sceane drawing**************\n";
        if (place == 0)
        {
            for (int i=0; i<objects.size(); ++i)
                objects[i]->draw();
        }
        else
        {
            this->getObj(place)->draw();
        }
        cout << "\n************end drawing**************\n";
        
    }

    int size() const
    {
        return this->objects.size();
    }

    void moveBy(int dx, int dy)
    {
        for(int i=0; i < objects.size(); i++) {
            IMoveable* mb = dynamic_cast<IMoveable*>(objects[i]);
            if (mb != NULL)
                mb->moveBy(dx, dy);
        }

    }


};











#endif