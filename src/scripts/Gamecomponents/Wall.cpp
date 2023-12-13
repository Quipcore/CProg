#include "components/gamecomponents/Wall.h"

//----------------------------------------------------------------------------------------------------------------------

Wall::Wall(const Vector2& startPosition, const Vector2& endPosition) {
    this->startPosition = startPosition;
    this->endPosition = endPosition;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Wall::getStartPosition() {
    return this->startPosition;
}

//----------------------------------------------------------------------------------------------------------------------

Vector2 Wall::getEndPosition() {
    return  this->endPosition;
}

//----------------------------------------------------------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Wall &wall) {
    os << "(" << wall.startPosition << ", " << wall.endPosition << ")";
    return os;
}

//----------------------------------------------------------------------------------------------------------------------

Wall::Wall(const Wall &wall) {
    this->startPosition = wall.startPosition;
    this->endPosition = wall.endPosition;
}
