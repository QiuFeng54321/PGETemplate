#include "olcPixelGameEngine.h"
#include "ScreenManager.h"
#include "CustomScreens.h"
#include <chrono>

class Game : public olc::PixelGameEngine {
    float last_updated = 0;
    williamcraft::ScreenManager manager;
public:
    Game() {
        sAppName = "Game";
        williamcraft::GlobalKeyListener.engine = this;
        williamcraft::GlobalKeyListener.Register(olc::ESCAPE, {0, TIME_GLOB_BEFORE_UPDATE, [](williamcraft::Screen*, int, void*, olc::HWButton states){
            if (states.bReleased)
                exit(0);
        }});
        manager.Start();
    }

public:
    bool OnUserCreate() override {
        // Called once at the start, so create things here
        manager.SetScreen(new williamcraft::TestScreen(this));
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        williamcraft::GlobalKeyListener.Listen(TIME_GLOB_BEFORE_UPDATE, nullptr);
        manager.OnUserUpdate(fElapsedTime);
        williamcraft::GlobalKeyListener.Listen(TIME_GLOB_AFTER_UPDATE, nullptr);
        return true;
    }
};


int main() {
    Game demo;
    if (demo.Construct(256, 256, 3, 3))
        demo.Start();

    return 0;
}