#ifndef SOUNDSTREAM_MUSIC_H
#define SOUNDSTREAM_MUSIC_H

#include "audio.h"

class Music : public Audio{

public:

    Music(const MusicGenre newMusicGenre,
          std::string newCreator,
          std::string newTitle,
          const std::vector<std::string>& newFeat) :
            Audio(newMusicGenre, std::move(newCreator), std::move(newTitle), newFeat) {}

};

#endif //SOUNDSTREAM_MUSIC_H
