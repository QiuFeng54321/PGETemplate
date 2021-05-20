//     <one line to give the program's name and a brief idea of what it does.>
//     Copyright (C) 2021  Qiufeng54321
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by mac on 2021/4/27.
//

#include "CustomScreens.h"
#include "Resources.h"
#include "Sounds.h"

namespace williamcraft {
    TestScreen::TestScreen(olc::PixelGameEngine *pge) : Screen(pge) {
    }

    bool TestScreen::OnUserCreate() {
        str = "Hi /";
        // Init sound
        auto sound = williamcraft::SoundEngine->play2D("resources/highway_cruisin.mp3", false, true);
        sound_id = williamcraft::append_sound(sound);
        ScreenKeyListener.Register(olc::S, {0, TIME_AFTER_UPDATE, [](Screen *screen, int, void*, olc::HWButton states) {
            if (states.bReleased) ((TestScreen *) screen)->finished = true;
        }});
        ScreenKeyListener.Register(olc::A, {0, TIME_IN_DRAW, [](Screen *screen, int, void*, olc::HWButton states) {
            if (states.bHeld) screen->engine->DrawString(30, 30, "A", ((TestScreen*)screen)->col);
            if (states.bReleased) {
                auto sound = williamcraft::get_sound(((TestScreen*)screen)->sound_id);
                sound->setIsPaused(!sound->getIsPaused());
            }
        }});
        ScreenKeyListener.Register(olc::A, {0, TIME_IN_DRAW, [](Screen *screen, int, void*, olc::HWButton states) {
            if (states.bHeld) screen->engine->DrawString(60, 30, "Another A", ((TestScreen*)screen)->col);
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
        engine->DrawString(10, 20, str, col);
        ScreenKeyListener.Listen(TIME_IN_DRAW, nullptr);
    }

    Screen *TestScreen::NextScreen() {
        williamcraft::remove_sound(sound_id);
        return new TestScreen2(engine);
    }

    bool TestScreen::Finished() {
        return finished;
    }

    TestScreen2::TestScreen2(olc::PixelGameEngine *pge) : Screen(pge) {

    }

    bool TestScreen2::OnUserCreate() {
        ScreenKeyListener.Register(olc::S, {0, TIME_AFTER_UPDATE, [](Screen *screen, int, void*, olc::HWButton states) {
            if (states.bReleased) ((TestScreen2 *) screen)->finished = true;
        }});
        ScreenKeyListener.Register(olc::B, {0, TIME_IN_DRAW, [](Screen *screen, int, void*, olc::HWButton states) {
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
        ScreenKeyListener.Listen(TIME_IN_DRAW, nullptr);
    }

    bool TestScreen2::Finished() {
        return finished;
    }

    Screen *TestScreen2::NextScreen() {
        return new TestScreen(engine);
    }
}
