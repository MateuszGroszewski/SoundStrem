#ifndef SOUNDSTREAM_AUDIO_H
#define SOUNDSTREAM_AUDIO_H

#include <utility>
#include <vector>
#include <string>
#include "../genres.h"


class Audio {

public:

    Audio(const GenreType newGenre,
          std::string newCreator,
          std::string newTitle,
          const std::vector<std::string>& newFeat) :
          genre(newGenre),
          creator(std::move(newCreator)),
          title(std::move(newTitle)),
          feat(newFeat) {}


    [[nodiscard]] std::string getCreator() const;
    [[nodiscard]] std::string getTitle() const;
    [[nodiscard]] GenreType getGenre() const;
    [[nodiscard]] std::vector<std::string> getFeat() const;

    virtual void show() const;




protected:
    GenreType genre;
    std::string creator;
    std::string title;
    std::vector<std::string> feat;

};

extern std::vector<Audio*> audio_stream;




#endif //SOUNDSTREAM_AUDIO_H
