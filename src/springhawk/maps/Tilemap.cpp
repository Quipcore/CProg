//
// Created by felix on 2023-11-16.
//

#include <fstream>
#include <iostream>
#include "springhawk/maps/Tilemap.h"
#include "Constants.h"

Tilemap::Tilemap(std::string mapName) {
    loadMap(mapName);
}

void Tilemap::loadMap(std::string &mapName) {

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
        walls.push_back(wall);
        std::cout << wall << std::endl;
    }
}

Wall Tilemap::createWall(std::string &fileLine) {

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
