cmake_minimum_required(VERSION 3.27)
project(SoundStream)

set(CMAKE_CXX_STANDARD 23)

add_executable(SoundStream main.cpp
        includes/menu.h
        includes/menu.cpp
        includes/audio/audio.cpp
        includes/audio/audio.h
        includes/audio/audiobook.h
        includes/audio/podcast.h
        includes/audio/music.h
        includes/genres.h
        includes/audio/audiobook.cpp
)
