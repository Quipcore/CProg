#include "springhawk/SceneBuilder.h"

springhawk::SceneBuilder& springhawk::SceneBuilder::addScene() {
    scenes.push_back(new Scene(currentPlayer, *currentMap, currentGameObjects,currentRenderTag));
    return *this;
}

springhawk::SceneBuilder& springhawk::SceneBuilder::setPlayer(Player& player) {
    this->currentPlayer = player;
    return *this;
}

springhawk::SceneBuilder& springhawk::SceneBuilder::setRenderTag(RenderTag renderTag) {
    this->currentRenderTag = renderTag;
    return *this;
}

std::vector<Scene *> springhawk::SceneBuilder::buildScenes() {
    return scenes;
}

springhawk::SceneBuilder & springhawk::SceneBuilder::setMap(Map& map) {
    this->currentMap = &map;
    return *this;
}

springhawk::SceneBuilder &springhawk::SceneBuilder::addGameObjects(std::vector<GameObject *> &gameObjects) {
    for(GameObject* gameObject : gameObjects){
        currentGameObjects.push_back(gameObject);
    }
    return *this;
}
