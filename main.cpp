#include <iostream>
#include <vector>

#include "types.hpp"
#include "vm.hpp"

int main(/* int argc, char *argv[] */) {
    std::vector<Byte> rom = {0x00, 0xAB, 0x02, 0xFF, 0x01, 0x01, 0x03, 0xE7};
    VM vm(rom);
    
    vm.execute_instr();
    vm.execute_instr();
    vm.execute_instr();
    vm.execute_instr();

    std::cout << vm << std::endl;
    
    return 0;
}
