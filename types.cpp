#include "types.hpp"

std::ostream& operator<<(std::ostream& os, ProcessorComponents& pc) {
    return os << "(PC, IR, A, B, X, Y) = ("
              << (int) pc.pc << ", " << (int) pc.ir << ", " << (int) pc.a
              << ", " << (int) pc.b << ", " << (int) pc.x << ", " << (int) pc.y << ")";
}
