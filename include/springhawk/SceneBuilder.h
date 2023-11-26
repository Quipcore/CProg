//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_SCENEBUILDER_H
#define CPROG_PROJECT_SCENEBUILDER_H

#include <vector>
#include "springhawk/Scene.h"
#include "scripts/Player.h"

namespace springhawk{
    class SceneBuilder {
    public :
        SceneBuilder addScene();
        SceneBuilder setMap(std::vector<std::vector<int>>);
        SceneBuilder setPlayer(Player* player);
        SceneBuilder addGameObjects(std::vector<GameObject *> gameObjects);
        std::vector<Scene*> buildScenes();

        SceneBuilder setRenderTag(RenderTag renderTag);

    private:
        std::vector<Scene*> scenes;
        Scene* currentScene;
        Player* currentPlayer;
        std::vector<std::vector<int>> currentMap;
        std::vector<GameObject*> currentGameObjects;
        springhawk::RenderTag currentRenderTag;

    };
}


#endif //CPROG_PROJECT_SCENEBUILDER_H
