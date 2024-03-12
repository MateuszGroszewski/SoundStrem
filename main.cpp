#include "includes/menu.h"
#include "includes/genres.h"
#include "includes/audio/audio.h"
#include "includes/audio/audiobook.h"
#include "includes/audio/music.h"
#include "includes/audio/podcast.h"

int main() {

    audio_stream.push_back(new Music(MusicGenre::HIPHOP, "Bedoes", "Doda :*",{"Kuqe2115"}));
    audio_stream.push_back(new AudioBook(AudioBookGenre::FICTION, "Andrzej Sapkowski", "Wiedzmin. Ostatnie zyczenie", {}));
    audio_stream.push_back(new Podcast(PodcastGenre::NEWS, "Zgrzyt", "ukradl tramwaj", {"Gimper", "Revo"}));

    Menu::displayMenu();

    return 0;
}
