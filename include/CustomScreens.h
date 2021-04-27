//
// Created by mac on 2021/4/27.
//

#ifndef PGETEST_CUSTOMSCREENS_H
#define PGETEST_CUSTOMSCREENS_H

#include "olcPixelGameEngine.h"
#include "Screen.h"
#include "KeyListener.h"

namespace williamcraft {
    class TestScreen : public Screen {
    public:
        olc::Pixel col;
        float last_updated = 0.;
        bool finished = false;
        TestScreen(olc::PixelGameEngine* pge);
        bool OnUserCreate() override;
        bool OnUserUpdate(float elapsedTime) override;
        bool Finished() override;
        Screen * NextScreen() override;
    };
    class TestScreen2 : public Screen {
    public:
        float last_updated = 0.;
        bool finished = false;
        TestScreen2(olc::PixelGameEngine* pge);
        bool OnUserCreate() override;
        bool OnUserUpdate(float elapsedTime) override;
        bool Finished() override;
        Screen * NextScreen() override;
    };
}

#endif //PGETEST_CUSTOMSCREENS_H
