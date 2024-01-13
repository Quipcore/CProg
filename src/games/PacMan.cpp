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

    std::vector<GameObject*> gameObjects = {
            new PacmanController(sceneBuilder->getMap()),
            new Blinky(sceneBuilder->getMap()),
    };

    sceneBuilder->addGameObjects(gameObjects);

    std::string path = constants::audioPath + "pacman_startup.mp3";
    sceneBuilder->addBackgroundMusic(path, false);

    sceneBuilder->addScene();
    std::vector<Scene*> scenes = sceneBuilder->buildScenes();

    springhawk::Engine::run(scenes);

    delete sceneBuilder;
}