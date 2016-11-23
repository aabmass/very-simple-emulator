#ifndef TYPES_H_
#define TYPES_H_

#include <cstdint>
#include <ostream>

using Byte = std::uint8_t;
using Address = std::uint16_t;

using PCReg = std::uint16_t;
using IRReg = std::uint8_t;
using OtherReg = std::uint8_t;

struct ProcessorComponents {
    /* special registers */
    PCReg pc;
    IRReg ir;

    /* general purpose registers */
    OtherReg a;
    OtherReg b;
    OtherReg x;
    OtherReg y;
};

std::ostream& operator<<(std::ostream& os, ProcessorComponents& pc);

// hard to explain why I need this...
enum class RegisterName {
    A, B, X, Y
};

enum class State {
    UNINITIALIZED,

    IRLD,
    DECODE,

    LD_IMD_A,
    LD_IMD_B,
    LD_IMD_X,
    LD_IMD_Y
};

template <typename Enumeration>
auto as_integer(Enumeration const value)
    -> typename std::underlying_type<Enumeration>::type
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}
std::ostream& operator<<(std::ostream& os, State& pc);

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


#endif /* ifndef TYPES_H_ */
