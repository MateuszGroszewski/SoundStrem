#ifndef SOUNDSTREAM_SOUND_H
#define SOUNDSTREAM_SOUND_H

#include <vector>
#include <string>

class Sound {

    public:

        Sound (std::string  artist, std::string  title, std::string genre)
            : artist(std::move(artist)), title(std::move(title)), genre(std::move(genre)) {};


        [[nodiscard]] std::string getArtist() const;
        [[nodiscard]] std::string getTitle() const;
        [[nodiscard]] std::string getGenre() const;

        static bool containsSubstring(const std::string& str, const std::string& substr);

        virtual void search() const;


    protected:
        std::string artist;
        std::string title;
        std::string genre;

};

class AudioBook : public Sound{

    public:

        AudioBook(const std::string& artist, const std::string& title, const std::string& genre)
            : Sound(artist, title, genre){}

        void search() const override;

};

class Podcast : public Sound{

    public:

        Podcast(const std::string& artist, const std::string& title, const std::string& genre)
            : Sound(artist, title, genre){}

        void search() const override;


};

class Music : public Sound{

    public:

        Music(const std::string& artist, const std::string& title, const std::string& genre)
                : Sound(artist, title, genre){}

        void search() const override;

};

extern std::vector <Sound*> sound_stream;



#endif //SOUNDSTREAM_SOUND_H
