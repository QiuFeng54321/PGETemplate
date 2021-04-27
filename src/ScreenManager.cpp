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
