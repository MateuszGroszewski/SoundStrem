#include "audio.h"
#include <iostream>

std::vector<Audio*> audio_stream;

void Audio::show() const {
    std::cout << creator;
}

AudioBookGenre Audio::getAudioBookGenre() const {
    return audioBookGenre;
}

PodcastGenre Audio::getPodcastGenre() const {
    return podcastGenre;
}

MusicGenre Audio::getMusicGenre() const {
    return musicGenre;
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
