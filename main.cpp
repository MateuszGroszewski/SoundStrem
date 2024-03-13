#include "includes/menu.h"
#include "includes/genres.h"
#include "includes/audio/audio.h"
#include "includes/audio/audiobook.h"
#include "includes/audio/music.h"
#include "includes/audio/podcast.h"

int main() {

    audio_stream.push_back(new Music(GenreType::HIPHOP, "Bedoes", "Doda :*",{"Kuqe2115"}));
    audio_stream.push_back(new Music(GenreType::HIPHOP, "Chivas", "Mlody Batman",{}));
    audio_stream.push_back(new AudioBook(GenreType::FICTION, "Andrzej Sapkowski", "Wiedzmin. Ostatnie zyczenie", {}));
    audio_stream.push_back(new Podcast(GenreType::NEWS, "Zgrzyt", "ukradl tramwaj", {"Gimper", "Revo"}));

    Menu::displayMenu();

    return 0;
}
