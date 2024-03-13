#include "menu.h"
#include "audio/audio.h"
#include "audio/audiobook.h"
#include "genres.h"
#include "audio/music.h"
#include "menucontent.h"
#include <iostream>


void Menu::displayMenu() {


    int menuOption;
    do {
        menuOption = MenuContent::mainMenu();

        switch (menuOption){
            case 1:{
                int searchOption;

                do {
                    searchOption = MenuContent::searchMenu();
                    switch (searchOption){
                        case 1: {
                            int searchType;
                            std::cout << "Search by audio type" << std::endl;
                            std::cout << "1. Music" << std::endl;
                            std::cout << "2. Podcast" << std::endl;
                            std::cout << "3. AudioBook" << std::endl;
                            std::cout << "Select option from above: ";
                            std::cin >> searchType;
                            std::cout << std::endl;

                            MenuContent::searchByType(searchType);

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

                } while (searchOption != 0);
                break;
            }

            case 2: {
                int add_options;
                do {
                    int numberOfFeats;
                    int genre;
                    std::string newCreator;
                    std::string newTitle;
                    std::string newFeat;
                    std::vector<std::string> newFeats;

                    std::cout << std::endl << std::endl;
                    std::cout << "   Add Menu   " << std::endl;
                    std::cout << "1. Music " << std::endl;
                    std::cout << "2. Podcast " << std::endl;
                    std::cout << "3. Audiobook" << std::endl;
                    std::cout << "0. Back to main menu " << std::endl;
                    std::cout << "Select option from above: ";
                    std::cin >> add_options;
                    std::cout << std::endl;

                    switch (add_options) {
                        case 1: {

                            GenreType chosenGenre;
                            std::cout << "Enter creator name: ";
                            std::getline(std::cin >> std::ws, newCreator);
                            std::cout << std::endl;

                            std::cout << "Enter title: ";
                            std::getline(std::cin >> std::ws, newTitle);
                            std::cout << std::endl;

                            for (int i = MUSIC_GENRE_START+1; i<GenreType::MUSIC_GENRE_END; ++i){
                                std::cout << i << ". " << getGenreName(i) << std::endl;
                            }
                            std::cout << "Choose genre: ";
                            std::cin >> genre;
                            chosenGenre = chooseGenre(genre);
                            std::cout << std::endl;

                            std::cout << "How many other people performed?: ";
                            std::cin >> numberOfFeats;
                            std::cout << std::endl;
                            if (numberOfFeats < 0) {
                                std::cout << "Cannot be less than 0!";
                            } else if (numberOfFeats >= 1) {
                                for (int i = 1; i <= numberOfFeats; ++i) {
                                    std::cout << "Feat " << i << ":";
                                    std::getline(std::cin >> std::ws, newFeat);
                                    std::cout << std::endl;
                                    newFeats.push_back(newFeat);
                                }
                            }
                            std::cout << "Adding new Audiobook please wait!..." << std::endl;
                            audio_stream.push_back(new Music(chosenGenre, newCreator, newTitle, newFeats));
                            std::cout << "Added successfully!" << std::endl;

                            break;
                        } // case 1 music

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

    } while (menuOption != 0);
}