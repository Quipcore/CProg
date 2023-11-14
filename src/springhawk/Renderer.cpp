//
// Created by felix on 2023-11-12.
//

#include <iostream>
#include "springhawk/Renderer.h"
#include "Math.h"
#include "springhawk/Input.h"

int Springhawk::Renderer::SCREEN_WIDTH = 0;
int Springhawk::Renderer::SCREEN_HEIGHT = 0;
int Springhawk::Renderer::map[mapWidth][mapHeight];

void Springhawk::Renderer::render(SDL_Renderer *pRenderer, std::vector<GameObject *> gameobjects, Player *pPlayer,
                      std::vector<std::vector<int>> map, int screenWidth, int screenHeight) {
    SCREEN_WIDTH = screenWidth;
    SCREEN_HEIGHT = screenHeight;

    for(int x = 0; x < map.size(); x++){
        for(int y = 0; y < map[x].size(); y++){
            Renderer::map[x][y] = map[x][y];
        }
    }

    //drawMap(pRenderer);
    //drawObjects(pRenderer, gameobjects);
    drawPlayer(pRenderer, pPlayer);
}

void Springhawk::Renderer::drawMap(SDL_Renderer *pRenderer) {
    int w = SCREEN_WIDTH / mapWidth;
    int h = SCREEN_HEIGHT / mapHeight;
    int x, y, xo, yo;
    for (y = 0; y < mapHeight; y++) {
        for (x = 0; x < mapWidth; x++) {
            if (map[y][x] == 1) {
                SDL_SetRenderDrawColor(pRenderer, 0xff, 0xff, 0xff, 0xff);
            }
            else if(map[y][x] == 2){
                SDL_SetRenderDrawColor(pRenderer, 0x00, 0xff, 0x00, 0xff);
            }
            else {
                SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xff);
            }
            xo = x * w;
            yo = y * h;
            SDL_Rect rect = {xo, yo, w - 1, h - 1};
            SDL_RenderFillRect(pRenderer, &rect);
        }
    }
}

void Springhawk::Renderer::drawObjects(SDL_Renderer *pRenderer, std::vector<GameObject *> &vector) {
    for (auto &gameObject: vector) {
        //Not yet implemented
    }
}

void Springhawk::Renderer::drawPlayer(SDL_Renderer *pRenderer, Player *const &player) {
    //Draw player square
//    Color color = player->getColor();
//    Vector2 position = player->getPosition();
    //SDL_Rect rect = {(int) position.getX(), (int) -position.getY(), 10, 10};
    //SDL_SetRenderDrawColor(pRenderer, color.r, color.g, color.b, color.a);
    //SDL_RenderFillRect(pRenderer, &rect);
    //std::cout << position <<" "<< player->getAngle() << std::endl;
    drawRays(pRenderer, player);
}

void Springhawk::Renderer::drawRays(SDL_Renderer *pRenderer, Player *pPlayer) {
    const int radius = 200;
    const int lineCount = pPlayer->getLineCount();
    const int sliceWidth = SCREEN_WIDTH / lineCount;
    const double fov = M_PI / 2;
    const Color rayColor = {0xff, 0, 0, 0xff};
    const double playerAngle = pPlayer->getAngle();
    Vector2 playerPosition = pPlayer->getPosition();
    int playerX = (int) playerPosition.getX();
    int playerY = (int) -playerPosition.getY();

    SDL_SetRenderDrawColor(pRenderer, rayColor.r, rayColor.g, rayColor.b, rayColor.a);

    for (int i = -lineCount / 2; i <= lineCount / 2; i++) {
        double angle = fov * (double) i / (double) lineCount + playerAngle;

        // Adjusted the direction calculation
        Vector2 direction = {cos(angle), sin(angle)};
        Vector2 endPosition = findEndPosition(playerPosition, direction, radius);

        Vector2 mapPos = findMapPoint(endPosition);
        int mapPointX = (int) mapPos.getX();
        int mapPointY = (int) mapPos.getY();

        if(map[mapPointY][mapPointX] == 1){
            SDL_SetRenderDrawColor(pRenderer, 0xff, 0, 0, 0xff);
        }
        if(map[mapPointY][mapPointX] == 2){
            SDL_SetRenderDrawColor(pRenderer, 0, 0xff, 0, 0xff);
        }


        double ca = 1;
        double lineDistance = endPosition.magnitude() * ca;
        //lineDistance = endPosition.magnitude();

        double lineHeight = SCREEN_HEIGHT / lineDistance;
        lineHeight *= SCREEN_HEIGHT;
        if(lineHeight > SCREEN_HEIGHT){
            lineHeight = SCREEN_HEIGHT;
        }


        bool render2D = Input::bufferContains(Keycode::TAB);
        if(render2D){
            drawMap(pRenderer);
            SDL_SetRenderDrawColor(pRenderer, rayColor.r, rayColor.g, rayColor.b, rayColor.a);
            SDL_RenderDrawLine(pRenderer, playerX, playerY, (int) endPosition.getX(), (int) -endPosition.getY());
        }else{
            int rectX = (i + lineCount / 2) * sliceWidth;
            int rectY = (SCREEN_HEIGHT - lineHeight) / 2;
            SDL_Rect rect = {rectX,rectY,sliceWidth,(int)lineHeight};

            SDL_RenderFillRect(pRenderer, &rect);
        }
    }

}

/*
 * 1. Shoot a ray from the player to the end of the screen
 * 2. Check if the ray intersects with a wall
 * 3. return the point of intersection
 */
Vector2 Springhawk::Renderer::findEndPosition(Vector2 &position, Vector2 &direction, double maxDistance) {

    //std::cout << "Direction: " << direction << std::endl;

    double stepSize = 1;
    Vector2 endPosition = position;
    while(isPositionValid(endPosition)){
        endPosition += direction * stepSize;
    }
    return endPosition;
}

Vector2 Springhawk::Renderer::getIntersectionPoint(Vector2 &position, double angle) {
    return position;
}

bool Springhawk::Renderer::isPositionValid(Vector2 vector2) {
    int x = (int) (vector2.getX() * mapWidth / SCREEN_WIDTH);
    int y = (int) (-vector2.getY() * mapHeight / SCREEN_HEIGHT);

    if (x < 0 || x >= mapWidth || y < 0 || y >= mapHeight) {
        return false;
    }
    if (map[y][x] != 0) {
        return false;
    }
    return true;
}

Vector2 Springhawk::Renderer::findMapPoint(Vector2 vector2) {
    double setX = (vector2.getX() * mapWidth / SCREEN_WIDTH);
    double setY = (-vector2.getY() * mapHeight / SCREEN_HEIGHT);

    return {setX, setY};
}



