//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_SCENE_H
#define CPROG_PROJECT_SCENE_H

#include "scripts/Player.h"
#include "scripts/GameObject.h"
#include "springhawk/renderers/RenderTag.h"
#include "springhawk/maps/Map.h"
#include "springhawk/maps/Tilemap.h"
#include <vector>


class Scene {
public:
    ~Scene() = default;
    Scene()= delete;
    Scene(Player &player, Map &incomingMap, std::vector<GameObject *> &gameObjects, springhawk::RenderTag renderTag);

    std::vector<GameObject *> getGameObjects();
    Player &getPlayer();

    [[nodiscard("Need to render scene!")]] springhawk::RenderTag getRenderTag() const;

    Map & getMap();

    void loadTextures(SDL_Renderer &renderer);
private:
    Player player;
    Map* map;
    std::vector<GameObject*> gameObjects;
    std::map<int,SDL_Texture*> textureMap;
    springhawk::RenderTag renderTag;


};


#endif //CPROG_PROJECT_SCENE_H
