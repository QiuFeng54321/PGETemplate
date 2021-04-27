//
// Created by mac on 2021/4/27.
//

#ifndef PGETEST_KEYLISTENER_H
#define PGETEST_KEYLISTENER_H

#include <unordered_map>
#include "olcPixelGameEngine.h"
#include "Screen.h"


#define TIME_AFTER_DRAW 0
#define TIME_BEFORE_DRAW 1
#define TIME_IN_DRAW 2
#define TIME_UNKNOWN -1

namespace williamcraft {
    typedef void(*pred)(Screen* screen, int callTime, void* data, bool held, bool pressed, bool released);

    struct Listener {
        int id;
        int callTime;
        pred func;
        void* data = nullptr;
    };

    class KeyListener {
    public:
        std::unordered_multimap<olc::Key, Listener> keys;
        Screen* screen;
        void Listen(int callTime, void* data);

        void Register(olc::Key key, Listener listener);

        void Unregister(olc::Key key, int id = -1);
    };
    inline KeyListener keyListener;
}

#endif //PGETEST_KEYLISTENER_H
