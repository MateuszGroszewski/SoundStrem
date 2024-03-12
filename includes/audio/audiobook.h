#ifndef SOUNDSTREAM_AUDIOBOOK_H
#define SOUNDSTREAM_AUDIOBOOK_H

#include "audio.h"

class AudioBook : public Audio{

public:

    AudioBook(const AudioType new_type,
          const std::string& new_creator,
          const std::string& new_title,
          const std::vector<std::string>& new_genre,
          const std::vector<std::string>& new_feat) :
            Audio(new_type, new_creator, new_title, new_genre, new_feat) {}

    void show() const override;
};



#endif //SOUNDSTREAM_AUDIOBOOK_H
