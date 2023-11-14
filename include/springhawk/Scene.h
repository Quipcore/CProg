//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_SCENE_H
#define CPROG_PROJECT_SCENE_H

#include "scripts/Player.h"
#include "scripts/GameObject.h"
#include <vector>


class Scene {
public:
    Scene(Player* player, std::vector<std::vector<int>> map, std::vector<GameObject*> gameObjects);
    ~Scene();

    std::vector<GameObject *> getGameObjects();
    Player * getPlayer();
    std::vector<std::vector<int>> getMap();

private:
    Player* player;
    std::vector<std::vector<int>> map;
    std::vector<GameObject*> gameObjects;
};


#endif //CPROG_PROJECT_SCENE_H
