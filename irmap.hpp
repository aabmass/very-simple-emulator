#ifndef IR_MAP_
#define IR_MAP_

#include <map>
#include "types.hpp"

extern std::map<IRReg, State> ir_map;
extern std::map<State, RegisterName> reg_for_state;

#endif /* ifndef IR_MAP_ */
