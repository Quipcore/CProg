#include "springhawk/maps/Sectormap.h"

bool springhawk::SectorMap::isOutOfBounds(Vector2 &position) {
    return false;
}

Vector2 springhawk::SectorMap::getValidPos() {
    return Vector2();
}

int springhawk::SectorMap::operator[](Vector2 vector2) {
    return 0;
}

int springhawk::SectorMap::getWidth() {
    return 0;
}

int springhawk::SectorMap::getHeight() {
    return 0;
}
