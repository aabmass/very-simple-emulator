#include <iostream>
#include <vector>

#include "types.hpp"
#include "util.hpp"
#include "vm.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: main <path-to-rom-bin>" << std::endl;
        return 1;
    }
    std::vector<Byte> rom = load_binary_file(*(argv + 1));

    VM vm(rom);

    // keep executing until the vm tells us to stop
    bool cont = true;
    while (cont) {
        std::cout << vm << std::endl;
        cont = vm.execute_instr();
    }

    std::cout << vm << std::endl;

    return 0;
}
