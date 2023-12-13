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

//        Engine() = delete;
//        ~Engine();
//        Engine(const Engine&) = delete;
//
//        explicit Engine(std::vector<Scene*>&scenes);

        static void instantiate(GameObject* gameObject);
        static void instantiate(UIComponent* uiComponent);
        static int run(std::vector<Scene *>& giveScenes);

    private:
        static const int SCREEN_WIDTH = 1500;
        static const int SCREEN_HEIGHT = 680;

        static const std::vector<Scene *> *scenes;
        static std::vector<GameObject *> gameObjects;
        static std::vector<UIComponent *> uiComponents;


        //Might causes prefomance issues
        static void (*render)(SDL_Renderer &, std::vector<GameObject *> &, Map &, int, int);

        static bool init();
        static void quit(SDL_Renderer *renderer, SDL_Window *window);
        void sleep(int);
        static void handleEvent(SDL_Event &event);

        static void startNextScene(SDL_Renderer &renderer);
        static void startGameLoop(SDL_Renderer &, Map&);
        static void renderScene(SDL_Renderer&, Map&);
    };
}


#endif //CPROG_PROJECT_ENGINE_H
