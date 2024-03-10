#include "headers/sound.h"
#include <iostream>

std::vector <Sound*> sound_stream;

bool Sound::containsSubstring(const std::string &str, const std::string &substr) {
    return str.find(substr) != std::string::npos;
}

std::string Sound::getArtist() const {
    return artist;
}

std::string Sound::getTitle() const {
    return title;
}

std::string Sound::getGenre() const {
    return genre;
}

void Sound::search() const {
    std::cout << artist << " - " << title << " : " << genre << std::endl;
}

void AudioBook::search() const {
    std::cout << artist << " - " << title << " : " << genre << std::endl;
}

void Podcast::search() const {
    std::cout << artist << " - " << title << std::endl << "Genre: " << genre << std::endl << std::endl;
}

void Music::search() const {
    std::cout << artist << " - " << title << std::endl << std::endl;
}
