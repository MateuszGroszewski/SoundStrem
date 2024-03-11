#ifndef SOUNDSTREAM_MUSIC_H
#define SOUNDSTREAM_MUSIC_H

#include "audio.h"

class Music : public Audio{

public:

    Music(const std::string& artist, const std::string& title, const std::string& genre)
            : Audio(artist, title, genre, std::vector<std::string>()) {}

    explicit Music(const Creation& creation)
            : Audio(creation.new_artist, creation.new_title, creation.new_genre, std::vector<std::string>()) {}

};

#endif //SOUNDSTREAM_MUSIC_H
