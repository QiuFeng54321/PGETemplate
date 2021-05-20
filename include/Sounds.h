//     <one line to give the program's name and a brief idea of what it does.>
//     Copyright (C) 2021  Qiufeng54321
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by mac on 2021/5/20.
//

#ifndef PGETEMPLATE_SOUNDS_H
#define PGETEMPLATE_SOUNDS_H

#include "irrKlang.h"
#include <vector>
#include <iostream>

namespace williamcraft {
    inline irrklang::ISoundEngine *SoundEngine;
    inline std::vector<irrklang::ISound *> Sounds;

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
