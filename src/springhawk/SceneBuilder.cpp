#include <fstream>
#include "springhawk/SceneBuilder.h"
#include <nlohmann/json.hpp>
#include <iostream>

springhawk::SceneBuilder &springhawk::SceneBuilder::addFromJSON(std::string path) {

    std::ifstream file(path);
    nlohmann::json data = nlohmann::json::parse(file);

    //Properties
    nlohmann::json properties = data["properties"];
    std::map<std::string,RenderTag> renderTags{
            {"Plane", RenderTag::Plane},
            {"Raycast", RenderTag::Raycaster},
            {"Doom", RenderTag::Doom}
    };
    RenderTag renderTag;
    for (const auto& entry : properties.items()) {
        if(entry.key() == "renderingMode"){
            renderTag = renderTags[entry.value()];
        }
    }
    setRenderTag(renderTag);

    //Map
    nlohmann::json map = data["scenes"][0]["gameScene"]["map"];
    auto* tilemap = new Tilemap(map);
    setMap(tilemap);


//    //Add gameobjects
//    auto gameObjects = new std::vector<GameObject*>{
//        new Player(tilemap)
//    };
//    addGameObjects(*gameObjects);

    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

springhawk::SceneBuilder& springhawk::SceneBuilder::addScene() {
    scenes.push_back(new Scene(*currentMap, currentGameObjects,currentRenderTag));
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

springhawk::SceneBuilder& springhawk::SceneBuilder::setRenderTag(RenderTag renderTag) {
    this->currentRenderTag = renderTag;
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

std::vector<Scene *> springhawk::SceneBuilder::buildScenes() {
    return scenes;
}

//----------------------------------------------------------------------------------------------------------------------

springhawk::SceneBuilder & springhawk::SceneBuilder::setMap(Tilemap *map) {
    this->currentMap = map;
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

springhawk::SceneBuilder &springhawk::SceneBuilder::addGameObjects(std::vector<GameObject *> &gameObjects) {
    for(GameObject* gameObject : gameObjects){
        currentGameObjects.push_back(gameObject);
    }
    return *this;
}
springhawk::SceneBuilder &springhawk::SceneBuilder::addGameObjects(std::initializer_list<GameObject*> gameObjects) {
    for(GameObject* gameObject : gameObjects){
        currentGameObjects.push_back(gameObject);
    }
    return *this;
}

Map *springhawk::SceneBuilder::getMap() {
    return currentMap;
}
