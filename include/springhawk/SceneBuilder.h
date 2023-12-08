//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_SCENEBUILDER_H
#define CPROG_PROJECT_SCENEBUILDER_H

#include <vector>
#include <memory>
#include "springhawk/Scene.h"
#include "scripts/Player.h"


namespace springhawk{
    class SceneBuilder {
    public :
        SceneBuilder() = default;
        SceneBuilder(const SceneBuilder&) = default;
        ~SceneBuilder() = default;

        SceneBuilder& addScene();
        SceneBuilder& setMap(Map &map);
        SceneBuilder& addGameObjects(std::vector<GameObject *>& gameObjects);
        SceneBuilder& setRenderTag(RenderTag renderTag);
        SceneBuilder& setPlayer(Player &player);
        SceneBuilder& addFromJSON(std::string path);

        std::vector<Scene*> buildScenes();

    private:
        std::vector<Scene*> scenes;
        Scene currentScene;
        Player currentPlayer;
        Map* currentMap;
        std::vector<GameObject*> currentGameObjects;
        std::map<int,SDL_Texture*> textureMap;
        springhawk::RenderTag currentRenderTag;
    };
}


#endif //CPROG_PROJECT_SCENEBUILDER_H
