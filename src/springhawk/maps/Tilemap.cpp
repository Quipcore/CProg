//
// Created by felix on 2023-11-16.
//

#include <fstream>
#include <iostream>
#include "springhawk/maps/Tilemap.h"
#include "Constants.h"

springhawk::Tilemap::Tilemap(std::string mapName) {
    this->walls = new std::vector<Wall*>;
    loadMap(mapName);
}

springhawk::Tilemap::Tilemap(std::vector<std::vector<int>> vector1) {
    mapVector = &vector1;
    this->walls = new std::vector<Wall*>;
}

void springhawk::Tilemap::loadMap(std::string &mapName) {

    std::string FilePath = constants::gMapPath + mapName;
    std::ifstream mapFile;
    mapFile.open(FilePath, std::ios::in);
    if(!mapFile.is_open()){
        std::cout << "Could not open file: " << FilePath << std::endl;
        return;
    }
    bool readingComment = false;
    while(!mapFile.eof()) {
        std::string line;
        std::getline(mapFile, line);

        if (line == "/*") {
            readingComment = true;
            continue;
        }

        if (line == "*/") {
            readingComment = false;
            continue;
        }

        if (readingComment || line.empty() || (line[0] == '/' && line[1] == '/') || line[0] == '\n'){
            continue;
        }

        Wall wall = createWall(line);

        walls->push_back(new Wall(wall));
        std::cout << wall << std::endl;
    }
}

Wall springhawk::Tilemap::createWall(std::string &fileLine) {

    for(int i = 0 ; i < fileLine.length() ; i++){
        if(fileLine[i] == '-'){
            std::string startPositionString = fileLine.substr(0, i);
            std::string endPositionString = fileLine.substr(i + 1, fileLine.length() - i - 1);

            Vector2 startPosition = Vector2::parse(startPositionString);
            Vector2 endPosition = Vector2::parse(endPositionString);

            return {startPosition, endPosition};
        }
    }

    return {Vector2::zero, Vector2::zero};
}

bool springhawk::Tilemap::isOutOfBounds(Vector2 &position) {
    return false;
}

Vector2 springhawk::Tilemap::getValidPos() {
    return Vector2();
}

int springhawk::Tilemap::operator[](Vector2 vector2) {
    return 0;
}

int springhawk::Tilemap::getWidth() {
    return 0;
}

int springhawk::Tilemap::getHeight() {
    return 0;
}


