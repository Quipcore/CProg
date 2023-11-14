//
// Created by felix on 2023-11-12.
//

#ifndef CPROG_PROJECT_TIME_H
#define CPROG_PROJECT_TIME_H

class Time {

protected:
    static void setDeltaTime(double dt);

public:
    friend class Engine;
    static double getDeltaTime();
private:
    static double deltaTime;
};


#endif //CPROG_PROJECT_TIME_H
