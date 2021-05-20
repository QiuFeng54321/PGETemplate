cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME PGETemplate)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        src/Screen.cpp
        src/ScreenManager.cpp
        src/KeyListener.cpp src/CustomScreens.cpp src/Resources.cpp)
set(INCLUDES ${IRRKLANG_INCLUDE_FILES}
        include/Screen.h
        include/ScreenManager.h
        include/KeyListener.h include/CustomScreens.h include/Resources.h include/irrKlangResourceFileFactory.h include/Sounds.h)

add_executable(${PROJECT_NAME} include/olcPixelGameEngine.h src/olcPixelGameEngine.cpp ${SOURCES} ${INCLUDES} main.cpp)
add_executable(PGEPack include/olcPixelGameEngine.h src/olcPixelGameEngine.cpp ResourcePackCreator.cpp)

set(IRRKLANG_DIR ${PROJECT_SOURCE_DIR}/irrKlang)
message("irrKlang Dir: ${IRRKLANG_DIR}")
message("Dynamic lib suffix: ${CMAKE_SHARED_LIBRARY_SUFFIX}")

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    set(IRRKLANG_LINK_DIR "${IRRKLANG_DIR}/bin/macosx-gcc")

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND install_name_tool -change /usr/local/lib/libikpFLAC.dylib @executable_path/ikpFLAC.dylib ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
            COMMAND install_name_tool -change /usr/local/lib/libikpMP3.dylib @executable_path/ikpMP3.dylib ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
            COMMAND install_name_tool -change /usr/local/lib/libirrklang.dylib @executable_path/irrKlang.dylib ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Changing lib paths (MacOS Specific)"
            )
elseif (CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
    set(IRRKLANG_LINK_DIR -L${IRRKLANG_DIR}/bin/linux-gcc-64)
elseif (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
    set(IRRKLANG_LINK_DIR -L${IRRKLANG_DIR}/bin/winx64-visualStudio)
endif ()

file(GLOB IRRKLANG_LIBS "${IRRKLANG_LINK_DIR}/*${CMAKE_SHARED_LIBRARY_SUFFIX}")

set(IRRKLANG_INCLUDE ${IRRKLANG_DIR}/include)
file(GLOB IRRKLANG_INCLUDE_FILES "${IRRKLANG_INCLUDE}/*.h")

message("irrKlang libs path: ${IRRKLANG_LIBS}, includes: ${IRRKLANG_INCLUDE}")
message("system lib: ${LD_LIBRARY_PATH}")

find_library(GL OpenGL)
find_library(PNG png)
find_library(GLUT glut)

include_directories(include /usr/local/include/)
include_directories(${IRRKLANG_INCLUDE})

link_directories("${IRRKLANG_LINK_DIR}")
link_libraries("${IRRKLANG_LIBS}")


target_link_libraries(PGEPack ${PNG} ${GLUT} ${GL})

target_link_libraries(PGETemplate ${PNG} ${GLUT} ${GL} ${IRRKLANG_LIBS})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${IRRKLANG_LINK_DIR}/irrKlang${CMAKE_SHARED_LIBRARY_SUFFIX} ${CMAKE_BINARY_DIR}/
        COMMAND ${CMAKE_COMMAND} -E copy ${IRRKLANG_LINK_DIR}/ikpMP3${CMAKE_SHARED_LIBRARY_SUFFIX} ${CMAKE_BINARY_DIR}/
        COMMAND ${CMAKE_COMMAND} -E copy ${IRRKLANG_LINK_DIR}/ikpFLAC${CMAKE_SHARED_LIBRARY_SUFFIX} ${CMAKE_BINARY_DIR}/
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Changing lib paths"
        )

file(GLOB RESOURCES_AUDIO_FILES RELATIVE ${PROJECT_SOURCE_DIR} "resources/*.mp3")
string (REPLACE ";" "\n" RESOURCES_AUDIO_FILES "${RESOURCES_AUDIO_FILES}")
file(WRITE resources/audio_files.txt "${RESOURCES_AUDIO_FILES}")
