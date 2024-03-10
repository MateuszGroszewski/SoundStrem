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



void Sound::fullSearch() const {
    std::cout << artist << " - " << title << " : " << genre << std::endl;
}

void AudioBook::fullSearch() const {
    std::cout << artist << " - " << title << " : " << genre << std::endl;
}

void Podcast::fullSearch() const {
    std::cout << artist << " - " << title << std::endl << "Genre: " << genre << std::endl << std::endl;
}

void Music::fullSearch() const {
    std::cout << artist << " - " << title << std::endl << std::endl;
}



void Sound::titleSearch() const {
    std::cout << title << " - " << artist << std::endl;
}

void AudioBook::titleSearch() const {
    std::cout << title << " - " << artist << std::endl;
}

void Podcast::titleSearch() const {
    std::cout << title << " - " << artist << std::endl;
}

void Music::titleSearch() const {
    std::cout << title << " - " << artist << std::endl;
}