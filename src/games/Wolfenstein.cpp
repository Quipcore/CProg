//
// Created by felix on 2023-11-14.
//

#include "games/Wolfenstein.h"

#include "iostream"

#include "springhawk/Engine.h"
#include "springhawk/SceneBuilder.h"
#include "scripts/Player.h"


void Wolfenstein::run() {

    springhawk::SceneBuilder sceneBuilder;
    std::vector<std::vector<int>> mapVector = {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {3, 0, 2, 0, 0, 0, 0, 5},
            {3, 0, 2, 0, 0, 0, 0, 5},
            {3, 0, 2, 0, 0, 0, 0, 5},
            {3, 0, 0, 0, 0, 0, 0, 5},
            {3, 0, 0, 0, 0, 2, 0, 5},
            {3, 0, 0, 0, 0, 0, 0, 5},
            {3, 4, 4, 4, 4, 4, 4, 4}
    };
    sceneBuilder.setMap(mapVector);
    sceneBuilder.setPlayer(new Player());
    //sceneBuilder.addGameObjects();
    sceneBuilder.setRenderTag(springhawk::RenderTag::Raycaster);

    sceneBuilder.addScene();
    std::vector<Scene*> scenes = sceneBuilder.buildScenes();

    springhawk::Engine::run(scenes);
    std::cout << "Wolfenstein 3D!" << std::endl;
}