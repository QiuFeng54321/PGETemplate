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
