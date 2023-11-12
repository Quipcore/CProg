//
// Created by felix on 2023-11-12.
//

#include "springhawk/Renderer.h"
#include "Math.h"

int Renderer::SCREEN_WIDTH = 0;
int Renderer::SCREEN_HEIGHT = 0;
int Renderer::map[mapWidth][mapHeight] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
};

void Renderer::render(SDL_Renderer *pRenderer, std::vector<GameObject *> &gameObjects, int width, int height) {
    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;
    drawMap(pRenderer);
    drawObjects(pRenderer, gameObjects);
}

void Renderer::drawMap(SDL_Renderer *pRenderer) {
    int w = SCREEN_WIDTH / mapWidth;
    int h = SCREEN_HEIGHT / mapHeight;
    int x, y, xo, yo;
    for (y = 0; y < mapHeight; y++) {
        for (x = 0; x < mapWidth; x++) {
            if (map[y][x] == 1) {
                SDL_SetRenderDrawColor(pRenderer, 0xff, 0xff, 0xff, 0xff);
            } else {
                SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xff);
            }
            xo = x * w;
            yo = y * h;
            SDL_Rect rect = {xo, yo, w - 1, h - 1};
            SDL_RenderFillRect(pRenderer, &rect);
        }
    }
}

void Renderer::drawObjects(SDL_Renderer *pRenderer, std::vector<GameObject *> &vector) {
    for (auto &gameObject: vector) {
        if (gameObject->getTag() == Tag::Player) {
            drawPlayer(pRenderer, dynamic_cast<class Player *>(gameObject));
        }
    }
}

void Renderer::drawPlayer(SDL_Renderer *pRenderer, class Player *const &player) {
    //Draw player square
    Color color = player->getColor();
    Vector2 position = player->getPosition();
    SDL_Rect rect = {(int) position.getX(), (int) -position.getY(), 10, 10};
    SDL_SetRenderDrawColor(pRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(pRenderer, &rect);

    //Draw player raycast
    const float startScale = 1;
    const float lineThickness = 1;
    const float fov = M_PI / 2;

    float lineLength = 100;

    int lineCount = player->getLineCount();

    int lineStartX = (int) position.getX();
    int lineStartY = (int) -position.getY();

    for (int i = 0; i < lineCount; i++) {

        // - fov/2 to center the raycast, i goes from 0 to lineCount, i min is -fov/2 and i max is fov/2
        float angle = (fov / lineCount) * i - fov / 2 + player->getAngle();
        Vector2 direction = {cos(angle), sin(angle)};
        Vector2 endPosition = findEndPosition(position,direction,lineLength);

        SDL_RenderSetScale(pRenderer, lineThickness, lineThickness);
        int lineEndX = (int) endPosition.getX();
        int lineEndY = (int) -endPosition.getY();
        SDL_RenderDrawLine(pRenderer, lineStartX, lineStartY, lineEndX, lineEndY);
        SDL_RenderSetScale(pRenderer, startScale, startScale);
    }
}

Vector2 Renderer::findEndPosition(Vector2 &position, Vector2 &direction, float maxDistance) {
    return position + direction * maxDistance;
}
