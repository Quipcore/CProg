#include "games/PacMan.h"
#include "springhawk/SceneBuilder.h"
#include "springhawk/maps/Tilemap.h"
#include "springhawk/Engine.h"
#include "components/gamecomponents/PacmanController.h"
#include "Constants.h"
#include "components/gamecomponents/Blinky.h"

void PacMan::run() {
    springhawk::Engine::initilize();

    auto* sceneBuilder = new springhawk::SceneBuilder();
    sceneBuilder->addFromJSON(constants::jsonPath + "pacman.json");

    sceneBuilder->addGameObjects({
        new PacmanController(sceneBuilder->getMap()),
        new Blinky(sceneBuilder->getMap()),
    });
    sceneBuilder->addScene();
    std::vector<Scene*> scenes = sceneBuilder->buildScenes();

    springhawk::Engine::run(scenes);
}