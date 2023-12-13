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

    void updateObject();
    virtual void update(){};
    virtual void onCollision(GameObject& other){};

    std::string getTag(){return tag;};
    void setTag(std::string tag){this->tag = tag;};

    SDL_Texture* getTexture();
    void setTexture(SDL_Renderer &renderer, const std::string& path);

    double getAngle() const;

    Vector2& getPosition();
    void setPosition(Vector2 &position);

    void resetPosition();

protected:
    std::string tag = "GameObject";
    Vector2 position;
    Vector2 oldPosition;
    Color color;
    double angle = 0;
    SDL_Texture* texture{};
};


#endif //CPROG_PROJECT_GAMEOBJECT_H
