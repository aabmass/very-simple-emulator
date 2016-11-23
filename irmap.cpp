#include "irmap.hpp"

std::map<IRReg, State> ir_map = {
    {0x00, State::LD_IMD_A},
    {0x01, State::LD_IMD_B},
    {0x02, State::LD_IMD_X},
    {0x03, State::LD_IMD_Y},
};

std::map<State, RegisterName> reg_for_state = {
    {State::LD_IMD_A, RegisterName::A},
    {State::LD_IMD_B, RegisterName::B},
    {State::LD_IMD_X, RegisterName::X},
    {State::LD_IMD_Y, RegisterName::Y},
};
