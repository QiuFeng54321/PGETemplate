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
        manager.Start();
    }

public:
    bool OnUserCreate() override {
        // Called once at the start, so create things here
        manager.SetScreen(new williamcraft::TestScreen(this));
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        manager.OnUserUpdate(fElapsedTime);
        return true;
    }
};


int main() {
    Game demo;
    if (demo.Construct(256, 256, 3, 3))
        demo.Start();

    return 0;
}