//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_SCENE_H
#define CPROG_PROJECT_SCENE_H

#include "SDL2/SDL.h"

#include "components/gamecomponents/Player.h"
#include "components/gamecomponents/GameObject.h"
#include "components/uiComponents/UIComponent.h"
#include "springhawk/renderers/RenderTag.h"
#include "springhawk/maps/Map.h"
#include "springhawk/maps/Tilemap.h"
#include "Audio.h"
#include <vector>
#include <SDL2/SDL_mixer.h>


class Scene {
public:
    ~Scene(){
            for(auto audio: currentAudio){
                delete audio;
            }
    };
    Scene() = delete;

    Scene(Map &incomingMap, std::vector<GameObject *> &gameObjects, std::vector<UIComponent*>, springhawk::RenderTag, std::vector<Audio*>);

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
    std::vector<Audio*> currentAudio;

    std::map<int,SDL_Texture*> textureMap;
    springhawk::RenderTag renderTag;
};


#endif //CPROG_PROJECT_SCENE_H
