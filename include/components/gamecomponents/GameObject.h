#ifndef CPROG_PROJECT_GAMEOBJECT_H
#define CPROG_PROJECT_GAMEOBJECT_H

#include "springhawk/Color.h"
#include "springhawk/Vector2.h"
#include "SDL2/SDL.h"

class GameObject {
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    void updateObject();
    virtual void update(){};
    virtual void onCollision(GameObject& other){};

    std::string getTag(){return tag;};
    void setTag(std::string tag){this->tag = tag;};

    SDL_Texture* getTexture();
    void setTexture(SDL_Texture *texture);
    void setTexture(SDL_Renderer &renderer, const std::string& path);

    double getAngle() const;

    Vector2& getPosition();
    void setPosition(Vector2 &position);

    void resetPosition();
    std::string getTexturePath() const{ return texturePath; };

    bool intersects(GameObject& other);

    bool isTrigger() const;

protected:
    std::string tag = "GameObject";
    std::string texturePath = "";
    Vector2 position {0,0};
    Vector2 oldPosition = position;
    Color color = {255,255,255,255};
    double angle = 0;
    bool objectIsTrigger = false;
private:
    SDL_Texture* texture{};
};


#endif //CPROG_PROJECT_GAMEOBJECT_H
