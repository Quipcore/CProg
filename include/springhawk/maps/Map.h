//
// Created by felix on 2023-11-16.
//

#ifndef CPROG_PROJECT_MAP_H
#define CPROG_PROJECT_MAP_H


#include "../Vector2.h"

class Map {

public:
    int operator[](Vector2 vector2);

    int getWidth();

    int getHeight();

    Map();

    ~Map();

private:
    int height;
    int width;
};


#endif //CPROG_PROJECT_MAP_H
