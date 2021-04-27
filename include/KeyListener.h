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
