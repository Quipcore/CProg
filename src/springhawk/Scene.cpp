//
// Created by felix on 2023-11-14.
//

#include <iostream>
#include <utility>
#include "springhawk/Scene.h"

Scene::~Scene() = default;

Scene::Scene(Player *player, std::vector<std::vector<int>> map, std::vector<GameObject *> gameObjects, Springhawk::RenderTag renderTag) {
    this->player = player;
    this->map = std::move(map);
    this->gameObjects = std::move(gameObjects);
    this->renderTag = renderTag;
}

std::vector<GameObject *> Scene::getGameObjects() {
    return gameObjects;
}

Player * Scene::getPlayer() {
    return player;
}

std::vector<std::vector<int>> Scene::getMap() {
    return map;
}

Springhawk::RenderTag Scene::getRenderTag() const {
    return renderTag;
}
