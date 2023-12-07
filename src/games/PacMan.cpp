#include "games/PacMan.h"
#include "springhawk/SceneBuilder.h"
#include "springhawk/maps/Tilemap.h"
#include "springhawk/Engine.h"
#include "scripts/PacmanController.h"
#include "Constants.h"

void PacMan::run() {
    auto* sceneBuilder = new springhawk::SceneBuilder();


    sceneBuilder->addFromJSON(constants::gResPath + "json/pacman.json");
//
//    sceneBuilder->setMap(*new springhawk::Tilemap("pacman.sphk"));
//    sceneBuilder->setPlayer(*new PacmanController());
//    sceneBuilder->setRenderTag(springhawk::RenderTag::Plane);

    sceneBuilder->addScene();
    std::vector<Scene*> scenes = sceneBuilder->buildScenes();
    springhawk::Engine::run(scenes);
}