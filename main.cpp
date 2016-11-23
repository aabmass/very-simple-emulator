#include <iostream>
#include <vector>

#include "types.hpp"
#include "util.hpp"
#include "vm.hpp"

int main(/* int argc, char *argv[] */) {
    std::vector<Byte> rom = load_binary_file("rom.bin");

    VM vm(rom);

    vm.execute_instr();
    vm.execute_instr();
    vm.execute_instr();
    
    std::cout << vm << std::endl;
    
    return 0;
}
