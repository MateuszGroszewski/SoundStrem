#include "genres.h"
#include <string>

std::vector<std::string> genreNames = {
        "MUSIC_GENRE_START",
        "HIPHOP",
        "CLASSICAL",
        "JAZZ",
        "ROCK",
        "POP",
        "COUNTRY",
        "ELECTRONIC",
        "RNB",
        "MUSIC_GENRE_END",

        "PODCAST_GENRE_START",
        "INTERVIEW",
        "NEWS",
        "TECHNOLOGY",
        "COMEDY",
        "TRUECRIME",
        "HEALTH",
        "PODCAST_GENRE_END",

        "AUDIOBOOK_GENRE_START",
        "HORROR",
        "POETRY",
        "HISTORICALFICTION",
        "FICTION",
        "NONFICTION",
        "AUDIOBOOK_GENRE_END"
};



std::string getGenreName(int index){
    if (index > MUSIC_GENRE_START && index<AUDIOBOOK_GENRE_END){
        return genreNames[index];
    }
    else {
        return "UNKNOWN";
    }
}

GenreType chooseGenre(int value){
    {
        if (value >= MUSIC_GENRE_START && value < MUSIC_GENRE_END) {
            return static_cast<GenreType>(value);
        } else if (value >= PODCAST_GENRE_START && value < PODCAST_GENRE_END) {
            return static_cast<GenreType>(value);
        } else if (value >= AUDIOBOOK_GENRE_START && value < AUDIOBOOK_GENRE_END) {
            return static_cast<GenreType>(value);
        } else {
            return GenreType::UNKNOWN;
        }
    }
}
