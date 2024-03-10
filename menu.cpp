#include "headers/menu.h"
#include "headers/sound.h"
#include "headers/creation.h"
#include <iostream>


void Menu::displayMenu() {

    int menu_options;

    do {
        std::cout << "     Main Menu     " << std::endl;
        std::cout << "1. Search" << std::endl;
        std::cout << "2. Add" << std::endl;
        std::cout << "3. Remove" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Select option from above: ";
        std::cin >> menu_options;
        std::cout << std::endl;

        switch (menu_options){
            case 1:{
                int search_options;
                do {
                    std::cout << std::endl << std::endl;
                    std::cout << "   Search Menu   " << std::endl;
                    std::cout << "Search by: " << std::endl;
                    std::cout << "1. Tag (AudioBook/ Podcast/ Music)" << std::endl;
                    std::cout << "2. Artist " << std::endl;
                    std::cout << "3. Title" << std::endl;
                    std::cout << "4. Genre" << std::endl;
                    std::cout << "0. Back to main menu " << std::endl;
                    std::cout << "Select option from above: ";
                    std::cin >> search_options;
                    std::cout << std::endl;

                    switch (search_options){
                        case 1:{
                            std::cout << std::endl << std::endl;
                            std::cout << "Search by tag" << std::endl;
                            std::cout << "1. AudioBook" << std::endl;
                            std::cout << "2. Podcast" << std::endl;
                            std::cout << "3. Music" << std::endl;
                            std::cout << "Select option from above: ";
                            std::cin >> search_options;
                            std::cout << std::endl;
                            if (search_options == 1) {
                                std::cout << std::endl << std::endl;
                                std::cout << "Searching for AudioBook..." << std::endl;
                                std::cout << "AudioBooks: " << std::endl << std::endl;
                                for (const auto &sound: sound_stream) {
                                    if (const auto *audiobook = dynamic_cast<const AudioBook *>(sound)) {
                                        audiobook->search();
                                    }
                                }
                            }
                            else if (search_options == 2){
                                std::cout << std::endl << std::endl;
                                std::cout << "Searching for Podcasts..." << std::endl;
                                std::cout << "Podcasts: " << std::endl << std::endl;
                                for (const auto &sound : sound_stream){
                                    if (const auto *podcast = dynamic_cast<const Podcast*>(sound)){
                                        podcast->search();
                                    }
                                }
                            }
                            else if (search_options == 3){
                                std::cout << std::endl << std::endl;
                                std::cout << "Searching for Music..." << std::endl;
                                std::cout << "Music:" << std::endl << std::endl;
                                for (const auto &sound : sound_stream){
                                    if (const auto *music = dynamic_cast<const Music*>(sound)){
                                        music->search();
                                    }
                                }
                            }
                            break;
                        } // case 1

                        case 2:{
                            std::string search_artist;
                            std::cout <<"Enter name of the artist: ";
                            std::cin >> search_artist;
                            std::cout << "Searching for artist: '" << search_artist << "'..." << std::endl;
                            std::cout << "Searching done!" << std::endl;
                            std::cout <<"***Results***" << std::endl << std::endl;
                            for (const auto& sound : sound_stream){
                                if(Sound::containsSubstring(sound->getArtist(), search_artist)){
                                    sound->search();
                                }
                            }
                            break;
                        } // case 2

                        case 3:{
                            std::string search_title;
                            std::cout << "Enter title: ";
                            std::cin >> search_title;
                            std::cout << std::endl;
                            std::cout << "Searching for title: '" << search_title << "'..." << std::endl;
                            std::cout << "Searching done!" << std::endl;
                            std::cout <<"***Results***" << std::endl << std::endl;
                            for (const auto* sound : sound_stream){
                                if(Sound::containsSubstring(sound->getTitle(), search_title)){
                                    sound->search();
                                }
                            }
                            break;
                        } // case 3

                        case 4:{
                            std::string search_genre;
                            std::cout << "Enter genre: ";
                            std::cin >> search_genre;
                            std::cout << std::endl;
                            std::cout << "Searching for genre: '" << search_genre << "'..." << std::endl;
                            std::cout << "Searching done!" << std::endl;
                            std::cout <<"***Results***" << std::endl << std::endl;
                            for (const auto* sound : sound_stream){
                                if(Sound::containsSubstring(sound->getGenre(), search_genre)){
                                    sound->search();
                                }
                            }
                            break;
                        } // case 4

                        case 0:{
                            break;
                        }

                        default:{
                            std::cout << "Wrong choice! Please try again." << std::endl;
                            break;
                        }

                    }

                } while (search_options != 0);
                break;
            }

            case 2:{
                int add_options;
                do {
                    Creation new_creation;

                    std::string new_artist;
                    std::string new_title;
                    std::string new_genre;

                    std::cout << std::endl << std::endl;
                    std::cout << "   Add Menu   " << std::endl;
                    std::cout << "1. Add AudioBook " << std::endl;
                    std::cout << "2. Add Podcast " << std::endl;
                    std::cout << "3. Add Music" << std::endl;
                    std::cout << "0. Back to main menu " << std::endl;
                    std::cout << "Select option from above: ";
                    std::cin >> add_options;
                    std::cout << std::endl;

                    switch (add_options){
                        case 1:{
                            std::cout << "Enter artist name: ";
                            std::cin >> new_creation.new_artist;
                            std::cout << std::endl;

                            std::cout << "Enter title: ";
                            std::cin >> new_creation.new_title;
                            std::cout << std::endl;

                            std::cout << "Enter genre: ";
                            std::cin >> new_creation.new_genre;
                            std::cout << std::endl;

                            std::cout << "Adding new Audiobook please wait!..." << std::endl;
                            sound_stream.push_back(new AudioBook(new_creation.new_artist, new_creation.new_title, new_creation.new_genre));
                            std::cout << "Added successfully!" << std::endl;
                            break;
                        }

                        case 2:{
                            std::cout << "Enter artist name: ";
                            std::getline(std::cin >> std::ws, new_artist);
                            std::cout << std::endl;

                            std::cout << "Enter title: ";
                            std::getline(std::cin >> std::ws, new_title);
                            std::cout << std::endl;

                            std::cout << "Enter genre: ";
                            std::getline(std::cin >> std::ws, new_genre);
                            std::cout << std::endl;

                            std::cout << "Adding new Podcast please wait!..." << std::endl;
                            sound_stream.push_back(new Podcast(new_artist, new_title, new_genre));
                            std::cout << "Added successfully!" << std::endl;
                            break;
                        }

                        case 3:{
                            std::cout << "Enter artist name: ";
                            std::cin >> new_creation.new_artist;
                            std::cout << std::endl;

                            std::cout << "Enter title: ";
                            std::cin >> new_creation.new_title;
                            std::cout << std::endl;

                            std::cout << "Enter genre: ";
                            std::cin >> new_creation.new_artist;
                            std::cout << std::endl;

                            std::cout << "Adding new Music please wait!..." << std::endl;
                            sound_stream.push_back(new Music(new_creation.new_artist, new_creation.new_title, new_creation.new_genre));
                            std::cout << "Added successfully!" << std::endl;
                            break;
                        }

                        case 0:{
                            break;
                        }

                        default:{
                            std::cout << "Wrong choice! Please try again." << std::endl;
                            break;
                        }
                    }

                } while (add_options != 0);
                break;
            }

            case 3:{
                std::cout << "Removing... Please wait!" << std::endl;
                break;
            }

            case 0:{
                std::cout << "Exiting... ";
                break;
            }

            default:{
              std::cout << "Wrong choice! Please try again." << std::endl;
              break;
            }
        }




    } while (menu_options != 0);
}