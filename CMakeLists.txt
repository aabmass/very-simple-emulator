cmake_minimum_required (VERSION 3.1)
project (verysimpleasm)

set (CMAKE_CXX_STANDARD 14)

# sources and headers for the emulator
set(SOURCES_EMU
    cpucontroller.cpp
    emu.cpp
    mappings.cpp
    types.cpp
    vm.cpp
    util.cpp
)
set(HEADERS_EMU
    cpucontroller.hpp
    mappings.hpp
    types.hpp
    vm.hpp
    util.hpp
)

# sources and headers for the assembler
set(SOURCES_ASM
    assembler.cpp
)
set(HEADERS_ASM
    
)

# use below to link c++ std statically
# set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(emu ${SOURCES_EMU} ${HEADERS_EMU})
add_executable(asm ${SOURCES_ASM} ${HEADERS_ASM})
