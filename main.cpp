#include <iostream>
#include <vector>

#include "types.hpp"
#include "util.hpp"
#include "vm.hpp"

int main(/* int argc, char *argv[] */) {
    std::vector<Byte> rom = load_binary_file("rom.bin");

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
