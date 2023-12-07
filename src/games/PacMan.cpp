#include "games/PacMan.h"
#include "springhawk/SceneBuilder.h"
#include "springhawk/maps/Tilemap.h"
#include "springhawk/Engine.h"

void PacMan::run() {
    auto* sceneBuilder = new springhawk::SceneBuilder();
    auto* tilemap = new springhawk::Tilemap("pacman.sphk");
    auto* player = new Player();

    sceneBuilder->addScene();

    sceneBuilder->setMap(*tilemap);
    sceneBuilder->setPlayer(*player);

    std::vector<Scene*> scenes = sceneBuilder->buildScenes();
    springhawk::Engine::run(scenes);
}