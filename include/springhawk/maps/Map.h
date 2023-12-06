//
// Created by felix on 2023-11-16.
//

#ifndef CPROG_PROJECT_MAP_H
#define CPROG_PROJECT_MAP_H


#include "springhawk/Vector2.h"

class Map {

public:
    virtual ~Map() = default;
    virtual int operator[](Vector2 vector2) = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual bool isOutOfBounds(Vector2 &position) = 0;
    virtual Vector2 getValidPos() = 0;
};


#endif //CPROG_PROJECT_MAP_H
