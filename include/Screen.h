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
// Created by mac on 2021/4/26.
//

#ifndef PGETEST_SCREEN_H
#define PGETEST_SCREEN_H

#include <chrono>
#include <olcPixelGameEngine.h>

namespace williamcraft {
    class Screen {
    public:
        std::chrono::time_point<std::chrono::milliseconds> start_time;
        olc::PixelGameEngine* engine;
        float alive_time = 0.;
        bool proposeExit = false;

        Screen(olc::PixelGameEngine* pge);

        virtual bool OnUserCreate();

        virtual bool OnUserUpdate(float elapsedTime);

        virtual bool OnUserDestroy();

        virtual bool Finished();

        virtual Screen* NextScreen();
    };

}

#endif //PGETEST_SCREEN_H
