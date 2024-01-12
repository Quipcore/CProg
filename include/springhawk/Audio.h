//
// Created by felix on 2024-01-12.
//

#ifndef CPROG_PROJECT_AUDIO_H
#define CPROG_PROJECT_AUDIO_H

#include <string>
#include <vector>
#include "SDL_mixer.h"

class Audio {
public:
    Audio() = delete;
    Audio(std::string& ,bool);
    ~Audio();

    void start();
    void stop();
    void pause();
    void resume();
    void setLoop(bool);
    bool getLoop();

private:

    static std::vector<Audio*> audioDrivers; //Name?
    std::vector<Mix_Chunk*> tracks;
    bool loop;
    int channel = -1;

    bool contains(Mix_Chunk *pMusic);
};


#endif //CPROG_PROJECT_AUDIO_H
