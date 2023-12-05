//
// Created by felix on 2023-11-26.
//

#ifndef PLAY_WALL_H
#define PLAY_WALL_H

#include "springhawk/Vector2.h"

class Wall {
public:
    Wall(const Vector2& startPosition, const Vector2& endPosition);
    ~Wall() = default;

    Vector2 getStartPosition();
    Vector2 getEndPosition();

    friend std::ostream& operator<<(std::ostream& os, const Wall& wall);
private:
    Vector2 startPosition;
    Vector2 endPosition;
};

#endif //PLAY_WALL_H
