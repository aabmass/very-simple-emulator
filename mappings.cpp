#include "mappings.hpp"

std::unordered_map<IRReg, State> ir_map = {
    /* load immediate value instructions */
    {0x00, State::LD_IMD_A},
    {0x01, State::LD_IMD_B},
    {0x02, State::LD_IMD_X},
    {0x03, State::LD_IMD_Y},

    /* load from immediate address instructions */
    {0x04, State::LD_IMD_ADDR_A},
    {0x05, State::LD_IMD_ADDR_B},
    {0x06, State::LD_IMD_ADDR_X},
    {0x07, State::LD_IMD_ADDR_Y},
};

std::unordered_map<State, RegisterName> reg_for_state = {
    {State::LD_IMD_A, RegisterName::A},
    {State::LD_IMD_B, RegisterName::B},
    {State::LD_IMD_X, RegisterName::X},
    {State::LD_IMD_Y, RegisterName::Y},

    {State::LD_IMD_ADDR_A, RegisterName::A},
    {State::LD_IMD_ADDR_B, RegisterName::B},
    {State::LD_IMD_ADDR_X, RegisterName::X},
    {State::LD_IMD_ADDR_Y, RegisterName::Y},
};
