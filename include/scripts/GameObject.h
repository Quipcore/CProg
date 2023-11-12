//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_GAMEOBJECT_H
#define CPROG_PROJECT_GAMEOBJECT_H

#include "springhawk/Color.h"
#include "springhawk/Vector2.h"

enum Tag{
    Player,
    Enemy,
    Bullet,
    Object
};

class GameObject {
public:
    GameObject() = default;
    ~GameObject() = default;

    virtual void update();
    virtual Color getColor();
    virtual Tag getTag();


    float getAngle() const;
    Vector2 getPosition() const;

protected:
    const Tag tag = Tag::Object;
    Vector2 position;
    float angle = 0;
    Color color;
};


#endif //CPROG_PROJECT_GAMEOBJECT_H
