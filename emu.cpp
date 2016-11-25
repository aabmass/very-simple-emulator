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
        cont = vm.execute_instr();
    }

    std::cout << std::endl <<  "Finished running program! End state of VM:" << std::endl;
    std::cout << vm << std::endl;

    return 0;
}
