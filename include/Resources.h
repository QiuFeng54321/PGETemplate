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
        auto files_rb = williamcraft::ResourcePack->GetFileBuffer("resources/audio_files.txt");
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
