#ifndef CPUCONTROLLER_HPP_8LJZV9M7
#define CPUCONTROLLER_HPP_8LJZV9M7

#include "types.hpp"

class VM;

class CPUController {
private:
    State s;
    VM& vm;

    State get_next_state(State s, IRReg ir);
    OtherReg& reg_pertaining_to_state(State s);

    /* specific bits of code for executing types of instructions */
    void execute_load_immediate();
    void execute_load_immediate_address();

public:
    CPUController(VM& vm);

    void execute_instr();
};

#endif /* end of include guard: CPUCONTROLLER_HPP_8LJZV9M7 */

