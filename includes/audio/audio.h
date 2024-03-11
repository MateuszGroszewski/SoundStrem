#ifndef SOUNDSTREAM_AUDIO_H
#define SOUNDSTREAM_AUDIO_H

#include <vector>
#include <string>
#include "../element.h"


class Audio {

public:

    explicit Audio(const Element &element) :
        artist(element.new_artist),
        title(element.new_title),
        genre(element.new_genre),
        feat(element.new_feat)  { };



protected:
    AudioType new_type;
    Element artist;
    std::string title;
    std::string genre;
    std::vector<std::string> feat;

};

std::vector<Audio*> audio_stream;




#endif //SOUNDSTREAM_AUDIO_H
