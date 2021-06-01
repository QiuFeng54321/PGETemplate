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
// Created by mac on 2021/4/28.
//

#ifndef PGETEST_RESOURCES_H
#define PGETEST_RESOURCES_H

#include "olcPixelGameEngine.h"
#include "Sounds.h"
#include <sstream>
#include <string>
#include <iostream>

namespace williamcraft {
    inline olc::ResourcePack *ResourcePack;

    inline void load_all_resource_sounds() {
        auto files_rb = williamcraft::ResourcePack->GetFileBuffer("audio_files.txt");
        auto files_rb_mem = files_rb.vMemory;
        std::stringstream ss;
        std::copy(files_rb_mem.begin(), files_rb_mem.end(), std::ostream_iterator<char>(ss, ""));
        std::string str;
        while (std::getline(ss, str)) {
            auto rb = williamcraft::ResourcePack->GetFileBuffer(str);
            auto rbmem = rb.vMemory;
            auto source = williamcraft::SoundEngine->addSoundSourceFromMemory(rbmem.data(), rbmem.size(), str.c_str());
            source->setStreamMode(irrklang::ESM_NO_STREAMING);
            source->setForcedStreamingThreshold(0);
            std::cout << "Loaded " << str << " as sound source" << std::endl;
        }
    }
}

#endif //PGETEST_RESOURCES_H
