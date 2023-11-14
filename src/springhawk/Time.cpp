//
// Created by felix on 2023-11-12.
//

#include "springhawk/Time.h"

double Time::deltaTime = 0;

double Time::getDeltaTime() {
    return deltaTime;
}

void Time::setDeltaTime(double dt) {
    deltaTime = dt;
}