#include "menucontent.h"
#include "audio/audio.h"
#include "audio/music.h"
#include "audio/podcast.h"
#include "genres.h"
#include "audio/audiobook.h"
#include <iostream>
#include <cctype>
#include <limits>


std::string MenuContent::returnToLower(std::string stringToLower) {
    for (char &c : stringToLower) {
        if (std::isupper(c)) {
            c = std::tolower(c);
        }
    }
    return stringToLower;
}



int MenuContent::mainMenu(){
    int option;
    std::cout << "     Main Menu     " << std::endl;
    std::cout << "1. Search" << std::endl;
    std::cout << "2. Add" << std::endl;
    std::cout << "3. Remove" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Select option from above: ";
    std::cin >> option;
    if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Value Error: Inserted value is out of range or is not a number! \n\n" << std::endl;
        return -1;
    }
    else{
        return option;
    }
}

int MenuContent::searchMenu() {
    int option;
    std::cout << "   Search Menu   " << std::endl;
    std::cout << "1. Type" << std::endl;
    std::cout << "2. Creator " << std::endl;
    std::cout << "3. Title" << std::endl;
    std::cout << "4. Genre" << std::endl;
    std::cout << "0. Back to main menu " << std::endl;
    std::cout << "Select option from above: ";
    std::cin >> option;
    std::cout << std::endl << std::endl;
    return  option;
}

void MenuContent::searchByType(int byType, bool show) {
    int index = 0;
    switch (byType){
        case 1:{
            std::cout << "Musics" << std::endl << std::endl;
            for (const auto& audio : audio_stream) {
                if (auto* music = dynamic_cast<Music*>(audio)) {
                    if (show) {
                        std::cout << "[ID: " << index << "]" << std::endl;
                    }
                    std::cout << "[" << getGenreName(music->getGenre()) << "] ";
                    std::cout << music->getCreator() << " - " << music->getTitle();
                    if (!music->getFeat().empty()) {
                        std::cout << "Feat: ";
                        for (const auto &feat: music->getFeat()) {
                            std::cout << feat << ", ";
                        }
                    }
                    std::cout << std::endl << std::endl;
                }
                index++;
            }
            break;
        }

        case 2:{
            std::cout << "Podcasts" << std::endl << std::endl;
            for (const auto& audio : audio_stream) {
                if (auto* podcast = dynamic_cast<Podcast*>(audio)) {
                    if (show) {
                        std::cout << "[ID: " << index << "]" << std::endl;
                    }
                    std::cout << "[" << getGenreName(podcast->getGenre()) << "] ";
                    std::cout << podcast->getCreator() << " - " << podcast->getTitle();
                    if (!podcast->getFeat().empty()) {
                        std::cout << "Feat: ";
                        for (const auto &feat: podcast->getFeat()) {
                            std::cout << feat << ", ";
                        }
                    }
                    std::cout << std::endl << std::endl << std::endl;
                }
                index++;
            }
            break;
        }
        case 3:{
            std::cout << "Audiobooks" << std::endl;
            for (const auto& audio : audio_stream) {
                if (auto* audiobook = dynamic_cast<AudioBook*>(audio)) {
                    if (show) {
                        std::cout << "[ID: " << index << "]" << std::endl;
                    }
                    std::cout << "[" << getGenreName(audiobook->getGenre()) << "] ";
                    std::cout << audiobook->getCreator() << " - " << audiobook->getTitle();
                    if (!audiobook->getFeat().empty()) {
                        std::cout << "Feat: ";
                        for (const auto &feat: audiobook->getFeat()) {
                            std::cout << feat << ", ";
                        }
                    }

                    std::cout << std::endl << std::endl << std::endl;
                }
                index++;
            }
            break;
        }


    }
}

GenreType MenuContent::chooseGenre(GenreType genreStart, GenreType genreEnd) {
    int genreIndex;
    for (int i = genreStart+1; i<genreEnd; ++i){
        std::cout << i-genreStart << ". " << getGenreName(i) << std::endl;
    }
    std::cout << "Choose genre: ";
    std::cin >> genreIndex;
    std::cout << std::endl << std::endl << std::endl;
    return returnGenre(genreIndex+genreStart);
}

std::vector<std::string> MenuContent::enterFeats() {
    std::string addFeat;
    int numberOfFeats;
    std::vector<std::string> feats;
    std::cout << "How many other people performed?: ";
    std::cin >> numberOfFeats;
    std::cout << std::endl;
    if (numberOfFeats < 0) {
        std::cout << "Cannot be less than 0!";
    } else if (numberOfFeats >= 1) {
        for (int i = 1; i <= numberOfFeats; ++i) {
            std::cout << "Feat " << i << ":";
            std::getline(std::cin >> std::ws, addFeat);
            std::cout << std::endl;
            feats.push_back(addFeat);
        }
    }

    return feats;
}

std::string MenuContent::enterCreator() {
    std::string creator;
    std::cout << "Enter creator name: ";
    std::getline(std::cin >> std::ws, creator);
    std::cout << std::endl;
    return creator;
}

std::string MenuContent::enterTitle() {
    std::string title;
    std::cout << "Enter title: ";
    std::getline(std::cin >> std::ws, title);
    std::cout << std::endl;
    return title;
}

int MenuContent::typeMenu() {
    int type;
    std::cout << "1. Music" << std::endl;
    std::cout << "2. Podcast" << std::endl;
    std::cout << "3. AudioBook" << std::endl;
    std::cout << "0. Back" << std::endl;
    std::cout << "Select option from above: ";
    std::cin >> type;
    std::cout << std::endl;
    return type;
}

std::vector<Audio *> MenuContent::searchCreatorSubstring(std::string &substring) {
        std::vector<Audio*> results;
        substring = returnToLower(substring);
        for (const auto& audio : audio_stream) {
            if (returnToLower(audio->getCreator()).find(substring) != std::string::npos) {
                results.push_back(audio);
            }
        }
        return results;
}

std::vector<Audio *> MenuContent::searchTitleSubstring(std::string &substring) {
    std::vector<Audio*> results;
    substring = returnToLower(substring);
    for (const auto& audio : audio_stream) {
        if (returnToLower(audio->getTitle()).find(substring) != std::string::npos) {
            results.push_back(audio);
        }
    }
    return results;
}

void MenuContent::showSearch(const std::vector<Audio *>& showFrom) {
    if (!showFrom.empty()) {
        for (const auto &audio: showFrom) {
            std::cout << "[" << getGenreName(audio->getGenre()) << "] " << std::endl;
            std::cout << audio->getCreator() << " - " << audio->getTitle() << std::endl;
            if (!audio->getFeat().empty()) {
                std::cout << "Feat: ";
                for (const auto &feat: audio->getFeat()) {
                    std::cout << feat << ", ";
                }
            }
            std::cout << std::endl << std::endl << std::endl;
        }
    }
}

std::vector<Audio *> MenuContent::searchByGenre(GenreType type) {
    std::vector<Audio*> results;
    for (const auto& audio : audio_stream) {
        if (audio->getGenre() == type) {
            results.push_back(audio);
        }
    }
    return results;
}





