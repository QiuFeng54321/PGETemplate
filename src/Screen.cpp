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
