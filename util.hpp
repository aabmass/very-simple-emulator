#ifndef UTIL_HPP_ESRDFTJX
#define UTIL_HPP_ESRDFTJX

#include "types.hpp"
#include <vector>

std::string load_text_file(std::string const& fname);
std::vector<Byte> load_binary_file(std::string const& fname);
Address create_addr_from_bytes(Byte addr_low, Byte addr_high);

struct EnumClassHash {
    template <typename T>
    std::size_t operator()(T t) const {
        return static_cast<std::size_t>(t);
    }
};

#endif /* end of include guard: UTIL_HPP_ESRDFTJX */
