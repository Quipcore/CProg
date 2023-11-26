//
// Created by felix on 2023-11-14.
//

#include "springhawk/SceneBuilder.h"
#include "springhawk/Scene.h"

springhawk::SceneBuilder springhawk::SceneBuilder::addScene() {

    currentScene = new Scene(currentPlayer, currentMap, currentGameObjects,currentRenderTag);

    scenes.push_back(currentScene);

    return *this;
}

springhawk::SceneBuilder springhawk::SceneBuilder::setMap(std::vector<std::vector<int>> map) {
    this->currentMap = map;
    return *this;
}

springhawk::SceneBuilder springhawk::SceneBuilder::setPlayer(Player* player) {
    this->currentPlayer = player;
    return *this;
}

springhawk::SceneBuilder springhawk::SceneBuilder::setRenderTag(RenderTag renderTag) {
    this->currentRenderTag = renderTag;
    return *this;
}

std::vector<Scene *> springhawk::SceneBuilder::buildScenes() {
    return scenes;
}

springhawk::SceneBuilder springhawk::SceneBuilder::addGameObjects(std::vector<GameObject *> gameObjects) {
    for(GameObject* gameObject : gameObjects){
        currentGameObjects.push_back(gameObject);
    }
    return *this;
}
