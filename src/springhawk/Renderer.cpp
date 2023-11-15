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
            setRenderDrawColor(pRenderer,map[y][x]);

            xo = x * w;
            yo = y * h;
            SDL_Rect rect = {xo, yo, w - 1, h - 1};
            SDL_RenderFillRect(pRenderer, &rect);
        }
    }
}

void Springhawk::Renderer::setRenderDrawColor(SDL_Renderer *pRenderer,int wallValue){
    switch(wallValue){
        case 1:
            SDL_SetRenderDrawColor(pRenderer, 0xff, 0xff, 0xff, 0xff);
            break;
        case 2:
            SDL_SetRenderDrawColor(pRenderer, 0x00, 0xff, 0x00, 0xff);
            break;
        case 3:
            SDL_SetRenderDrawColor(pRenderer,0x00,0x00,0xff,0xff);
            break;
        case 4:
            SDL_SetRenderDrawColor(pRenderer,0xff,0xff,0x00,0xff);
            break;
        case 5:
            SDL_SetRenderDrawColor(pRenderer,0xff,0x00,0xff,0xff);
            break;
        default:
            SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xff);
            break;
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
    const double sliceWidth = SCREEN_WIDTH / lineCount;
    const double fov = M_PI/2;
    const double playerAngle = pPlayer->getAngle();
    const double wallScale = SCREEN_HEIGHT/16;
    const Color rayColor = {0xff, 0, 0, 0xff};

    Vector2 playerPosition = pPlayer->getPosition();
    int playerX = (int) playerPosition.getX();
    int playerY = (int) -playerPosition.getY();

    SDL_SetRenderDrawColor(pRenderer, rayColor.r, rayColor.g, rayColor.b, rayColor.a);
    for(int i = 0; i <= lineCount; i++){

        double angle = (fov * i / lineCount) + playerAngle;
        Vector2 direction = {cos(angle), sin(angle)};
        Vector2 endPosition = findEndPosition(playerPosition, direction, radius);

        Vector2 mapPos = findMapPoint(endPosition);
        int mapPointX = (int) mapPos.getX();
        int mapPointY = (int) mapPos.getY();
        setRenderDrawColor(pRenderer, map[mapPointY][mapPointX]);

        double rayMag = (pPlayer->getPosition() - endPosition).magnitude();
        double lineDistance = (rayMag)* 0.5; //Causes div by zero if cos(angle) instead of .5
        double wallHeight = SCREEN_HEIGHT * wallScale / lineDistance;
        if(wallHeight > SCREEN_HEIGHT){
            wallHeight = SCREEN_HEIGHT;
        }
        if(i == 0){
            std::cout << rayMag << " " << lineDistance <<" "<< wallHeight << std::endl;
        }

        bool render2D = Input::bufferContains(Keycode::TAB);
        if(render2D){
            drawMap(pRenderer);
            SDL_SetRenderDrawColor(pRenderer, rayColor.r, rayColor.g, rayColor.b, rayColor.a);
            SDL_RenderDrawLine(pRenderer, playerX, playerY, (int) endPosition.getX(), (int) -endPosition.getY());
        }else{
            int rectX = (lineCount-i) * sliceWidth;
            int rectY = (SCREEN_HEIGHT - wallHeight) / 2;
            SDL_Rect rect = {rectX,rectY,(int)sliceWidth,(int)wallHeight};

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



