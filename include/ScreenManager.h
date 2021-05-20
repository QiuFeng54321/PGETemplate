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

#ifndef PGETEST_SCREENMANAGER_H
#define PGETEST_SCREENMANAGER_H

#include "Screen.h"
#include "KeyListener.h"
#include <chrono>

namespace williamcraft {
    class ScreenManager {
    public:
        std::chrono::time_point<std::chrono::milliseconds> start_time;
        Screen* currentScreen;

        void Start();

        bool OnUserUpdate(float elapsedTime);

        bool NextScreen();

        bool SetScreen(Screen* screen);
    };
}

#endif //PGETEST_SCREENMANAGER_H
