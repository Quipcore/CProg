//
// Created by felix on 2023-11-12.
//

#include "springhawk/Renderer.h"
#include "Math.h"

int Renderer::SCREEN_WIDTH = 0;
int Renderer::SCREEN_HEIGHT = 0;
int Renderer::map[mapWidth][mapHeight] = {
        {1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,1},
        {1,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1}
};

void Renderer::render(SDL_Renderer* pRenderer, std::vector<GameObject*> &gameObjects, int width, int height){
    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;
    drawMap(pRenderer);
    drawObjects(pRenderer,gameObjects);
}

void Renderer::drawMap(SDL_Renderer *pRenderer) {
    int w = SCREEN_WIDTH / mapWidth;
    int h = SCREEN_HEIGHT / mapHeight;
    int x, y, xo, yo;
    for(y = 0; y < mapHeight; y++){
        for(x = 0; x < mapWidth; x++){
            if(map[y][x] == 1){
                SDL_SetRenderDrawColor(pRenderer, 0xff,0xff,0xff,0xff);
            } else {
                SDL_SetRenderDrawColor(pRenderer, 0x00,0x00,0x00,0xff);
            }
            xo = x * w;
            yo = y * h;
            SDL_Rect rect = {xo,yo,w-1,h-1};
            SDL_RenderFillRect(pRenderer,&rect);
        }
    }
}

void Renderer::drawObjects(SDL_Renderer *pRenderer, std::vector<GameObject*> &vector) {
    for(const auto& gameObject : vector){
        if(gameObject->getTag() == Tag::Player){
            Color color = gameObject->getColor();
            Vector2 position = gameObject->getPosition();
            SDL_Rect rect = {(int) position.getX(),(int) -position.getY(), 10,10};
            SDL_SetRenderDrawColor(pRenderer, color.r,color.g,color.b,color.a);
            SDL_RenderFillRect(pRenderer,&rect);

            const float startScale = 1;
            const float lineThickness = 1;
            float angle = 0;
            const float fov = M_PI/2;
            float lineLength = 10;
            int lineCount = 100;

            int lineStartX = (int) position.getX()/lineThickness;
            int lineStartY = (int) -position.getY()/lineThickness;

            for(int i = 0; i < lineCount; i++){
                angle = (fov/lineCount) * i - fov/2;
                Vector2 direction = {cos(angle),sin(angle)};
                Vector2 endPosition = position + direction * lineLength;
                SDL_RenderSetScale(pRenderer,lineThickness,lineThickness);

                int lineEndX = (int) endPosition.getX()/lineThickness;
                int lineEndY = (int) -endPosition.getY()/lineThickness;

                SDL_RenderDrawLine(pRenderer,lineStartX,lineStartY,lineEndX,lineEndY);
                SDL_RenderSetScale(pRenderer,startScale,startScale);
            }
        }

    }
}
