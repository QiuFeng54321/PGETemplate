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
        Screen(olc::PixelGameEngine* pge);
        virtual bool OnUserCreate();
        virtual bool OnUserUpdate(float elapsedTime);
        virtual bool OnUserDestroy();
        virtual bool Finished();
        virtual Screen* NextScreen();

    };

}

#endif //PGETEST_SCREEN_H
