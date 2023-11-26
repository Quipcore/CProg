//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_SCENE_H
#define CPROG_PROJECT_SCENE_H

#include "scripts/Player.h"
#include "scripts/GameObject.h"
#include "springhawk/renderers/RenderTag.h"
#include "springhawk/maps/Map.h"
#include <vector>


class Scene {
public:
    Scene(Player* player, std::vector<std::vector<int>> tileMap, std::vector<GameObject*> gameObjects, springhawk::RenderTag renderTag);
    Scene(Player *player, Map map, std::vector<GameObject *> gameObjects, springhawk::RenderTag renderTag);

    ~Scene();

    std::vector<GameObject *> getGameObjects();
    Player * getPlayer();
    std::vector<std::vector<int>> getTileMap();
    springhawk::RenderTag getRenderTag() const;

    Map getMap();

private:
    Player* player;
    Map map;
    std::vector<std::vector<int>> tileMap;
    std::vector<GameObject*> gameObjects;
    springhawk::RenderTag renderTag;
};


#endif //CPROG_PROJECT_SCENE_H
