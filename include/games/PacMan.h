//
// Created by felix on 2023-11-26.
//

#ifndef PLAY_PACMAN_H
#define PLAY_PACMAN_H

#include "games/Game.h"

class PacMan : public Game {

public:
    PacMan() = default;
    ~PacMan() = default;

    void run() override;
};

#endif //PLAY_PACMAN_H
