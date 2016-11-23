very-simple-emulator
=============

This emulates a very simple instruction set and can execute a binary rom image
directly. Assembler to come.

Building
------
Make sure you have a C++ compiler and `cmake`. No other dependencies!

```sh
git clone https://github.com/aabmass/very-simple-emulator.git
cd very-simple-emulator
mkdir build
cd build
cmake ..
make

# creates main in build folder
```

Executing
------
To run the emulator, write a binary file `rom.bin` and pass its path to `main`.
Each opcode is a byte wide (the instruction register gets 8 bits). See the
sample rom.bin in a hex editor, or run `hexdump`.

So to run the sample program:
```sh
# from the source root with binary built in build directory
./build/main <path-to-rom>
```

Output
-------
Currently, `main()` just outputs the state of the registers after each
instruction gets executed. Here is the sample program output, to make sure
it ran right:

```
(PC, IR, A, B, X, Y) = (0, 0, 0, 0, 0, 0)
(PC, IR, A, B, X, Y) = (3, 5, 254, 0, 0, 0)
(PC, IR, A, B, X, Y) = (6, 8, 254, 0, 0, 9)
(PC, IR, A, B, X, Y) = (8, 2, 254, 1, 0, 9)
(PC, IR, A, B, X, Y) = (9, 32, 255, 1, 0, 9)
(PC, IR, A, B, X, Y) = (10, 33, 255, 2, 0, 9)
(PC, IR, A, B, X, Y) = (11, 34, 255, 2, 1, 9)
(PC, IR, A, B, X, Y) = (12, 35, 255, 2, 1, 10)
(PC, IR, A, B, X, Y) = (13, 48, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (14, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (15, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (16, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (17, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (18, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (19, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (20, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (21, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (22, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (23, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (24, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (25, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (26, 0, 1, 2, 1, 10)
(PC, IR, A, B, X, Y) = (27, 35, 1, 2, 1, 11)
(PC, IR, A, B, X, Y) = (28, 34, 1, 2, 2, 11)
(PC, IR, A, B, X, Y) = (29, 33, 1, 3, 2, 11)
(PC, IR, A, B, X, Y) = (30, 32, 2, 3, 2, 11)
(PC, IR, A, B, X, Y) = (31, 0, 2, 3, 2, 11)
(PC, IR, A, B, X, Y) = (32, 0, 2, 3, 2, 11)
(PC, IR, A, B, X, Y) = (33, 0, 2, 3, 2, 11)
(PC, IR, A, B, X, Y) = (34, 0, 2, 3, 2, 11)
(PC, IR, A, B, X, Y) = (35, 0, 2, 3, 2, 11)
(PC, IR, A, B, X, Y) = (36, 0, 2, 3, 2, 11)
(PC, IR, A, B, X, Y) = (37, 255, 2, 3, 2, 11)
```

These values are currently in decimal.
