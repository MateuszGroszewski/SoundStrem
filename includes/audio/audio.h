#ifndef SOUNDSTREAM_AUDIO_H
#define SOUNDSTREAM_AUDIO_H

#include <utility>
#include <vector>
#include <string>
#include "../audiotype.h"


class Audio {

public:

    Audio(const AudioType new_type,
          std::string new_creator,
          std::string new_title,
          const std::vector<std::string>& new_genre,
          const std::vector<std::string>& new_feat) :
          type(new_type),
          creator(std::move(new_creator)),
          title(std::move(new_title)),
          genre(new_genre),
          feat(new_feat) {}

    [[nodiscard]] AudioType getType() const;
    [[nodiscard]] std::string getCreator() const;
    [[nodiscard]] std::string getTitle() const;
    [[nodiscard]] std::vector<std::string> getGenre() const;
    [[nodiscard]] std::vector<std::string> getFeat() const;

    virtual void show() const;




protected:
    AudioType type;
    std::string creator;
    std::string title;
    std::vector<std::string> genre;
    std::vector<std::string> feat;

};

extern std::vector<Audio*> audio_stream;




#endif //SOUNDSTREAM_AUDIO_H
