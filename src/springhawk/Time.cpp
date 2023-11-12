//
// Created by felix on 2023-11-12.
//

#include "springhawk/Time.h"

float Time::deltaTime = 0;

float Time::getDeltaTime() {
    return deltaTime;
}

void Time::setDeltaTime(float dt) {
    deltaTime = dt;
}