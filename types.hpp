#ifndef TYPES_HPP_X1G387PI
#define TYPES_HPP_X1G387PI

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
    LD_IMD_Y,

    LD_IMD_ADDR_A,
    LD_IMD_ADDR_B,
    LD_IMD_ADDR_X,
    LD_IMD_ADDR_Y,

    INA,
    INB,
    INX,
    INY,

    SUM_BA,

    BRK // the break pseudo instruction
};

/** this method gets the underlying value for an enum value */
template <typename Enumeration>
auto as_integer(Enumeration const value)
    -> typename std::underlying_type<Enumeration>::type
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

std::ostream& operator<<(std::ostream& os, State& s);

#endif /* end of include guard: TYPES_HPP_X1G387PI */
