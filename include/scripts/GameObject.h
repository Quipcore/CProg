//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_GAMEOBJECT_H
#define CPROG_PROJECT_GAMEOBJECT_H

#include "springhawk/Color.h"
#include "springhawk/Vector2.h"

class GameObject {
public:
    GameObject() = default;
    ~GameObject() = default;

    virtual void update();
    virtual Color getColor();


    double getAngle() const;
    Vector2 getPosition() const;
    void setPosition(Vector2 position);
protected:
    Vector2 position;
    Color color;
    double angle = 0;


};


#endif //CPROG_PROJECT_GAMEOBJECT_H
