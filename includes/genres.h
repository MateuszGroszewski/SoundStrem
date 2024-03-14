#ifndef SOUNDSTREAM_GENRES_H
#define SOUNDSTREAM_GENRES_H

#include <string>
#include <vector>

enum GenreType{

    MUSIC_GENRE_START,
    HIPHOP,
    CLASSICAL,
    JAZZ,
    ROCK,
    POP,
    COUNTRY,
    ELECTRONIC,
    RNB,
    MUSIC_GENRE_END,

    PODCAST_GENRE_START,
    INTERVIEW,
    NEWS,
    TECHNOLOGY,
    COMEDY,
    TRUECRIME,
    HEALTH,
    PODCAST_GENRE_END,

    AUDIOBOOK_GENRE_START,
    HORROR,
    POETRY,
    HISTORICALFICTION,
    FICTION,
    NONFICTION,
    AUDIOBOOK_GENRE_END,

    UNKNOWN

};

std::string getGenreName(int index);

GenreType returnGenre(int index);


#endif //SOUNDSTREAM_GENRES_H
