
![Static Badge](https://img.shields.io/badge/MIT-License-blue)
![Static Badge](https://img.shields.io/badge/Github-Repo-blue)
![Static Badge](https://img.shields.io/badge/SoC-Design-blue)

![PIM Gym](/sphinx_doc/source/_static/images/logo.webp)

**Collection of Baseline Designs for Memory-Centric Tensor Processing SoC**

Author: [Bonan Yan](http://bonany.cc) :) 

-----

## Quick Downloads in This Repo

|                    File                     | Version | URL                                                                                        |
| :-----------------------------------------: | :-----: | ------------------------------------------------------------------------------------------ |
| PIM macro behavioral model, Verilog version |   v2    | [\[download\]](https://github.com/bonanyan/pim-gym/raw/main/src/pim-verilog-bmodel.tar.gz) |
| PIM macro behavioral model, Chisel version  |   v2    | [\[download\]](https://github.com/bonanyan/pim-gym/raw/main/src/pim-chisel-bmodel.tar.gz)  |
|                 SoC, Type 1                 |   v1    | [\[download\]](https://github.com/bonanyan/pim-gym/raw/main/src/pim-chisel-bmodel.tar.gz)  |
|                 SoC, Type 2                 |   v1    | [\[download\]](https://github.com/bonanyan/pim-gym/raw/main/src/pim-chisel-bmodel.tar.gz)  |
|                 SoC, Type 3                 |   v1    | [\[download\]](https://github.com/bonanyan/pim-gym/raw/main/src/pim-chisel-bmodel.tar.gz)  |
|                 SoC, Type 4                 |   v1    | [\[download\]](https://github.com/bonanyan/pim-gym/raw/main/src/pim-chisel-bmodel.tar.gz)  |

SoC Categories:
- Type 1: 
- Type 2: 
- Type 3:
- Type 4: 
- 
-----

## :checkered_flag: PIM Macro Model, Verilog version

### Step 1: Untar the downloaded _pim-verilog-bmodel.tar.gz_ and enter the working folder (where the "makefile" lies)

```bash
tar xvzf pim-verilog-bmodel.tar.gz
cd pim-verilog-bmodel
```

Files:

```
pim-verilog-bmodel/
├── doc
│   ├── APIM_AddressMap.pdf  //address map of apim
│   └── DPIM_AddressMap.pdf  //address map of dpim
├── makefile  //top entry
├── readme.md //readme
└── src
    ├── APIM_tb.v //testbench for APIM.v
    ├── APIM.v //design (behavioral model) of APIM
    ├── DPIM_tb.v //testbench for DPIM.v
    ├── DPIM.v //design (behavioral model) of DPIM
    └── plt.tcl //gtkwave ploting configuration, used in "make plot"

```

### Step 2: Run
Choose one of the 4 following commend to run in shell:

(a) To test APIM.v:
```
make apim
```

(b) To test DPIM.v:
```
make dpim
```

(c) To plot the testing waveform:
```
make plot
```

(d) To cleanup:
```
make clean
```

**FAQs**:
It is common to revise the code of the behavioral model codes according to your own demands, please refer to [arvix:XXX](XXX) for detailed elaboration on the macro structure.

-----

## :checkered_flag: PIM Macro Model, Chisel version

### Behavioral model:
```
/src/main/scala/pislib/*
```

| File          | Content                               |
| - | - | 
| Memory.scala  | traditional memory behavioral model   |
| APIM.scala    | analog PIM macro behavioral model     |  
| DPIM.scala    | digital PIM macro behavioral model    |

### Chisel testbench:
```
/src/test/scala/pislib/*
```
To use:
### Step 1: Untar the downloaded _pim-chisel-bmodel.tar.gz_ and enter the working folder (where the "makefile" lies)

```bash
tar xvzf pim-chisel-bmodel.tar.gz
cd pim-chisel-bmodel
```

### Step 2: Select one of the following:

(a) Test normal memory:
```bash
make testMem
```
*Explain*: test conventional memory chisel behavioral model

(b) Test analog PIM:
```bash
make testAPIM 
```
*Explain*: test analog PIM macro chisel behavioral model

(c) Test digital PIM:
```bash
make testDPIM 
```
*Explain*: test digital PIM macro chisel behavioral model

#### Run environment setup:
Refer to [chisel local install]
- install *Java SDK* 
- install *sbt*
- Good to go run the main entry

-----

## :checkered_flag: Type 1 SoC: 

-----

## :checkered_flag: Type 2 SoC: 

-----

## :checkered_flag: Type 3 SoC: 

-----

## :checkered_flag: Type 4 SoC: 


---

## Citation
Please cite this work as: 

```
XXX, XXX, XXX
```

or use Bibtex:
```bibtex
@article{pimgym,
    author = {Yan, Bonan},
    journal = {arXiv preprint arXiv:2202.07646},
    title = {Quantifying memorization across neural language models},
    url = {https://arxiv.org/abs/2202.07646},
    year = {2022}
}
```