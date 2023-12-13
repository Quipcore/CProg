#include "games/PacMan.h"
#include "springhawk/SceneBuilder.h"
#include "springhawk/maps/Tilemap.h"
#include "springhawk/Engine.h"
#include "components/gamecomponents/PacmanController.h"
#include "Constants.h"

void PacMan::run() {
    auto* sceneBuilder = new springhawk::SceneBuilder();
    sceneBuilder->addFromJSON(constants::jsonPath + "pacman.json");
    sceneBuilder->addGameObjects({
        new PacmanController(sceneBuilder->getMap())
    });
    sceneBuilder->addScene();
    std::vector<Scene*> scenes = sceneBuilder->buildScenes();
    springhawk::Engine::run(scenes);
}