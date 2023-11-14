//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_SCENEBUILDER_H
#define CPROG_PROJECT_SCENEBUILDER_H

#include <vector>
#include "springhawk/Scene.h"
#include "scripts/Player.h"

namespace Springhawk{
    class SceneBuilder {
    public :
        SceneBuilder addScene();
        SceneBuilder setMap(std::vector<std::vector<int>>);
        SceneBuilder setPlayer(Player* player);
        SceneBuilder addGameObjects(std::vector<GameObject *> gameObjects);
        std::vector<Scene*> buildScenes();
    private:
        std::vector<Scene*> scenes;
        Scene* currentScene;
        Player* currentPlayer;
        std::vector<std::vector<int>> currentMap;
        std::vector<GameObject*> currentGameObjects;
    };
}


#endif //CPROG_PROJECT_SCENEBUILDER_H
