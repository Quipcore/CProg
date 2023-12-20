#include "components/gamecomponents/Player.h"
#include "games/Wolfenstein.h"

#include "iostream"

#include "springhawk/Engine.h"
#include "springhawk/SceneBuilder.h"
#include "springhawk/maps/Tilemap.h"
#include "Constants.h"

void Wolfenstein::run() {

    springhawk::Engine::initilize();

    auto* sceneBuilder = new springhawk::SceneBuilder();
    sceneBuilder->addFromJSON(constants::jsonPath + "wolfenstein.json");

    sceneBuilder->addGameObjects({
        new Player(),
    });
    sceneBuilder->setRenderTag(springhawk::RenderTag::Raycaster);
    sceneBuilder->addScene();
    std::vector<Scene*> scenes = sceneBuilder->buildScenes();
    springhawk::Engine::run(scenes);
}
