//
// Created by felix on 2024-01-13.
//

#ifndef CPROG_PROJECT_TELEPORTPAD_H
#define CPROG_PROJECT_TELEPORTPAD_H


#include "springhawk/Vector2.h"
#include "components/gamecomponents/GameObject.h"

class TeleportPad : public GameObject{

public:
    explicit TeleportPad(Vector2 vector2);
    ~TeleportPad() override = default;

    void setAnchor(GameObject *gameObject, Vector2 offset);
    void onCollision(GameObject& other) override;

private:
    Vector2 offset;
    GameObject* anchor; //Usually another teleport pad
};


#endif //CPROG_PROJECT_TELEPORTPAD_H
