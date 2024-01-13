#ifndef PLAY_PACMAN_H
#define PLAY_PACMAN_H

#include "games/Game.h"

class PacMan : public Game {

public:
    PacMan() = default;
    ~PacMan() override = default;

    void run() override;
};

#endif //PLAY_PACMAN_H
