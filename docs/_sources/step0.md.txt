# 00\_Build _Memory_

## Description
This step build memories, including *RAM* (random-access memory) and *ROM* (read-only memory to store all instructions/programs).

The design is in ``embark-rv/src/00_memory/rtl/``.Testbench is provided in ``embark-rv/src/00_memory/test/``

## Run

First enter ``test`` folder:
```bash
cd embark-rv/src/00_memory/test
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

## Files
```
00_memory
├── rtl
│   └── memory.v    //design
└── test
    ├── makefile    //top entry
    ├── plot.tcl    //loaded tcl script for loading waveforms, optional
    ├── testbench.v //verilog testbench
    ├── wave        //generated executable
    └── wave.vcd    //generated waveform file
```

## Chapter Summary
After completing Step 00, you have built a useful RAM and ROM for future use.