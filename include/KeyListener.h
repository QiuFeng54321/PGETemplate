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

#ifndef PGETEST_KEYLISTENER_H
#define PGETEST_KEYLISTENER_H

#include <unordered_map>
#include "olcPixelGameEngine.h"
#include "Screen.h"


#define TIME_IN_DRAW 0
#define TIME_GLOB_BEFORE_UPDATE 1
#define TIME_GLOB_AFTER_UPDATE 2
#define TIME_BEFORE_UPDATE 3
#define TIME_AFTER_UPDATE 4
#define TIME_UNKNOWN -1

namespace williamcraft {
    typedef void(*pred)(Screen* screen, int callTime, void* data, olc::HWButton states);

    struct Listener {
        int id;
        int callTime;
        pred func;
        void* data = nullptr;
    };

    class KeyListener {
    public:
        Screen* screen;
        olc::PixelGameEngine* engine;
        std::unordered_multimap<olc::Key, Listener> keys;

        void Listen(int callTime, void* data);

        void Register(olc::Key key, Listener listener);

        void Unregister(olc::Key key, int id = -1);
    };

    inline KeyListener ScreenKeyListener, GlobalKeyListener;
}

#endif //PGETEST_KEYLISTENER_H
