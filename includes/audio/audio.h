#ifndef SOUNDSTREAM_AUDIO_H
#define SOUNDSTREAM_AUDIO_H

#include <utility>
#include <vector>
#include <string>
#include "../genres.h"


class Audio {

public:

    Audio(const AudioBookGenre newAudioBookGenre,
          std::string newCreator,
          std::string newTitle,
          const std::vector<std::string>& newFeat) :
          audioBookGenre(newAudioBookGenre),
          creator(std::move(newCreator)),
          title(std::move(newTitle)),
          feat(newFeat) {}

    Audio(const PodcastGenre newPodcastGenre,
          std::string newCreator,
          std::string newTitle,
          const std::vector<std::string>& newFeat) :
          podcastGenre(newPodcastGenre),
          creator(std::move(newCreator)),
          title(std::move(newTitle)),
          feat(newFeat) {}

    Audio(const MusicGenre newMusicGenre,
          std::string newCreator,
          std::string newTitle,
          const std::vector<std::string>& newFeat) :
          musicGenre(newMusicGenre),
          creator(std::move(newCreator)),
          title(std::move(newTitle)),
          feat(newFeat) {}

    [[nodiscard]] std::string getCreator() const;
    [[nodiscard]] std::string getTitle() const;
    [[nodiscard]] AudioBookGenre getAudioBookGenre() const;
    [[nodiscard]] PodcastGenre getPodcastGenre() const;
    [[nodiscard]] MusicGenre getMusicGenre() const;
    [[nodiscard]] std::vector<std::string> getFeat() const;

    virtual void show() const;




protected:
    AudioBookGenre audioBookGenre;
    PodcastGenre podcastGenre;
    MusicGenre musicGenre;
    std::string creator;
    std::string title;
    std::vector<std::string> feat;

};

extern std::vector<Audio*> audio_stream;




#endif //SOUNDSTREAM_AUDIO_H
