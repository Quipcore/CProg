//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_SCENEBUILDER_H
#define CPROG_PROJECT_SCENEBUILDER_H

#include <vector>
#include <memory>
#include "springhawk/Scene.h"
#include "components/gamecomponents/Player.h"
#include "Audio.h"


namespace springhawk{
    class SceneBuilder {
    public:

        SceneBuilder() = default;
        SceneBuilder(const SceneBuilder&) = default;
        ~SceneBuilder() = default;

        SceneBuilder& addScene();

        SceneBuilder& setMap(Tilemap *map);
        Map *getMap();

        SceneBuilder& addGameObjects(std::vector<GameObject *>& gameObjects);
        SceneBuilder &addGameObjects(std::initializer_list<GameObject *> gameObjects);

        SceneBuilder& setRenderTag(RenderTag renderTag);

        SceneBuilder& addFromJSON(std::string path);

        SceneBuilder &addUIComponents(std::vector<UIComponent *> &uiComponents);
        SceneBuilder &addUIComponents(std::initializer_list<UIComponent *> uiComponents);

        SceneBuilder& addBackgroundMusic(std::string&,bool);
        std::vector<Scene*> buildScenes();

    private:
        std::vector<Scene*> scenes;
        Map* currentMap;

        std::vector<Audio*> currentAudio;
        std::vector<GameObject*> currentGameObjects;
        std::vector<UIComponent*> currentUIComponents;
        springhawk::RenderTag currentRenderTag;
    };
}


#endif //CPROG_PROJECT_SCENEBUILDER_H
