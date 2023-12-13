#include "components/Gamecomponents/GameObject.h"
#include "iostream"
#include "Constants.h"
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

    std::string pathToImage = constants::imagePath + path;

    SDL_Surface *surface = IMG_Load(pathToImage.c_str());
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(&renderer, surface);
    SDL_FreeSurface(surface);
    this->texture = pTexture;
}

SDL_Texture* GameObject::getTexture(){
    return texture;
}

void GameObject::resetPosition() {
    setPosition(oldPosition);
}
