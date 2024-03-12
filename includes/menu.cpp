#include "menu.h"
#include "audio/audio.h"
#include "audio/audiobook.h"
#include "audiotype.h"
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

                            if (!audio_stream.empty()) {

                            } else {
                                std::cout << "Audio stream is empty!" << std::endl;
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

            case 2: {
                int add_options;
                do {
                    int number_of_feats;
                    int number_of_genres;
                    AudioType new_type;
                    std::string new_creator;
                    std::string new_title;
                    std::string new_genre;
                    std::vector<std::string> new_genres;
                    std::string new_feat;
                    std::vector<std::string> new_feats;

                    std::cout << std::endl << std::endl;
                    std::cout << "   Add Menu   " << std::endl;
                    std::cout << "1. Add AudioBook " << std::endl;
                    std::cout << "2. Add Podcast " << std::endl;
                    std::cout << "3. Add Music" << std::endl;
                    std::cout << "0. Back to main menu " << std::endl;
                    std::cout << "Select option from above: ";
                    std::cin >> add_options;
                    std::cout << std::endl;

                    switch (add_options) {
                        case 1: {
                            new_type = AudioType::AudioBook;

                            std::cout << "Enter creator name: ";
                            std::getline(std::cin >> std::ws, new_creator);
                            std::cout << std::endl;

                            std::cout << "Enter title: ";
                            std::getline(std::cin >> std::ws, new_title);
                            std::cout << std::endl;

                            std::cout << "How many genre tags you want to add?: ";
                            std::cin >> number_of_genres;
                            std::cout << std::endl;

                            if (number_of_genres < 0) {
                                std::cout << "Number cannot be less than 0!" << std::endl;
                            } else if (number_of_genres >= 1) {
                                for (int i = 0; i <= number_of_genres; ++i) {
                                    std::cout << "Genre " << i << ":";
                                    std::getline(std::cin >> std::ws, new_genre);
                                    std::cout << std::endl;
                                    new_genres.push_back(new_genre);
                                }
                            }


                            std::cout << "How many other people performed?: ";
                            std::cin >> number_of_feats;
                            if (number_of_feats < 0) {
                                std::cout << "Cannot be less than 0!";
                            } else if (number_of_feats >= 1) {
                                for (int i = 0; i <= number_of_feats; ++i) {
                                    std::cout << "Feat " << i << ":";
                                    std::getline(std::cin >> std::ws, new_feat);
                                    std::cout << std::endl;
                                    new_feats.push_back(new_feat);
                                }
                            }

                            audio_stream.push_back(new AudioBook(new_type, new_creator, new_title, new_genres, new_feats));




                            std::cout << "Adding new Audiobook please wait!..." << std::endl;
                            std::cout << "Added successfully!" << std::endl;
                            break;
                        } // case 1 audiobook

                        case 2: {

                            std::cout << "Added successfully!!" << std::endl;
                            break;
                        } // case 2

                        case 3: {

                            std::cout << "Added successfully!" << std::endl;
                            break;
                        } // case 3

                        case 0: {
                            break;
                        } // case 0

                        default: {
                            std::cout << "Wrong choice! Please try again." << std::endl;
                            break;
                        } // default
                    }
                } while (add_options != 0);
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