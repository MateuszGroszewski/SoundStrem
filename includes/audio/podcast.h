#ifndef SOUNDSTREAM_PODCAST_H
#define SOUNDSTREAM_PODCAST_H

#include "audio.h"

class Podcast : public Audio{

public:

    Podcast(const PodcastGenre newMusicGenre,
            std::string newCreator,
            std::string newTitle,
            const std::vector<std::string>& newFeat) :
            Audio(newMusicGenre, std::move(newCreator), std::move(newTitle), newFeat) {}

};

#endif //SOUNDSTREAM_PODCAST_H
