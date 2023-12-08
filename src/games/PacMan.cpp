#include "games/PacMan.h"
#include "springhawk/SceneBuilder.h"
#include "springhawk/maps/Tilemap.h"
#include "springhawk/Engine.h"
#include "scripts/PacmanController.h"
#include "Constants.h"

void PacMan::run() {
    auto* sceneBuilder = new springhawk::SceneBuilder();
    sceneBuilder->addFromJSON(constants::gResPath + "json/pacman.json");
    std::vector<Scene*> scenes = sceneBuilder->buildScenes();
    springhawk::Engine::run(scenes);
}