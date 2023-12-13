//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_SCENE_H
#define CPROG_PROJECT_SCENE_H

#include "components/gamecomponents/Player.h"
#include "components/gamecomponents/GameObject.h"
#include "components/uiComponents/UIComponent.h"
#include "springhawk/renderers/RenderTag.h"
#include "springhawk/maps/Map.h"
#include "springhawk/maps/Tilemap.h"
#include <vector>


class Scene {
public:
    ~Scene() = default;
    Scene()= delete;
    Scene(Map &incomingMap, std::vector<GameObject *> &gameObjects, std::vector<UIComponent*>, springhawk::RenderTag renderTag);

    std::vector<GameObject *> getGameObjects();
    std::vector<UIComponent *> getUIComponents();

    [[nodiscard("Needed to render scene!")]] springhawk::RenderTag getRenderTag() const;

    Map & getMap();

    void loadTextures(SDL_Renderer &renderer);

    void destroyTextures();



private:
    Map* map;
    std::vector<GameObject*> gameObjects;
    std::vector<UIComponent*> uiComponents;
    std::map<int,SDL_Texture*> textureMap;
    springhawk::RenderTag renderTag;
};


#endif //CPROG_PROJECT_SCENE_H
