#include "types.hpp"

std::ostream& operator<<(std::ostream& os, ProcessorComponents& pc) {
    return os << "(PC, IR, A, B, X, Y) = ("
              << (int) pc.pc << ", " << (int) pc.ir << ", " << (int) pc.a
              << ", " << (int) pc.b << ", " << (int) pc.x << ", " << (int) pc.y << ")";
}


std::ostream& operator<<(std::ostream& os, State& s) {
    std::string state_to_string[7];
    state_to_string[as_integer(State::IRLD)] = "IRLD";
    state_to_string[as_integer(State::LD_IMD_A)] = "LD_IMD_A";
    state_to_string[as_integer(State::LD_IMD_B)] = "LD_IMD_B";
    state_to_string[as_integer(State::LD_IMD_X)] = "LD_IMD_X";
    state_to_string[as_integer(State::LD_IMD_Y)] = "LD_IMD_Y";
    state_to_string[as_integer(State::UNINITIALIZED)] = "UNINITIALIZED";
    state_to_string[as_integer(State::DECODE)] = "DECODE";

    return os << state_to_string[as_integer(s)];
}
