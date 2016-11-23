#include <iostream>
#include <algorithm>
#include <vector>
#include "types.hpp"
#include "mappings.hpp"

class VM {
private:
    ProcessorComponents proc;
    Byte* rom;
    Byte* ram;
    CPUController controller;

public:
    VM(std::vector<Byte> const& rom_contents) :
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

    virtual ~VM() {
        delete[] rom;
        delete[] ram;
    }

    void execute_instr() {
        controller.execute_instr();
    }

    void pc_inc() {
        ++proc.pc;
    }

    OtherReg get_reg(RegisterName rn) {
        switch (rn) {
            case RegisterName::A: return proc.a;
            case RegisterName::B: return proc.b;
            case RegisterName::X: return proc.x;
            case RegisterName::Y: return proc.y;
        }
    }

    Byte get_mem(Address a) {
        /*
         * rom is mapped from 0x0000 to 0x7FFF, ram is mapped
         * from 0x8000 to 0xFFFF
         */
        if (a > 0x7FFF) // ram
            return ram[a - 0x8000];
        else            // rom
            return rom[a];
    }

    Byte get_mem(Byte addr_low, Byte addr_high) {
        // build the address from the low and high bytes.
        // Set equal to high byte, then shift it over by 8. Finally, or with
        // the low byte to get the full address
        Address a = addr_high;

        a <<= 8;
        
        // low byte
        a |= addr_low;

        return get_mem(a);
    }


    friend class CPUController;
    friend std::ostream& operator<<(std::ostream& os, VM& vm);
};

std::ostream& operator<<(std::ostream& os, VM& vm) {
    return os << vm.proc;
}

State CPUController::get_next_state(State s, IRReg ir) {
    if (s == State::IRLD)
        return ir_map[ir];
    else
        return State::IRLD;
}

OtherReg& CPUController::reg_pertaining_to_state(State s) {
    RegisterName rn = reg_for_state[s];
    switch (rn) {
        case RegisterName::A: return vm.proc.a;
        case RegisterName::B: return vm.proc.b;
        case RegisterName::X: return vm.proc.x;
        case RegisterName::Y: return vm.proc.y;
    }
}

CPUController::CPUController(VM& vm) :
    s(State::IRLD),
    vm(vm)
{}

void CPUController::execute_instr() {
    if (s == State::IRLD) {
        vm.proc.ir = vm.get_mem(vm.proc.pc);
        vm.pc_inc();
    }

    s = get_next_state(s, vm.proc.ir);
    while (s != State::IRLD) {
        if (s == State::LD_IMD_A || s == State::LD_IMD_B ||
                s == State::LD_IMD_X || s == State::LD_IMD_Y) {

            // get the immediate value from from memory
            Byte immediate_data = vm.get_mem(vm.proc.pc);

            // put it into register of choice
            OtherReg& r = reg_pertaining_to_state(s);
            r = immediate_data;

            vm.pc_inc();
        }

        s = get_next_state(s, vm.proc.ir);
    }
}



int main(int argc, char *argv[]) {
    std::vector<Byte> rom = {0x00, 0xAB, 0x02, 0xFF, 0x01, 0x01, 0x03, 0xE7};
    VM vm(rom);
    
    vm.execute_instr();
    vm.execute_instr();
    vm.execute_instr();
    vm.execute_instr();

    std::cout << vm << std::endl;
    
    return 0;
}
