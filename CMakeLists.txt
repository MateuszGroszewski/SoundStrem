cmake_minimum_required(VERSION 3.27)
project(SoundStream)

set(CMAKE_CXX_STANDARD 23)

add_executable(SoundStream main.cpp
        headers/menu.h
        menu.cpp
        sound.cpp
        headers/sound.h
        enums.cpp
        headers/creation.h
)
