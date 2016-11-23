#include "cpucontroller.hpp"
#include "vm.hpp"
#include "mappings.hpp"

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
