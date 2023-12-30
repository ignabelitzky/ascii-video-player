#include <iostream>

void show_usage(std::string programName) {
    std::cerr << "Usage: " << programName << " <path_to_video_file>" << std::endl;
}

bool check_input( int& argc, char**& argv) {
    bool result = true;
    if(argc != 2) {
        show_usage(std::string(argv[0]));
        result = false;
    }
    return result;
}