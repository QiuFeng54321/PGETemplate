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

#include "olcPixelGameEngine.h"
#include "Resources.h"
#include "ScreenManager.h"
#include "CustomScreens.h"
#include "irrKlang.h"
#include "irrKlangResourceFileFactory.h"
#include "Sounds.h"
#include <chrono>
#include <string>

class Game : public olc::PixelGameEngine {
    float last_updated = 0;
    williamcraft::ScreenManager manager;
public:
    Game() {
        sAppName = "Game";
        williamcraft::GlobalKeyListener.engine = this;
        williamcraft::GlobalKeyListener.Register(olc::ESCAPE, {0, TIME_GLOB_BEFORE_UPDATE, [](williamcraft::Screen*, int, void*, olc::HWButton states){
            if (states.bReleased) {
                // Release
                williamcraft::clear_sounds();
                exit(0);
            }
        }});
        manager.Start();
    }

public:
    bool OnUserCreate() override {
        // Called once at the start, so create things here
        manager.SetScreen(new williamcraft::TestScreen(this));
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        williamcraft::GlobalKeyListener.Listen(TIME_GLOB_BEFORE_UPDATE, nullptr);
        manager.OnUserUpdate(fElapsedTime);
        williamcraft::GlobalKeyListener.Listen(TIME_GLOB_AFTER_UPDATE, nullptr);
        return true;
    }
};


int main() {
    williamcraft::SoundEngine = irrklang::createIrrKlangDevice();
    if (!williamcraft::SoundEngine)
        std::cout << "Failed to initialize the engine" << std::endl; // error starting up the engine
    auto factory = new irrKlangResourceFileFactory();


//    williamcraft::SoundEngine->addFileFactory(factory);
    std::filesystem::current_path("/Users/mac/Documents/VSCProjects/PGETemplate/");
    std::string key;

    williamcraft::ResourcePack = new olc::ResourcePack();
    williamcraft::ResourcePack->LoadPack("ResourcePack.dat", key);
    williamcraft::load_all_resource_sounds();
    Game demo;
    if (demo.Construct(256, 256, 3, 3))
        demo.Start();

    return 0;
}