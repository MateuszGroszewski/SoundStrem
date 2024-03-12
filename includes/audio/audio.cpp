#include "audio.h"
#include <iostream>

std::vector<Audio*> audio_stream;

void Audio::show() const {
    std::cout << creator;
}

AudioType Audio::getType() const {
    return type;
}

std::string Audio::getCreator() const {
    return creator;
}

std::string Audio::getTitle() const {
    return title;
}

std::vector<std::string> Audio::getGenre() const {
    return genre;
}

std::vector<std::string> Audio::getFeat() const {
    return feat;
}
