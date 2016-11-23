#include "util.hpp"

#include <fstream>
#include <iterator>

std::vector<Byte> load_binary_file(std::string const& fname) {
    // open the file:
    std::ifstream file(fname, std::ios::binary);

    // Stop eating new lines in binary mode!!!
    file.unsetf(std::ios::skipws);

    // get its size:
    std::streampos fileSize;

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // reserve capacity
    std::vector<Byte> vec;
    vec.reserve(fileSize);

    // read the data:
    vec.insert(vec.begin(),
               std::istream_iterator<Byte>(file),
               std::istream_iterator<Byte>());

    return vec;
}
