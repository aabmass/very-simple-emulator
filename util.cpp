#include "util.hpp"

#include <fstream>
#include <iterator>
#include <sstream>

std::string load_text_file(std::string const& fname) {
    std::ifstream fs(fname);
    std::stringstream buf;
    buf << fs.rdbuf();

    return buf.str();
}

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

Address create_addr_from_bytes(Byte addr_low, Byte addr_high) {
    // build the address from the low and high bytes.
    // Set equal to high byte, then shift it over by 8. Finally, or with
    // the low byte to get the full address
    Address a = addr_high;

    a <<= 8;

    // low byte
    a |= addr_low;

    return a;
}
