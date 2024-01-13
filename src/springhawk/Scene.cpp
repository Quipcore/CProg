#include <iostream>
#include <utility>
#include "springhawk/Scene.h"
#include "SDL2/SDL.h"
#include "springhawk/Engine.h"


Scene::Scene(Map &incomingMap, std::vector<GameObject *> &gameObjects, std::vector<UIComponent *> uiComponents, springhawk::RenderTag renderTag, std::vector<Audio*> audio) {
    this->map = &incomingMap;
    this->gameObjects = std::move(gameObjects);
    this->uiComponents = std::move(uiComponents);
    this->renderTag = renderTag;
    this->currentAudio = std::move(audio);
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
        springhawk::Engine::swapTexture(gameObject, gameObject->getTexturePath());
    }
}

//----------------------------------------------------------------------------------------------------------------------
void Scene::destroyTextures() {
    for(GameObject* gameObject : gameObjects){
        SDL_DestroyTexture(gameObject->getTexture());
    }
}

std::vector<UIComponent *> Scene::getUIComponents() {
    return uiComponents;
}




