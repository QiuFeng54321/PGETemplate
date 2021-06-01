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
// Created by mac on 2021/4/27.
//

#ifndef PGETEST_CUSTOMSCREENS_H
#define PGETEST_CUSTOMSCREENS_H

#include "olcPixelGameEngine.h"
#include "Screen.h"
#include "KeyListener.h"
#include <string>

namespace williamcraft {
    class TestScreen : public Screen {
    public:
        std::string str;
        int sound_id{};
        olc::Pixel col;
        std::unique_ptr<olc::Sprite> sprite;
        float last_updated = 0.;
        bool finished = false;

        explicit TestScreen(olc::PixelGameEngine *pge);

        bool OnUserCreate() override;

        bool OnUserUpdate(float elapsedTime) override;

        bool Finished() override;

        Screen * NextScreen() override;
    };

    class TestScreen2 : public Screen {
    public:
        float last_updated = 0.;
        bool finished = false;

        explicit TestScreen2(olc::PixelGameEngine *pge);

        bool OnUserCreate() override;

        bool OnUserUpdate(float elapsedTime) override;

        bool Finished() override;

        Screen * NextScreen() override;
    };
}

#endif //PGETEST_CUSTOMSCREENS_H
