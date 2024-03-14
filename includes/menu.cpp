#include "menu.h"
#include "audio/audio.h"
#include "audio/audiobook.h"
#include "genres.h"
#include "audio/music.h"
#include "menucontent.h"
#include "audio/podcast.h"
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
                            int type = MenuContent::typeMenu();

                            MenuContent::searchByType(type, false);

                            break;
                        } // case 1 by type

                        case 2:{
                            std::string searchFor = MenuContent::enterCreator();

                            std::vector<Audio*> results = MenuContent::searchCreatorSubstring(searchFor);

                            MenuContent::showSearch(results);


                            break;
                        } // case 2 by creator name

                        case 3:{
                            std::string searchFor = MenuContent::enterTitle();

                            std::vector<Audio*> results = MenuContent::searchTitleSubstring(searchFor);

                            MenuContent::showSearch(results);

                            break;
                        } // case 3 by title

                        case 4:{
                            GenreType genre;
                            int type = MenuContent::typeMenu();
                            switch (type){
                                case 1:{
                                    genre = MenuContent::chooseGenre(GenreType::MUSIC_GENRE_START, GenreType::MUSIC_GENRE_END);
                                    break;
                                }

                                case 2:{
                                    genre = MenuContent::chooseGenre(GenreType::PODCAST_GENRE_START, GenreType::PODCAST_GENRE_END);
                                    break;
                                }

                                case 3:{
                                    genre = MenuContent::chooseGenre(GenreType::AUDIOBOOK_GENRE_START, GenreType::AUDIOBOOK_GENRE_END);
                                    break;
                                }

                            }

                            std::vector<Audio*> results = MenuContent::searchByGenre(genre);

                            MenuContent::showSearch(results);

                            break;
                        } // case 4 by genre

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
            } // case 1 search

            case 2: {
                int addOptions;
                do {
                    std::cout << std::endl << std::endl;
                    std::cout << "   Add Menu   " << std::endl;
                    std::cout << "1. Music " << std::endl;
                    std::cout << "2. Podcast " << std::endl;
                    std::cout << "3. Audiobook" << std::endl;
                    std::cout << "0. Back to main menu " << std::endl;
                    std::cout << "Select option from above: ";
                    std::cin >> addOptions;
                    std::cout << std::endl;

                    switch (addOptions) {
                        case 1: {
                            std::string creator = MenuContent::enterCreator();
                            std::string title = MenuContent::enterTitle();
                            GenreType genre = MenuContent::chooseGenre(GenreType::MUSIC_GENRE_START, GenreType::MUSIC_GENRE_END);
                            std::vector<std::string> feats = MenuContent::enterFeats();

                            std::cout << "Adding new Music please wait!..." << std::endl;
                            audio_stream.push_back(new Music(genre, creator, title, feats));
                            std::cout << "Added successfully!" << std::endl;

                            break;
                        } // case 1 add music

                        case 2: {
                            std::string creator = MenuContent::enterCreator();
                            std::string title = MenuContent::enterTitle();
                            GenreType genre = MenuContent::chooseGenre(GenreType::PODCAST_GENRE_START, GenreType::PODCAST_GENRE_END);
                            std::vector<std::string> feats = MenuContent::enterFeats();

                            std::cout << "Adding new Podcast please wait!..." << std::endl;
                            audio_stream.push_back(new Podcast(genre, creator, title, feats));
                            std::cout << "Added successfully!" << std::endl;

                            break;
                        } // case 2 add Podcast

                        case 3: {
                            std::string creator = MenuContent::enterCreator();
                            std::string title = MenuContent::enterTitle();
                            GenreType genre = MenuContent::chooseGenre(GenreType::AUDIOBOOK_GENRE_START, GenreType::AUDIOBOOK_GENRE_END);
                            std::vector<std::string> feats = MenuContent::enterFeats();

                            std::cout << "Adding new Podcast please wait!..." << std::endl;
                            audio_stream.push_back(new AudioBook(genre, creator, title, feats));
                            std::cout << "Added successfully!" << std::endl;

                            break;
                        } // case 3 add AudioBook

                        case 0: {
                            break;
                        } // case 0

                        default: {
                            std::cout << "Wrong choice! Please try again." << std::endl;
                            break;
                        } // default
                    }
                } while (addOptions != 0);
            } // case 2 add element done!

            case 3:{
                std::cout << "remove menu" << std::endl;
                int type = MenuContent::typeMenu();

                MenuContent::searchByType(type, true);

                std::cout << "Enter index to delete: ";
                int indexToDelete;
                std::cin >> indexToDelete;
                audio_stream.erase(audio_stream.begin() + indexToDelete);
                std::cout << "Removing... Please wait!" << std::endl;
                break;
            } // case 3 remove element

            case 0:{
                std::cout << "Exiting... ";
                break;
            } // case 0 shutdown app

            default:{
              std::cout << "Wrong choice! Please try again." << std::endl;
              break;
            } // default
        }

    } while (menuOption != 0);
}