//
// Created by felix on 2023-11-14.
//

#include <iostream>
#include <utility>
#include "springhawk/Scene.h"
#include "springhawk/Map.h"

Scene::~Scene() = default;

Scene::Scene(Player *player, Map map, std::vector<GameObject *> gameObjects, Springhawk::RenderTag renderTag) {
    this->player = player;
    this->map = map;
    this->gameObjects = std::move(gameObjects);
    this->renderTag = renderTag;
}

Scene::Scene(Player *player, std::vector<std::vector<int>> tileMap, std::vector<GameObject *> gameObjects, Springhawk::RenderTag renderTag) {
    this->player = player;
    this->tileMap = std::move(tileMap);
    this->gameObjects = std::move(gameObjects);
    this->renderTag = renderTag;
}

std::vector<GameObject *> Scene::getGameObjects() {
    return gameObjects;
}

Player * Scene::getPlayer() {
    return player;
}

std::vector<std::vector<int>> Scene::getTileMap() {
    return tileMap;
}

Springhawk::RenderTag Scene::getRenderTag() const {
    return renderTag;
}

Map Scene::getMap() {
    return map;
}
