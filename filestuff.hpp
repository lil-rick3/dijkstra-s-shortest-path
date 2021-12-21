#ifndef FILE_THINGS
#define FILE_THINGS


#include "string"
#include <vector>



struct Arc
{
    std::string sourceID;
    std::string targetID;
    unsigned int cost;
};

namespace filereading {

    void read_in_file(char**, int, std::vector<std::string>*, std::vector<Arc>*);
    std::istream& get_input_handle(const int, std::ifstream&, const char*);

}

#endif