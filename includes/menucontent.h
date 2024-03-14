#ifndef SOUNDSTREAM_MENUCONTENT_H
#define SOUNDSTREAM_MENUCONTENT_H

#include "genres.h"
#include "audio/audio.h"
#include <vector>
#include <string>

class MenuContent {
public:
    static int mainMenu ();
    static int searchMenu ();
    static int typeMenu ();
    static void searchByType (int byType, bool show);
    static std::vector<Audio *> searchByGenre (GenreType type);
    static std::vector<Audio*> searchCreatorSubstring(const std::string& substring);
    static std::vector<Audio*> searchTitleSubstring(const std::string& substring);
    static void showSearch(const std::vector<Audio*>& showFrom);
    static std::string enterCreator();
    static std::string enterTitle();
    static GenreType chooseGenre (GenreType genreStart, GenreType genreEnd);
    static std::vector<std::string> enterFeats ();
    static int addMenu ();
    static int removeMenu ();

};


#endif //SOUNDSTREAM_MENUCONTENT_H