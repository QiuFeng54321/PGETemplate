//
// Created by mac on 2021/5/20.
//

#ifndef PGETEMPLATE_SOUNDS_H
#define PGETEMPLATE_SOUNDS_H

#include "irrKlang.h"
#include <vector>
#include <iostream>

namespace williamcraft {
    inline irrklang::ISoundEngine* SoundEngine = irrklang::createIrrKlangDevice();
    inline std::vector<irrklang::ISound*> Sounds;
    inline int append_sound(irrklang::ISound* sound) {
        Sounds.push_back(sound);
        int id = Sounds.size() - 1;
        std::cout << "Requested sound id " << id << " for source " << sound->getSoundSource()->getName() << std::endl;
        return id;
    }
    inline irrklang::ISound* get_sound(int id) {
        auto sound = Sounds[id];
        std::cout << "Sound " << id << "(" << sound->getSoundSource()->getName() << ") requested" << std::endl;
        return sound;
    }
    inline void release_sound(irrklang::ISound* sound) {
        sound->stop();
        sound->drop();
    }
    inline void remove_sound(int id) {
        auto sound = get_sound(id);
        release_sound(sound);
        Sounds.erase(Sounds.begin() + id);
        std::cout << "Removed sound " << id << "(" << sound->getSoundSource()->getName() << ")" << std::endl;
    }
    inline void clear_sounds() {
        for (auto sound : Sounds) {
            release_sound(sound);
            std::cout << "Force removed sound " << sound->getSoundSource()->getName() << std::endl;
        }
        Sounds.clear();
    }
}

#endif //PGETEMPLATE_SOUNDS_H
