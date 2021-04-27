//
// Created by mac on 2021/4/27.
//

#include "CustomScreens.h"

namespace williamcraft {
    TestScreen::TestScreen(olc::PixelGameEngine *pge) : Screen(pge) {
    }

    bool TestScreen::OnUserCreate() {
        keyListener.Register(olc::S, {0, TIME_AFTER_DRAW, [](Screen *screen, int, void*, olc::HWButton states) {
            if (states.bReleased) ((TestScreen *) screen)->finished = true;
        }});
        keyListener.Register(olc::A, {0, TIME_IN_DRAW, [](Screen *screen, int, void*, olc::HWButton states) {
            if (states.bHeld) screen->engine->DrawString(30, 30, "A", ((TestScreen*)screen)->col);
        }});
        return true;
    }

    bool TestScreen::OnUserUpdate(float elapsedTime) {
        alive_time += elapsedTime;
        last_updated += elapsedTime;
        if (last_updated > 0.5) {
            col = olc::Pixel(rand() % 256, rand() % 256, rand() % 256);
            last_updated = 0;
        }
        engine->Clear(col.inv());
        engine->DrawRect({5, 5}, {246, 246}, olc::CYAN);
        engine->DrawRect({7, 7}, {242, 242}, olc::CYAN);
        for (int i = 0; i < 16; i += 4)
            engine->DrawCircle({128, 128}, 16 + i, col);
        engine->DrawString(10, 10, "Hello World", col);
        keyListener.Listen(TIME_IN_DRAW, nullptr);
        keyListener.Listen(TIME_AFTER_DRAW, nullptr);
    }

    Screen *TestScreen::NextScreen() {
        return new TestScreen2(engine);
    }

    bool TestScreen::Finished() {
        return finished;
    }

    TestScreen2::TestScreen2(olc::PixelGameEngine *pge) : Screen(pge) {

    }
    bool TestScreen2::OnUserCreate() {
        keyListener.Register(olc::S, {0, TIME_AFTER_DRAW, [](Screen *screen, int, void*, olc::HWButton states) {
            if (states.bReleased) ((TestScreen2 *) screen)->finished = true;
        }});
        keyListener.Register(olc::B, {0, TIME_IN_DRAW, [](Screen *screen, int, void*, olc::HWButton states) {
            if (states.bHeld) screen->engine->DrawString(30, 30, "B", olc::WHITE);
        }});
        return true;
    }

    bool TestScreen2::OnUserUpdate(float elapsedTime) {
        alive_time += elapsedTime;
        last_updated += elapsedTime;
        engine->Clear(olc::BLACK);
        engine->DrawRect({5, 5}, {246, 246}, olc::CYAN);
        engine->DrawRect({7, 7}, {242, 242}, olc::CYAN);
        for (int i = 0; i < 16; i += 5)
            engine->DrawCircle({128, 128}, 16 + i);
        engine->DrawString(10, 10, "Screen2");
        keyListener.Listen(TIME_IN_DRAW, nullptr);
        keyListener.Listen(TIME_AFTER_DRAW, nullptr);
    }

    bool TestScreen2::Finished() {
        return finished;
    }

    Screen *TestScreen2::NextScreen() {
        return new TestScreen(engine);
    }
}
