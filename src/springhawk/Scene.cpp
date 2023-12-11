#include <iostream>
#include <utility>
#include "springhawk/Scene.h"
#include "SDL2/SDL.h"

//----------------------------------------------------------------------------------------------------------------------

Scene::Scene(Map &incomingMap, std::vector<GameObject *> &gameObjects, springhawk::RenderTag renderTag) {
    this->map = &incomingMap;
    this->gameObjects = std::move(gameObjects);
    this->renderTag = renderTag;
}

//----------------------------------------------------------------------------------------------------------------------

std::vector<GameObject *> Scene::getGameObjects() {
    return gameObjects;
}

//----------------------------------------------------------------------------------------------------------------------

springhawk::RenderTag Scene::getRenderTag() const {
    return renderTag;
}

//----------------------------------------------------------------------------------------------------------------------

Map & Scene::getMap() {
    return *map;
}

//----------------------------------------------------------------------------------------------------------------------

void Scene::loadTextures(SDL_Renderer& renderer) {
    map->loadTextures(renderer);
    for(GameObject* gameObject : gameObjects){
        gameObject->setTexture(renderer, "pac.png");
    }
}

//----------------------------------------------------------------------------------------------------------------------

void Scene::destroyTextures() {
    //TODO: Destory textures in the same places they were created!
}


