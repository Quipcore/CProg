#include <iostream>
#include "components/gamecomponents/TeleportPad.h"

TeleportPad::TeleportPad(Vector2 vector2) {
    this->position = vector2;
    this->texturePath = "temp.png";
    this->tag = "teleport";
    this->objectIsTrigger = true;
}

void TeleportPad::setAnchor(GameObject *gameObject, Vector2 offset) {
    this->offset = offset;
    this->anchor = gameObject;
}

void TeleportPad::onCollision(GameObject &other) {
    if(other.getTag() == "Empty"){
        return;
    }
    Vector2 teleportPos = anchor->getPosition() + offset;
    std::cout << other.getTag() << " = "<<teleportPos << std::endl;
    other.setPosition(teleportPos);
}
