//
// Created by felix on 2023-11-14.
//

#include "springhawk/SceneBuilder.h"
#include "springhawk/Scene.h"

Springhawk::SceneBuilder Springhawk::SceneBuilder::addScene() {

    currentScene = new Scene(currentPlayer, currentMap, currentGameObjects,currentRenderTag);

    scenes.push_back(currentScene);

    return *this;
}

Springhawk::SceneBuilder Springhawk::SceneBuilder::setMap(std::vector<std::vector<int>> map) {
    this->currentMap = map;
    return *this;
}

Springhawk::SceneBuilder Springhawk::SceneBuilder::setPlayer(Player* player) {
    this->currentPlayer = player;
    return *this;
}

Springhawk::SceneBuilder Springhawk::SceneBuilder::setRenderTag(RenderTag renderTag) {
    this->currentRenderTag = renderTag;
    return *this;
}

std::vector<Scene *> Springhawk::SceneBuilder::buildScenes() {
    return scenes;
}

Springhawk::SceneBuilder Springhawk::SceneBuilder::addGameObjects(std::vector<GameObject *> gameObjects) {
    for(GameObject* gameObject : gameObjects){
        currentGameObjects.push_back(gameObject);
    }
    return *this;
}
