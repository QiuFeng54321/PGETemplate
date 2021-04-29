cmake_minimum_required(VERSION 3.17)
project(PGETemplate)

set(CMAKE_CXX_STANDARD 17)
find_library(GL OpenGL)
find_library(PNG png)
find_library(GLUT glut)

include_directories(include /usr/local/include/)
link_directories(/usr/local/lib/)

set(SOURCES
        src/Screen.cpp
        src/ScreenManager.cpp
        src/KeyListener.cpp src/CustomScreens.cpp src/Resources.cpp)
set(INCLUDES
        include/Screen.h
        include/ScreenManager.h
        include/KeyListener.h include/CustomScreens.h include/Resources.h)

add_executable(PGETemplate include/olcPixelGameEngine.h src/olcPixelGameEngine.cpp ${SOURCES} ${INCLUDES} main.cpp)
add_executable(PGEPack include/olcPixelGameEngine.h src/olcPixelGameEngine.cpp ResourcePackCreator.cpp)

target_link_libraries(PGEPack ${PNG} ${GLUT} ${GL})

target_link_libraries(PGETemplate ${PNG} ${GLUT} ${GL})