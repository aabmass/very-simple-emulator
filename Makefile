CXX = g++
CXXFLAGS := $(CFLAGS) -g -std=c++14

all: main.cpp irmap.o types.o
	$(CXX) $(CXXFLAGS) -o main main.cpp irmap.o types.o

irmap.o: irmap.cpp irmap.hpp
	$(CXX) $(CXXFLAGS) -c irmap.cpp

types.o: types.cpp types.hpp
	$(CXX) $(CXXFLAGS) -c types.cpp

.PHONY: clean

clean:
	rm -f *.o main
