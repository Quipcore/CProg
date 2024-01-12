#include "springhawk/Audio.h"
#include "algorithm"
#include "Constants.h"
#include <limits>


std::vector<Audio*> Audio::audioDrivers = {};

Audio::Audio(std::string &path, bool loop) {
    this->loop = loop;
    audioDrivers.push_back(this);

    Mix_Chunk* chunkA = Mix_LoadWAV(path.c_str());

    tracks.push_back(chunkA);
    Mix_PlayChannel(1,chunkA,-1);
}

Audio::~Audio() {

    for(Mix_Chunk* track: tracks){

        bool trackContainedElsewhere = false;

        for(Audio* audio: audioDrivers){
            if(audio->contains(track)){
                trackContainedElsewhere = true;
            }
        }

        if(!trackContainedElsewhere){
            Mix_FreeChunk(track);
        }
    }

}

bool Audio::contains(Mix_Chunk *pChunk) {
    return std::any_of(tracks.begin(), tracks.end(), [pChunk](Mix_Chunk* track) {
        return pChunk == track;
    });
}

void Audio::start() {
    for(Mix_Chunk* chunk : tracks){
        Mix_PlayChannel(channel,chunk,loop);
    }
}

void Audio::stop() {
    Mix_HaltChannel(channel);
}

void Audio::pause() {
    Mix_Pause(channel);
}

void Audio::setLoop(bool loop) {
    this->loop = loop;
}

bool Audio::getLoop() {
    return loop;
}

void Audio::resume() {
    Mix_Resume(channel);
}