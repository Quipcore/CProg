#include <iostream>
#include <utility>
#include "springhawk/Scene.h"

//----------------------------------------------------------------------------------------------------------------------

Scene::Scene(Player &player, Map &incomingMap, std::vector<GameObject *> &gameObjects, springhawk::RenderTag renderTag)  : map(incomingMap) {
    this->player = player;
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
    return map;
}