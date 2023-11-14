//
// Created by felix on 2023-11-14.
//

#include "games/Wolfenstein.h"

#include "iostream"

#include "springhawk/Engine.h"
#include "springhawk/SceneBuilder.h"
#include "scripts/Player.h"


void Wolfenstein::run() {

    Springhawk::SceneBuilder sceneBuilder;
    std::vector<std::vector<int>> mapVector = {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 2, 0, 0, 0, 0, 1},
            {1, 0, 2, 0, 0, 0, 0, 1},
            {1, 0, 2, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 2, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1}
    };
    sceneBuilder.setMap(mapVector);

    sceneBuilder.setPlayer(new Player());
    //sceneBuilder.addGameObjects();
    sceneBuilder.addScene();

    std::vector<Scene*> scenes = sceneBuilder.buildScenes();

    Springhawk::Engine::run(scenes);
    std::cout << "Wolfenstein 3D!" << std::endl;
}