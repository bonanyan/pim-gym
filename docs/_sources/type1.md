# 01_Build _Fetch_

## Description
This step introduce instruction fetching function in ``core.v``. The core module is named as ``embarkrv`` in _"core.v"_.
A system-on-a-chip (SoC) is a module that includes both the ``embarkrv`` core and memories. _Instr Fetch_ only uses ROM.

The design is in ``embark-rv/src/01_fetch/rtl/``.Testbench is provided in ``embark-rv/src/01_fetch/test/``

## Run

First enter ``test`` folder:
```bash
cd embark-rv/src/01_fetch/test
```

To run simulation:
```bash
make
```

To plot the waveform:
```bash
make plot
```

To clean up (remove the generated files):
```bash
make clean
```

For code linting:
```bash
make soc
make core
```


## Files

```
01_fetch
├── rtl //design
│   ├── core.v //embark core design
│   ├── memory.v
│   └── soc.v //memory + embark core
└── test
    ├── makefile //top entry
    ├── program.hex //converted instruction memory content for loading in the initial stage
    ├── testCode.bin //random instruction memory content for testing
    ├── testCode.hex //random instruction memory content for testing in hexidecimal
    ├── testbench.v //verilog testbench
    ├── wave        //generated executable
    └── wave.vcd    //generated waveform file
```

## Useful Tools

Note that program.hex can be converted automatically by embark-rv/utilities/convertTestCode.py, to use it:
```bash
cd embark-rv/utilities/
python convertTestCode.py -i testCode.bin -o program.hex -ou testCode.hex
```
>> **require python package: argparse, random**, they are very common though.

if you only change the content without changing file names, you can directly use:
```bash
cd embark-rv/utilities/
python convertTestCode.py
```
the default file names are exactly: ``testCode.bin`` (input binary instruction), ``testCode.hex`` (output hexadecimal instruction), and ``program.hex`` (output hex file for Verilog to load into the memory using Verilog system function ``$readmemh()``, in _memory.v"_).

## Chapter Summary
After completing Step 01, you can load instructions from ROM. You now have a famous PC (program counter) in your hardware.

Easy, isn't it? Let's get to the next easier step--"instruction decode"!