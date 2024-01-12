#ifndef CPROG_PROJECT_ENGINE_H
#define CPROG_PROJECT_ENGINE_H

#include <vector>
#include "SDL2/SDL.h"
#include "components/gamecomponents/GameObject.h"
#include "springhawk/Time.h"
#include "springhawk/Scene.h"
#include "springhawk/renderers/Renderer.h"
#include "Input.h"
#include "maps/Map.h"

namespace springhawk {
    class Engine: Time{
    public:
        static void instantiate(GameObject* gameObject);
        static void instantiate(UIComponent* uiComponent);

        template<typename Base, typename T>
        static bool instanceof(const T *ptr) {
            return dynamic_cast<const Base*>(ptr) != nullptr;
        }

        template<typename T>
        static std::vector<T*> getObjects(){
            if(!beenInitialized){
                return {};
            }

            std::vector<T*> objects;
            for(GameObject* gameObject : Engine::gameObjects){
                if(instanceof<T>(gameObject)){
                    objects.push_back((T*)gameObject);
                }
            }

            return objects;
        }

        static int run(std::vector<Scene *>& incomingScenes);
        static int initilize();

        static void swapTexture(GameObject* gameObject, std::string path);

    private:
        static const int SCREEN_WIDTH = 1500;
        static const int SCREEN_HEIGHT = 680;

        static const std::vector<Scene *> *scenes;
        static std::vector<GameObject *> gameObjects;
        static std::vector<UIComponent *> uiComponents;

        static SDL_Renderer *renderer;
        static SDL_Window *window;

        static Map* map;

        static bool beenInitialized;

        //Might causes performance issues
        static void (*render)(SDL_Renderer &, std::vector<GameObject *> &, Map &, int, int);

        static bool init();
        static void quit(SDL_Renderer *renderer, SDL_Window *window);
        void sleep(int);
        static void handleEvent(SDL_Event &event);

        static void startNextScene(SDL_Renderer &renderer);
        static void startGameLoop(SDL_Renderer &, Map&);
        static void renderScene(SDL_Renderer&, Map&);

        static void checkCollisions(Map &map);

        static void updateObjects();
    };
}


#endif //CPROG_PROJECT_ENGINE_H
