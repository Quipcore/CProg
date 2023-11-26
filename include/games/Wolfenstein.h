//
// Created by felix on 2023-11-14.
//

#ifndef CPROG_PROJECT_WOLFENSTEIN_H
#define CPROG_PROJECT_WOLFENSTEIN_H

#include "games/Game.h"

class Wolfenstein : public Game{
public:
    Wolfenstein() = default;
    ~Wolfenstein() = default;

    void run() override;
};

//class Wolfenstein{
//public:
//    Wolfenstein() = default;
//    ~Wolfenstein() = default;
//
//    void run();
//};


#endif //CPROG_PROJECT_WOLFENSTEIN_H
