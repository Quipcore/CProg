#include "components/Gamecomponents/GameObject.h"
#include "iostream"
#include "Constants.h"
#include "springhawk/Engine.h"
#include <SDL2/SDL_image.h>

void GameObject::updateObject(){
    oldPosition = position;
    update();
};

//----------------------------------------------------------------------------------------------------------------------

Vector2& GameObject::getPosition(){
    return position;
}

//----------------------------------------------------------------------------------------------------------------------

double GameObject::getAngle() const{
    return angle;
}

//----------------------------------------------------------------------------------------------------------------------

void GameObject::setPosition(Vector2 &position) {
    this->position = position;
}

void GameObject::setTexture(SDL_Renderer &renderer, const std::string& path){

//    springhawk::Engine::swapTexture(texture, path);

    std::string pathToImage = constants::imagePath + path;

    SDL_Surface *surface = IMG_Load(pathToImage.c_str());
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(&renderer, surface);
    SDL_FreeSurface(surface);
    this->texture = pTexture;
}

void GameObject::setTexture(SDL_Texture* texture){
    this->texture = texture;
}

SDL_Texture* GameObject::getTexture(){
    return texture;
}

void GameObject::resetPosition() {
    setPosition(oldPosition);
}

bool GameObject::intersects(GameObject &other) {

    int tileSize = 20;
    Vector2 otherPos = other.getPosition();
    std::vector<Vector2> otherCorners = {
            {otherPos.getX(), otherPos.getY()},
            {otherPos.getX() + tileSize, otherPos.getY()},
            {otherPos.getX(), otherPos.getY() + tileSize},
            {otherPos.getX() + tileSize, otherPos.getY() + tileSize}
    };

    return std::any_of(otherCorners.begin(), otherCorners.end(), [&](Vector2& otherCorner){
        if(position.getX() <= otherCorner.getX() && position.getX() + tileSize >= otherCorner.getX()){
            if(position.getY() <= otherCorner.getY() && position.getY() + tileSize >= otherCorner.getY()){
                return true;
            }
        }
        return false;
    });
}

bool GameObject::isTrigger() const {
    return objectIsTrigger;
}
