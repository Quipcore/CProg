//
// Created by felix on 2023-11-12.
//

#include <iostream>
#include "springhawk/raycaster/Raycaster.h"
#include "Math.h"
#include "springhawk/Input.h"

int Springhawk::Raycaster::SCREEN_WIDTH = 0;
int Springhawk::Raycaster::SCREEN_HEIGHT = 0;
int Springhawk::Raycaster::map[mapWidth][mapHeight];

void Springhawk::Raycaster::render(SDL_Renderer *pRenderer, std::vector<GameObject *> gameobjects, Player *pPlayer,
                                   std::vector<std::vector<int>> map, int screenWidth, int screenHeight) {
    SCREEN_WIDTH = screenWidth;
    SCREEN_HEIGHT = screenHeight;

    for(int x = 0; x < map.size(); x++){
        for(int y = 0; y < map[x].size(); y++){
            Raycaster::map[x][y] = map[x][y];
        }
    }

    //drawMap(pRenderer);
    //drawObjects(pRenderer, gameobjects);
    drawPlayer(pRenderer, pPlayer);
}

void Springhawk::Raycaster::drawMap(SDL_Renderer *pRenderer) {
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

void Springhawk::Raycaster::setRenderDrawColor(SDL_Renderer *pRenderer, int wallValue){
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

void Springhawk::Raycaster::drawObjects(SDL_Renderer *pRenderer, std::vector<GameObject *> &vector) {
    for (auto &gameObject: vector) {
        //Not yet implemented
    }
}

void Springhawk::Raycaster::drawPlayer(SDL_Renderer *pRenderer, Player *const &player) {
    drawRays(pRenderer, player);
}

void Springhawk::Raycaster::drawRays(SDL_Renderer *pRenderer, Player *pPlayer) {
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
    for(int i = -lineCount/2; i < lineCount/2; i++){
        double angle = (fov * (i)/ lineCount) + playerAngle;
        Vector2 direction = {cos(angle), sin(angle)};
        Vector2 endPosition = findEndPosition(playerPosition, direction, radius);

        Vector2 mapPos = findMapPoint(endPosition);
        int mapPointX = (int) mapPos.getX();
        int mapPointY = (int) mapPos.getY();
        setRenderDrawColor(pRenderer, map[mapPointY][mapPointX]);

        double rayMag = (pPlayer->getPosition() - endPosition).magnitude();
        double lineDistance = (rayMag)* 0.5; //Causes div by zero if cos(angle) instead of .5
        double wallHeight = SCREEN_HEIGHT * wallScale/ lineDistance;
        if(wallHeight > SCREEN_HEIGHT){
            wallHeight = SCREEN_HEIGHT;
        }

        bool render2D = Input::bufferContains(Keycode::TAB);
        if(render2D){
            drawMap(pRenderer);
            SDL_SetRenderDrawColor(pRenderer, rayColor.r, rayColor.g, rayColor.b, rayColor.a);
            SDL_RenderDrawLine(pRenderer, playerX, playerY, (int) endPosition.getX(), (int) -endPosition.getY());
        }else{
            int rectX = (lineCount-(i+lineCount/2)) * sliceWidth;
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
Vector2 Springhawk::Raycaster::findEndPosition(Vector2 &position, Vector2 &direction, double maxDistance) {
    double stepSize = 1;
    Vector2 endPosition = position;
    while(isPositionValid(endPosition)){
        endPosition += direction * stepSize;
    }
    return endPosition;
}

Vector2 Springhawk::Raycaster::getIntersectionPoint(Vector2 &position, double angle) {
    return position;
}

bool Springhawk::Raycaster::isPositionValid(Vector2 vector2) {
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

Vector2 Springhawk::Raycaster::findMapPoint(Vector2 vector2) {
    double setX = (vector2.getX() * mapWidth / SCREEN_WIDTH);
    double setY = (-vector2.getY() * mapHeight / SCREEN_HEIGHT);

    return {setX, setY};
}



