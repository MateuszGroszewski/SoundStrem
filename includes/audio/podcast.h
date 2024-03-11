#ifndef SOUNDSTREAM_PODCAST_H
#define SOUNDSTREAM_PODCAST_H

#include "audio.h"

class Podcast : public Audio{

public:

    Podcast(const std::string& artist, const std::string& title, const std::string& genre)
            : Audio(artist, title, genre, std::vector<std::string>()) {}

};

#endif //SOUNDSTREAM_PODCAST_H
