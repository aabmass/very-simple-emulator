#ifndef MAPPINGS_H_
#define MAPPINGS_H_

#include <map>
#include "types.hpp"

extern std::map<IRReg, State> ir_map;
extern std::map<State, RegisterName> reg_for_state;

#endif /* ifndef MAPPINGS_H_ */
