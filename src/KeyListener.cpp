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

#include "KeyListener.h"
#include "olcPixelGameEngine.h"

namespace williamcraft {
    void KeyListener::Listen(int callTime, void *data) {
        olc::Key last_key;
        olc::HWButton states;
        for (auto it = keys.begin(); it != keys.end(); it++) {
            if (it->first != last_key) {
                last_key = it->first;
                states = engine->GetKey(last_key);
            }
            if (it->second.callTime == callTime)
                it->second.func(screen, callTime, data, states);
        }
    }

    void KeyListener::Register(olc::Key key, Listener listener) {
        keys.insert({key, listener});
    }

    void KeyListener::Unregister(olc::Key key, int id) {
        // Erase all if id = -1
        if (id == -1) keys.erase(key);
        else {
            auto pairs = keys.equal_range(key);
            for (auto it = pairs.first; it != pairs.second; it++) {
                if (it->second.id == id) {
                    keys.erase(it);
                    return;
                }
            }
        }
    }
}