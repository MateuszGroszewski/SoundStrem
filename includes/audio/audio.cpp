#include "audio.h"
#include <iostream>

std::vector<Audio*> audio_stream;

void Audio::show() const {
    std::cout << creator;
}

GenreType Audio::getGenre() const {
    return genre;
}

std::string Audio::getCreator() const {
    return creator;
}

std::string Audio::getTitle() const {
    return title;
}

std::vector<std::string> Audio::getFeat() const {
    return feat;
}

