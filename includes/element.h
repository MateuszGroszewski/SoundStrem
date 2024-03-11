#ifndef SOUNDSTREAM_ELEMENT_H
#define SOUNDSTREAM_ELEMENT_H

#include <string>
#include <vector>
#include "audiotype.h"

class Element {

public:
    std::string new_artist;
    std::string new_title;
    std::string new_genre;
    std::vector<std::string> new_feat;

};

#endif //SOUNDSTREAM_ELEMENT_H
