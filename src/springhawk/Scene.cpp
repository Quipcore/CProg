#include <iostream>
#include <utility>
#include "springhawk/Scene.h"
#include "SDL2/SDL.h"

//----------------------------------------------------------------------------------------------------------------------

Scene::Scene(Player &player, Map &incomingMap, std::vector<GameObject *> &gameObjects, springhawk::RenderTag renderTag) {
    this->player = player;
    this->map = &incomingMap;
    this->gameObjects = std::move(gameObjects);
    this->renderTag = renderTag;
}

//----------------------------------------------------------------------------------------------------------------------

std::vector<GameObject *> Scene::getGameObjects() {
    return gameObjects;
}

//----------------------------------------------------------------------------------------------------------------------

Player &Scene::getPlayer() {
    return player;
}

//----------------------------------------------------------------------------------------------------------------------

springhawk::RenderTag Scene::getRenderTag() const {
    return renderTag;
}

//----------------------------------------------------------------------------------------------------------------------

Map & Scene::getMap() {
    return *map;
}

void Scene::loadTextures(SDL_Renderer& renderer) {
    map->loadTextures(renderer);
    player.setTexture(renderer,"pac.png");
}
