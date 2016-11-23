#ifndef CPUCONTROLLER_HPP_8LJZV9M7
#define CPUCONTROLLER_HPP_8LJZV9M7

#include "types.hpp"

class VM;

class CPUController {
private:
    State s;
    VM& vm;

    // pure function, just because
    State get_next_state(State s, IRReg ir);

    OtherReg& reg_pertaining_to_state(State s);

public:
    CPUController(VM& vm);

    void execute_instr();
};

#endif /* end of include guard: CPUCONTROLLER_HPP_8LJZV9M7 */

