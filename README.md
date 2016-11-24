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
To run the emulator, write a binary file `smileys.bin` and pass its path to `main`.
Each opcode is a byte wide (the instruction register gets 8 bits). See the
samples in the sample directory, open them in a hex editor or run `hexdump`
etc.

So to run the sample smiley program:
```sh
# from the source root with binary built in build directory
./build/main sample-programs/smileys.bin
```

Output
-------
Currently, `main()` runs the program passed as its first arg and then prints
the state of the virtual machine's registers when it's "done". By done, I mean
the pseudo instruction (just for emulation) `BRK` (opcode `0xFF`) is
encountered. The sample program `smileys.bin` prints ten smiley's!

```
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)

Finished running program! End state of VM:
(PC, IR, A, B, X, Y) = (28, 255, 73, 11, 10, 0)
```

The values in the registers are in decimal. The outputted smiley's are bytes
that `std::cout` formats as ASCII.
