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
// Created by mac on 2021/4/26.
//

#include "ScreenManager.h"

namespace williamcraft {
    void ScreenManager::Start() {
    }

    bool ScreenManager::OnUserUpdate(float elapsedTime) {
        ScreenKeyListener.Listen(TIME_BEFORE_UPDATE, nullptr);
        currentScreen->OnUserUpdate(elapsedTime);
        ScreenKeyListener.Listen(TIME_AFTER_UPDATE, nullptr);
        if (currentScreen->proposeExit)
            exit(0);
        if (currentScreen->Finished())
            NextScreen();
        return true;
    }

    bool ScreenManager::NextScreen() {
        Screen* newScreen = currentScreen->NextScreen();
        SetScreen(newScreen);
        return true;
    }

    bool ScreenManager::SetScreen(Screen *screen) {
        if (currentScreen != nullptr)
            currentScreen->OnUserDestroy();
        ScreenKeyListener.keys.clear();
        currentScreen = screen;
        ScreenKeyListener.screen = currentScreen;
        ScreenKeyListener.engine = currentScreen->engine;
        currentScreen->OnUserCreate();
        return true;
    }
}
