#include "util.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2)
        std::cerr << "usage: asm <assembly-file-name>" << std::endl;

    std::string fname = argv[1];
    std::string file_text = load_text_file(fname);

     
    return 0;
}
