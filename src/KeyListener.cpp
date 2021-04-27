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
                states = screen->engine->GetKey(last_key);
            }
            if (it->second.callTime == callTime)
                it->second.func(screen, callTime, data, states.bHeld, states.bPressed, states.bReleased);
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