#ifndef SOUNDSTREAM_AUDIOBOOK_H
#define SOUNDSTREAM_AUDIOBOOK_H

#include <utility>

#include "audio.h"


class AudioBook : public Audio{

public:

    AudioBook(const GenreType newGenre,
              std::string newCreator,
              std::string newTitle,
              const std::vector<std::string>& newFeat) :
            Audio(newGenre, std::move(newCreator), std::move(newTitle), newFeat) {}

    void show() const override;
};



#endif //SOUNDSTREAM_AUDIOBOOK_H
