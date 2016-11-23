cmake_minimum_required (VERSION 3.1)
project (verysimpleasm)

set (CMAKE_CXX_STANDARD 14)

set(SOURCES
    cpucontroller.cpp
    main.cpp
    mappings.cpp
    types.cpp
    vm.cpp
    util.cpp
)

set(HEADERS
    cpucontroller.hpp
    mappings.hpp
    types.hpp
    vm.hpp
    util.hpp
)

# use below to link c++ std statically
# set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(main ${SOURCES} ${HEADERS})
