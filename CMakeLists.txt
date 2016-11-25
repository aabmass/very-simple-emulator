cmake_minimum_required (VERSION 3.1)
project (verysimpleasm)

set (CMAKE_CXX_STANDARD 14)

# Sources and headers for to be used overal. Compile them into a library and
# then link any executables against that
set(SOURCES
    cpucontroller.cpp
    mappings.cpp
    token.cpp
    types.cpp
    util.cpp
    vm.cpp
)
set(HEADERS
    cpucontroller.hpp
    mappings.hpp
    token.hpp
    types.hpp
    util.hpp
    vm.hpp
)
add_library(very-simple-emu ${SOURCES} ${HEADERS})

# Now the executables that we will build, by name of cpp file
set(EXECUTABLES
    emu
    assembler
)

## if you want to link statically (e.g. for windows build), use:
## set(CMAKE_EXE_LINKER_FLAGS -static)

foreach(execsrc ${EXECUTABLES})
    add_executable(${execsrc} ${execsrc}.cpp)
    target_link_libraries(${execsrc} very-simple-emu)
endforeach(execsrc ${EXECUTABLES})

