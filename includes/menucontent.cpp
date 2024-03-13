#include "menucontent.h"
#include "audio/audio.h"
#include "audio/music.h"
#include "audio/podcast.h"
#include "genres.h"
#include <iostream>

int MenuContent::mainMenu(){
    int option;
    std::cout << "     Main Menu     " << std::endl;
    std::cout << "1. Search" << std::endl;
    std::cout << "2. Add" << std::endl;
    std::cout << "3. Remove" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Select option from above: ";
    std::cin >> option;
    std::cout << std::endl;
    return  option;
}

int MenuContent::searchMenu() {
    int option;
    std::cout << "   Search Menu   " << std::endl;
    std::cout << "Search by: " << std::endl;
    std::cout << "1. Type" << std::endl;
    std::cout << "2. Artist " << std::endl;
    std::cout << "3. Title" << std::endl;
    std::cout << "4. Genre" << std::endl;
    std::cout << "0. Back to main menu " << std::endl;
    std::cout << "Select option from above: ";
    std::cin >> option;
    std::cout << std::endl << std::endl << std::endl;
    return  option;
}

void MenuContent::searchByType(int type) {

    switch (type){
        case 1:{
            std::cout << "Musics" << std::endl << std::endl;
            for (const auto& audio : audio_stream) {
                if (auto* music = dynamic_cast<Music*>(audio)) {
                    std::cout << "[" << getGenreName(music->getGenre()) << "] ";
                    std::cout << music->getCreator() << " - " << music->getTitle();
                    if (!music->getFeat().empty()) {
                        std::cout << "Feat: ";
                        for (const auto &feat: music->getFeat()) {
                            std::cout << feat << ", ";
                        }
                    }
                    std::cout << std::endl << std::endl << std::endl;
                }

            }

            break;
        }

        case 2:{
            std::cout << "Podcasts" << std::endl;
            for (const auto& audio : audio_stream) {
                if (auto* podcast = dynamic_cast<Podcast*>(audio)) {
                    std::cout << "[" << getGenreName(podcast->getGenre()) << "] ";
                    std::cout << podcast->getCreator() << " - " << podcast->getTitle();
                    if (!podcast->getFeat().empty()) {
                        std::cout << "Feat: ";
                        for (const auto &feat: podcast->getFeat()) {
                            std::cout << feat << ", ";
                        }
                    }
                }
            }
            std::cout << std::endl << std::endl << std::endl;
            break;
        }
        case 3:{
            std::cout << "Audiobooks" << std::endl;
            for (const auto& audio : audio_stream) {
                if (auto* audiobook = dynamic_cast<Podcast*>(audio)) {
                    std::cout << "[" << getGenreName(audiobook->getGenre()) << "] ";
                    std::cout << audiobook->getCreator() << " - " << audiobook->getTitle();
                    if (!audiobook->getFeat().empty()) {
                        std::cout << "Feat: ";
                        for (const auto &feat: audiobook->getFeat()) {
                            std::cout << feat << ", ";
                        }
                    }
                }
                std::cout << std::endl << std::endl << std::endl;
            }
            break;
        }


    }
}

