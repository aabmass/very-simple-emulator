#include "cpucontroller.hpp"
#include "vm.hpp"
#include "mappings.hpp"
#include "util.hpp"

#include <iostream>

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

void CPUController::execute_load_immediate() {
    // get the immediate value from from memory
    Byte immediate_data = vm.get_mem(vm.proc.pc);

    // put it into register of choice
    OtherReg& r = reg_pertaining_to_state(s);
    r = immediate_data;

    vm.pc_inc();
}

void CPUController::execute_load_immediate_address() {
    // get the value from the immediate two byte address
    Byte addr_low = vm.get_mem(vm.proc.pc);
    vm.pc_inc();
    Byte addr_high = vm.get_mem(vm.proc.pc);
    Byte mem = vm.get_mem(addr_low, addr_high);

    // put it into register of choice
    OtherReg& r = reg_pertaining_to_state(s);
    r = mem;

    vm.pc_inc();
}

void CPUController::execute_increment() {
    // put it into register of choice
    OtherReg& r = reg_pertaining_to_state(s);
    ++r;
}

void CPUController::execute_jmp() {
    Byte addr_low = vm.get_mem(vm.proc.pc);
    vm.pc_inc();
    Byte addr_high = vm.get_mem(vm.proc.pc);

    vm.proc.pc = create_addr_from_bytes(addr_low, addr_high);
}

void CPUController::execute_bne() {
    // read the mem first since we have to increment pc anyway
    Byte addr_low = vm.get_mem(vm.proc.pc);
    vm.pc_inc();
    Byte addr_high = vm.get_mem(vm.proc.pc);

    OtherReg& r = reg_pertaining_to_state(s);
    if (r != 0) {
        // only perform the jump (change pc) the register in question == 0
        vm.proc.pc = create_addr_from_bytes(addr_low, addr_high);
    }
}

void CPUController::execute_sum_ba() {
    vm.proc.a = vm.proc.a + vm.proc.b;
}

void CPUController::execute_stdout_imd_addr() {
    Byte addr_low = vm.get_mem(vm.proc.pc);
    vm.pc_inc();
    Byte addr_high = vm.get_mem(vm.proc.pc);

    /* load the data and print it */
    Byte data = vm.get_mem(addr_low, addr_high);

    // std::cout will treat it as a char (byte), as it. This is okay!
    std::cout << data;

    vm.pc_inc();
}

bool CPUController::execute_instr() {
    if (s == State::IRLD) {
        vm.proc.ir = vm.get_mem(vm.proc.pc);
        vm.pc_inc();
    }

    s = get_next_state(s, vm.proc.ir);
    if (s == State::NOOP) {
        // noop dammit!
    }
    else if (s == State::LD_IMD_A || s == State::LD_IMD_B ||
            s == State::LD_IMD_X || s == State::LD_IMD_Y) {

        execute_load_immediate();
    }
    else if (s == State::LD_IMD_ADDR_A || s == State::LD_IMD_ADDR_B ||
            s == State::LD_IMD_ADDR_X || s == State::LD_IMD_ADDR_Y) {

        execute_load_immediate_address();
    }
    else if (s == State::INA || s == State::INB ||
            s == State::INX  || s == State::INY ) {

        execute_increment();
    }
    else if (s == State::SUM_BA) execute_sum_ba();

    else if (s == State::JMP) execute_jmp();
    else if (s == State::BNE_X || s == State::BNE_Y) execute_bne();

    else if (s == State::STDOUT_IMD_ADDR) execute_stdout_imd_addr();
    else if (s == State::BRK) { // break pseudo instruction
        return false;
    }

    s = get_next_state(s, vm.proc.ir);
    return true;
}
