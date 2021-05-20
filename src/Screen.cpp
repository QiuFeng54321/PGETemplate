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

#include "Screen.h"

#include <system_error>

namespace williamcraft {
    Screen::Screen(olc::PixelGameEngine *pge) : engine(pge) {
    }

    bool Screen::OnUserCreate() {
        return true;
    }

    bool Screen::OnUserUpdate(float elapsedTime) {
        alive_time += elapsedTime;
        return true;
    }

    bool Screen::OnUserDestroy() {
        return true;
    }

    bool Screen::Finished() {
        return false;
    }

    Screen *Screen::NextScreen() {
        throw std::runtime_error("NextScreen not set");
    }


}
