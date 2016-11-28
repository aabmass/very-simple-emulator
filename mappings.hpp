#ifndef MAPPINGS_HPP_HDUR0N3L
#define MAPPINGS_HPP_HDUR0N3L

#include <unordered_map>
#include "util.hpp"
#include "types.hpp"

/* maps opconds in IR to State for the controller */
extern std::unordered_map<IRReg, State, EnumClassHash> ir_map;

/* maps the state onto the applicable register name */
extern std::unordered_map<State, RegisterName, EnumClassHash> reg_for_state;

#endif /* end of include guard: MAPPINGS_HPP_HDUR0N3L */
