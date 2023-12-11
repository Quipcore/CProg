//
// Created by felix on 2023-11-11.
//

#ifndef CPROG_PROJECT_GAMEOBJECT_H
#define CPROG_PROJECT_GAMEOBJECT_H

#include "springhawk/Color.h"
#include "springhawk/Vector2.h"
#include "SDL2/SDL.h"

class GameObject {
public:
    GameObject() = default;
    ~GameObject() = default;

    virtual void update() = 0;
    virtual Color getColor() = 0;

    double getAngle() const;
    Vector2& getPosition();
    void setPosition(Vector2 &position);

    void setTexture(SDL_Renderer &renderer, std::string path);

    SDL_Texture* getTexture();

protected:
    Vector2 position;
    Color color;
    double angle = 0;
    SDL_Texture* texture;

};


#endif //CPROG_PROJECT_GAMEOBJECT_H
