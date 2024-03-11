#ifndef SOUNDSTREAM_AUDIOBOOK_H
#define SOUNDSTREAM_AUDIOBOOK_H

#include "audio.h"

class AudioBook : public Audio{

public:

    explicit AudioBook(const Element &element) : Audio(artist, title, genre, feat) { };

};

#endif //SOUNDSTREAM_AUDIOBOOK_H
