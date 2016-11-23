#ifndef VM_HPP_1F2XTUBO
#define VM_HPP_1F2XTUBO

#include <vector>

#include "types.hpp"
#include "cpucontroller.hpp"

class VM {
private:
    ProcessorComponents proc;
    Byte* rom;
    Byte* ram;
    CPUController controller;

public:
    VM(std::vector<Byte> const& rom_contents);
    virtual ~VM();

    bool execute_instr();
    void pc_inc();

    OtherReg get_reg(RegisterName rn);
    Byte get_mem(Address a);
    Byte get_mem(Byte addr_low, Byte addr_high);

    friend class CPUController; // makes me feel dirty..
    friend std::ostream& operator<<(std::ostream& os, VM& vm);
};

std::ostream& operator<<(std::ostream& os, VM& vm);

#endif /* end of include guard: VM_HPP_1F2XTUBO */

