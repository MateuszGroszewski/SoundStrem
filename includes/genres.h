#ifndef SOUNDSTREAM_GENRES_H
#define SOUNDSTREAM_GENRES_H

enum MusicGenre{
    HIPHOP,
    CLASSICAL,
    JAZZ,
    ROCK,
    POP,
    COUNTRY,
    ELECTRONIC,
    RNB,
    MUSIC_GENRE_NUM
};

enum PodcastGenre{
    INTERVIEW,
    NEWS,
    TECHNOLOGY,
    COMEDY,
    TRUECRIME,
    HEALTH
};

enum AudioBookGenre{
    HORROR,
    POETRY,
    HISTORICALFICTION,
    FICTION,
    NONFICTION
};

MusicGenre chooseMusicGenre(int chosen){
    switch (chosen){
        case 1:{
            return MusicGenre::HIPHOP;
        }
        case 2:{
            return MusicGenre::CLASSICAL;
        }
        case 3:{
            return MusicGenre::JAZZ;
        }
        case 4:{
            return MusicGenre::ROCK;
        }
        case 5:{
            return MusicGenre::POP;
        }
        case 6:{
            return MusicGenre::COUNTRY;
        }
        case 7:{
            return MusicGenre::ELECTRONIC;
        }
        case 8:{
            return MusicGenre::RNB;
        }
    }
};
PodcastGenre choosePodcastGenre(int chosen);
AudioBookGenre chooseAudiobookGenre(int chosen);




#endif //SOUNDSTREAM_GENRES_H
