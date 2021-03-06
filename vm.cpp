#include "vm.hpp"
#include "util.hpp"

VM::VM(std::vector<Byte> const& rom_contents) :
    proc({0, 0, 0, 0, 0, 0}),
    rom(new Byte[0x8000]),
    ram(new Byte[0x8000]),
    controller(*this)
{
    // load the rom with the values given
    for (std::size_t i = 0; i < rom_contents.size(); ++i) {
        rom[i] = rom_contents[i];
    }
}

VM::~VM() {
    delete[] rom;
    delete[] ram;
}

bool VM::execute_instr() {
    return controller.execute_instr();
}

void VM::pc_inc() {
    ++proc.pc;
}

OtherReg VM::get_reg(RegisterName rn) {
    switch (rn) {
        case RegisterName::A: return proc.a;
        case RegisterName::B: return proc.b;
        case RegisterName::X: return proc.x;
        case RegisterName::Y: return proc.y;
    }
}

Byte VM::get_mem(Address a) {
    /*
     * rom is mapped from 0x0000 to 0x7FFF, ram is mapped
     * from 0x8000 to 0xFFFF
     */
    if (a > 0x7FFF) // ram
        return ram[a - 0x8000];
    else            // rom
        return rom[a];
}

Byte VM::get_mem(Byte addr_low, Byte addr_high) {
    Address a = create_addr_from_bytes(addr_low, addr_high);
    return get_mem(a);
}

std::ostream& operator<<(std::ostream& os, VM& vm) {
    return os << vm.proc;
}
