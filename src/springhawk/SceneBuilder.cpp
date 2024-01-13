#include <fstream>
#include "springhawk/SceneBuilder.h"
#include "springhawk/Audio.h"
#include <nlohmann/json.hpp>
#include <iostream>

springhawk::SceneBuilder &springhawk::SceneBuilder::addFromJSON(std::string path) {

    std::ifstream file(path);
    nlohmann::json data = nlohmann::json::parse(file);
    file.close();
    //Properties
    nlohmann::json properties = data["properties"];
    std::map<std::string,RenderTag> renderTags{
            {"Plane", RenderTag::Plane},
            {"Raycaster", RenderTag::Raycaster},
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


    return *this;
}

springhawk::SceneBuilder& springhawk::SceneBuilder::addBackgroundMusic(std::string& path, bool loop){
    currentAudio.push_back(new Audio(path,loop));
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

springhawk::SceneBuilder& springhawk::SceneBuilder::addScene() {
    scenes.push_back(new Scene(*currentMap, currentGameObjects,currentUIComponents,currentRenderTag,currentAudio));
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

//----------------------------------------------------------------------------------------------------------------------

springhawk::SceneBuilder &springhawk::SceneBuilder::addGameObjects(std::initializer_list<GameObject*> gameObjects) {
    for(GameObject* gameObject : gameObjects){
        currentGameObjects.push_back(gameObject);
    }
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

springhawk::SceneBuilder &springhawk::SceneBuilder::addUIComponents(std::vector<UIComponent *> &uiComponents) {
    for(UIComponent* uiComponent : uiComponents){
        currentUIComponents.push_back(uiComponent);
    }
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

springhawk::SceneBuilder &springhawk::SceneBuilder::addUIComponents(std::initializer_list<UIComponent *> uiComponents) {
    for(UIComponent* uiComponent : uiComponents){
        currentUIComponents.push_back(uiComponent);
    }
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------

Map *springhawk::SceneBuilder::getMap() {
    return currentMap;
}
