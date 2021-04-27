//
// Created by mac on 2021/4/26.
//

#include "ScreenManager.h"

namespace williamcraft {
    void ScreenManager::Start() {
    }
    bool ScreenManager::OnUserUpdate(float elapsedTime) {
        currentScreen->OnUserUpdate(elapsedTime);
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
            keyListener.keys.clear();
        currentScreen = screen;
        keyListener.screen = currentScreen;
        currentScreen->OnUserCreate();
        return true;
    }
}
