//
// Created by felix on 2023-11-16.
//

#ifndef CPROG_PROJECT_MAP_H
#define CPROG_PROJECT_MAP_H


#include <map>
#include "springhawk/Vector2.h"
#include "SDL2/SDL.h"
#include "vector"
#include "springhawk/TextureTag.h"

class Map {

public:
    virtual ~Map() = default;

    virtual bool isOutOfBounds(Vector2 &position) = 0;
    virtual Vector2 getValidPos() = 0;

    virtual int operator[](Vector2 vector2) = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;

    //SHOULD ONLY BE USED BY RENDERER!
    virtual SDL_Texture *getTextureAt(Vector2 position) = 0;

    //SHOULD ONLY BE USED BY ENGINE!
    virtual void loadTextures(SDL_Renderer&) = 0;

    virtual void setValueAt(Vector2, char) = 0;
};


#endif //CPROG_PROJECT_MAP_H
