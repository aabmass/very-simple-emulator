#include "mappings.hpp"

std::unordered_map<IRReg, State> ir_map = {
    /* noop */
    {0x00, State::NOOP},

    /* load immediate value instructions */
    {0x01, State::LD_IMD_A},
    {0x02, State::LD_IMD_B},
    {0x03, State::LD_IMD_X},
    {0x04, State::LD_IMD_Y},

    /* load from immediate address instructions */
    {0x05, State::LD_IMD_ADDR_A},
    {0x06, State::LD_IMD_ADDR_B},
    {0x07, State::LD_IMD_ADDR_X},
    {0x08, State::LD_IMD_ADDR_Y},

    /* increment instructions here */
    {0x20, State::INA},
    {0x21, State::INB},
    {0x22, State::INX},
    {0x23, State::INY},
    
    /* arithmetic instructions here. these opcodes may change */
    {0x30, State::SUM_BA},

    /* jmp/branch instructions here */
    {0x80, State::JMP},
    {0x81, State::BNE_X},
    {0x82, State::BNE_Y},

    /* special instructions here */
    // print to standard out the value in the immediate address
    {0xE0, State::STDOUT_IMD_ADDR},

    // this guy is a pseudo instruction. Just for exiting the program in this
    // emulator
    {0xFF, State::BRK}
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

    {State::INA, RegisterName::A},
    {State::INB, RegisterName::B},
    {State::INX, RegisterName::X},
    {State::INY, RegisterName::Y},

    {State::BNE_X, RegisterName::X},
    {State::BNE_Y, RegisterName::Y},
};
